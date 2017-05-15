#include "SoundBuilder.h"
#include <fstream>

#define TWO_PI 6.283185307179586476925286766559

//------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------
SoundBuilder::SoundBuilder()
{
	m_dSampleRateHz = 44100;
	m_fTempo = 1.0f;
	m_fTotalDutation = 0.0f;
}

//------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------
SoundBuilder::~SoundBuilder()
{
	Reset();
}

//------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------
void SoundBuilder::Reset()
{
	for(auto i = m_NoteArray.begin(); i != m_NoteArray.end();)
	{
		delete *i;
		i = m_NoteArray.erase(i);
	}

	m_fTotalDutation = 0.0f;
}

//------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------
void SoundBuilder::AddSound(Note eNote, int nOctave, float fDuration, int nVolume)
{
	NoteData* pNote = new NoteData();
	pNote->m_nFrequency = GetFrequency(eNote, nOctave);
	pNote->m_nAmplitude = nVolume;
	pNote->m_fDuration = fDuration;

	m_fTotalDutation += fDuration;

	m_NoteArray.push_back(pNote);
}

//------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------
void SoundBuilder::AddNote(Note eNote, int nOctave, NoteType eNoteType)
{
	float fTotalDuration = m_fTempo / eNoteType;
	float fNoteDuration = fTotalDuration * 0.9f;
	float fSilenceDuration = fTotalDuration - fNoteDuration;
	AddSound(eNote, nOctave, fNoteDuration);
	AddSilence(fSilenceDuration);
}

//------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------
void SoundBuilder::AddSilence(float fDuration)
{
	AddSound(NOTE_NONE, 0, fDuration, 0);
}

//------------------------------------------------------------------------------------
// Used to fade each note in and out quickly to avoid pops at the start and end of each note.
//------------------------------------------------------------------------------------
float SoundBuilder::FadeNote(int nCurrentSample, int nTotalSamples)
{
	//Number of samples to fade over
	int nFadeSamples = 100;

	float fFadeStep = 1.0f / nFadeSamples;
	float fFade = 0.0f;

	if(nCurrentSample > (nTotalSamples - nFadeSamples))
	{
		//Fade out
		fFade = (float)(nTotalSamples - nCurrentSample) * fFadeStep;
		if(fFade < 0.0f)
			fFade = 0.0f;
	}
	else
	{
		//Fade in
		fFade = (float)nCurrentSample * fFadeStep;
		if(fFade > 1.0f)
			fFade = 1.0f;
	}

	return fFade;
}

//------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------
void SoundBuilder::BuildWavFile(char* szFilename)
{
	int nTotalSamples = (int)(m_dSampleRateHz * m_fTotalDutation);

	//Create the header
	WAV_HEADER header;
	memcpy_s(header.riffHeader, 4, "RIFF", 4);
	header.chunkSize = (sizeof(WAV_HEADER) - 8) + ((nTotalSamples * header.channels * header.bitsPerSample) / 8);
	memcpy_s(header.wavHeader, 4, "WAVE", 4);
	
	//"fmt" sub-chunk
	memcpy_s(header.fmtHeader, 4, "fmt ", 4);
	header.fmtChunkSize = 16;
	header.audioFormat = 1;
	header.channels = 2;
	header.sampleRateHz = (int)m_dSampleRateHz;
	header.bitsPerSample = 16;
	header.byteRate = (header.sampleRateHz * header.channels * header.bitsPerSample) / 8;
	header.blockAlign = (header.channels * header.bitsPerSample) / 8;
	
	//"data" sub-chunk
	memcpy_s(header.dataHeader, 4, "data", 4);
	header.dataChunkSize = (nTotalSamples * header.channels * header.bitsPerSample) / 8;

	//Open the file for writing
	std::ofstream file(szFilename, std::ios::out | std::ios::binary);
	if (file.good())
	{
		//write the header
		file.write((char*)&header, sizeof(WAV_HEADER));

		//Iterate the list of notes and write each one to the file.
		for (auto i = m_NoteArray.begin(); i != m_NoteArray.end(); i++)
		{
			NoteData* pNote = *i;

			//Iterating through each sample that makes up the note.
			int nSampleCount = (int)(pNote->m_fDuration * m_dSampleRateHz);
			for (int n = 0; n < nSampleCount; n++)
			{
				float fFade = FadeNote(n, nSampleCount);
				
				short leftChannel = 0;
				short rightChannel = 0;
				if(pNote->m_nFrequency > 0.0f)
				{
					//Calculate the frequency of each sample over time (standing wave)
					double dSampleFreq = sin((TWO_PI * n * pNote->m_nFrequency) / m_dSampleRateHz);
					int nAmplitude = (int)(pNote->m_nAmplitude * fFade);

					//The final note is the sample frequency multiplied by the amplitude (volume) of the note.
					//Here we're setting left and right channel to be the same, so effectively mono sound, but these could be set differently for stereo.
					leftChannel = (short)(nAmplitude * dSampleFreq);
					rightChannel = (short)(nAmplitude * dSampleFreq);
				}

				//Write to file.
				file.write((char*)&leftChannel, sizeof(short));
				file.write((char*)&rightChannel, sizeof(short));
			}
		}

		file.close();
	}
}

//------------------------------------------------------------------------------------
// Convert note and octave to a frequency using A4 (440Hz) as the baseline.
//------------------------------------------------------------------------------------
int SoundBuilder::GetFrequency(Note eNote, int Octave)
{
	if(eNote == NOTE_NONE)
		return 0;

	//Work out how many semitones the requested note is above A4.
	int semitone = (Octave * NOTE_COUNT) + eNote;

	//Size of a semitone. Magic number corresponding to the 12th root of 2.
	const double a = 1.059463094359; 

	//Calculate the new frequency.
	double freq = 440 * pow(a, semitone);

	return (int)freq;
}

//------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------
void SoundBuilder::SetTempo(int nQuarterNotesPerMinute)
{
	if(nQuarterNotesPerMinute > 0)
		m_fTempo = 60.0f / (float)nQuarterNotesPerMinute;
	else 
		m_fTempo = 1.0f;
}