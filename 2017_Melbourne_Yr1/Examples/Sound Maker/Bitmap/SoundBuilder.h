#pragma once
#include <vector>

enum Note
{
	NOTE_NONE = -1,

	NOTE_A = 0,
	NOTE_A_SHARP,
	NOTE_B,
	NOTE_C,
	NOTE_C_SHARP,
	NOTE_D,
	NOTE_D_SHARP,
	NOTE_E,
	NOTE_F,
	NOTE_F_SHARP,
	NOTE_G,
	NOTE_G_SHARP,

	NOTE_COUNT
};

enum NoteType
{
	NOTETYPE_EIGHTH = 8,	//Quaver
	NOTETYPE_QUARTER = 4,	//Crotchet
	NOTETYPE_HALF = 2,		//Minim
	NOTETYPE_FULL = 1		//Semibreve
};

struct WAV_HEADER
{
	//RIFF Chunk Descriptor
	char riffHeader[4];		//Must contain the text "RIFF".
	int chunkSize;			//The size of the whole .wav file excluding this and the previous one variable.
	char wavHeader[4];		//Must contain the text "WAVE".

	//"fmt" Sub-chunk
	char fmtHeader[4];		//Must contain the text "fmt " (including the trailing space).
	int fmtChunkSize;		//The size of the sub-chunk, excluding this and the previous one variable.
	short audioFormat;		//Audio format. 1 for PCM.
	short channels;			//Number of channels (1 for mono, 2 for stereo, etc).
	int sampleRateHz;		//Samples per second (Hz).
	int byteRate;			//Bytes per second: (SampleRate * Channels * BitsPerSample) / 8.
	short blockAlign;		//Size of each sample multipled by number of channels (Channels * BitsPerSample) / 8.
	short bitsPerSample;	//Audio quality. Number of bits per sample (use a multiple of 8).

	//"data" Sub-chunk
	char dataHeader[4];		//Must contain the text "data".
	int dataChunkSize;		//Size of the audio data. (TotalSamples * Channels * BitsPerSample) / 8;
};

struct NoteData
{
	int m_nFrequency;
	int m_nAmplitude;
	float m_fDuration;
};

class SoundBuilder
{
public:
	SoundBuilder();
	~SoundBuilder();

	//Reset the system, ready for a new file.
	void Reset();

	//Set the tempo of the notes
	void SetTempo(int nQuarterNotesPerMinute = 60);

	//Add a single note from the chromatic scale by specifying the note, octave and note length
	//eNote - Which note in the chromatic scale to use.
	//nOctave - Octaves above 440 Hz. Zero is a pleasant tone, both positive and negative numbers can be entered.
	//eNoteType - How long is the note? Quarter? full? half? etc.
	void AddNote(Note eNote, int nOctave, NoteType eNoteType);

	//Add sound of the specied type for a specfic duration.
	//eNote - Which note in the chromatic scale to use.
	//nOctave - Octaves above 440 Hz. Zero is a pleasant tone, both positive and negative numbers can be entered.
	//fDuration - Duration of the sound in seconds.
	void AddSound(Note eNote, int nOctave, float fDuration, int nVolume = 8000);

	//Add silence to the sound file.
	void AddSilence(float fDuration);

	//Create the wave file and write it to disk
	//szFilename - The name of the file to save. e.g. "example.wav"
	void BuildWavFile(char* szFilename);

private:
	int GetFrequency(Note eNote, int Octave);
	float FadeNote(int nCurrentSample, int nTotalSamples);

	std::vector<NoteData*> m_NoteArray;
	float m_fTotalDutation;

	double m_dSampleRateHz;
	float m_fTempo;
};

