#pragma once

#include "SoundBuilder.h"

void Music_NewSound()
{
	SoundBuilder soundBuilder;

	soundBuilder.SetTempo(60);

	soundBuilder.AddNote(NOTE_C, 0, NOTETYPE_HALF);
	soundBuilder.AddNote(NOTE_D, 0, NOTETYPE_HALF);
	soundBuilder.AddNote(NOTE_E, 0, NOTETYPE_HALF);

	soundBuilder.BuildWavFile("test.wav");
}

void Music_MarioStarTheme()
{
	SoundBuilder soundBuilder;

	soundBuilder.SetTempo(75);

	//Row 1
	soundBuilder.AddNote(NOTE_F, 0, NOTETYPE_QUARTER);
	soundBuilder.AddNote(NOTE_F, 0, NOTETYPE_QUARTER);
	soundBuilder.AddNote(NOTE_F, 0, NOTETYPE_QUARTER);
	soundBuilder.AddNote(NOTE_D, 0, NOTETYPE_EIGHTH);
	soundBuilder.AddNote(NOTE_F, 0, NOTETYPE_EIGHTH);

	soundBuilder.AddNote(NOTE_NONE, 0, NOTETYPE_EIGHTH);
	soundBuilder.AddNote(NOTE_F, 0, NOTETYPE_QUARTER);
	soundBuilder.AddNote(NOTE_D, 0, NOTETYPE_EIGHTH);
	soundBuilder.AddNote(NOTE_F, 0, NOTETYPE_EIGHTH);
	soundBuilder.AddNote(NOTE_D, 0, NOTETYPE_EIGHTH);
	soundBuilder.AddNote(NOTE_F, 0, NOTETYPE_QUARTER);

	soundBuilder.AddNote(NOTE_E, 0, NOTETYPE_QUARTER);
	soundBuilder.AddNote(NOTE_E, 0, NOTETYPE_QUARTER);
	soundBuilder.AddNote(NOTE_E, 0, NOTETYPE_QUARTER);
	soundBuilder.AddNote(NOTE_C, 0, NOTETYPE_EIGHTH);
	soundBuilder.AddNote(NOTE_E, 0, NOTETYPE_EIGHTH);

	soundBuilder.AddNote(NOTE_NONE, 0, NOTETYPE_EIGHTH);
	soundBuilder.AddNote(NOTE_E, 0, NOTETYPE_QUARTER);
	soundBuilder.AddNote(NOTE_C, 0, NOTETYPE_EIGHTH);
	soundBuilder.AddNote(NOTE_E, 0, NOTETYPE_EIGHTH);
	soundBuilder.AddNote(NOTE_C, 0, NOTETYPE_EIGHTH);
	soundBuilder.AddNote(NOTE_E, 0, NOTETYPE_QUARTER);

	//Row 2
	soundBuilder.AddNote(NOTE_F, 0, NOTETYPE_QUARTER);
	soundBuilder.AddNote(NOTE_F, 0, NOTETYPE_QUARTER);
	soundBuilder.AddNote(NOTE_F, 0, NOTETYPE_QUARTER);
	soundBuilder.AddNote(NOTE_D, 0, NOTETYPE_EIGHTH);
	soundBuilder.AddNote(NOTE_F, 0, NOTETYPE_EIGHTH);

	soundBuilder.AddNote(NOTE_NONE, 0, NOTETYPE_EIGHTH);
	soundBuilder.AddNote(NOTE_F, 0, NOTETYPE_QUARTER);
	soundBuilder.AddNote(NOTE_D, 0, NOTETYPE_EIGHTH);
	soundBuilder.AddNote(NOTE_F, 0, NOTETYPE_EIGHTH);
	soundBuilder.AddNote(NOTE_D, 0, NOTETYPE_EIGHTH);
	soundBuilder.AddNote(NOTE_F, 0, NOTETYPE_QUARTER);

	soundBuilder.AddNote(NOTE_E, 0, NOTETYPE_QUARTER);
	soundBuilder.AddNote(NOTE_E, 0, NOTETYPE_QUARTER);
	soundBuilder.AddNote(NOTE_E, 0, NOTETYPE_QUARTER);
	soundBuilder.AddNote(NOTE_C, 0, NOTETYPE_EIGHTH);
	soundBuilder.AddNote(NOTE_E, 0, NOTETYPE_EIGHTH);

	soundBuilder.AddNote(NOTE_NONE, 0, NOTETYPE_EIGHTH);
	soundBuilder.AddNote(NOTE_E, 0, NOTETYPE_QUARTER);
	soundBuilder.AddNote(NOTE_C, 0, NOTETYPE_EIGHTH);
	soundBuilder.AddNote(NOTE_E, 0, NOTETYPE_EIGHTH);
	soundBuilder.AddNote(NOTE_C, 0, NOTETYPE_EIGHTH);
	soundBuilder.AddNote(NOTE_E, 0, NOTETYPE_QUARTER);

	//Row 3
	soundBuilder.AddNote(NOTE_F, 0, NOTETYPE_QUARTER);
	soundBuilder.AddNote(NOTE_F, 0, NOTETYPE_QUARTER);
	soundBuilder.AddNote(NOTE_F, 0, NOTETYPE_QUARTER);
	soundBuilder.AddNote(NOTE_D, 0, NOTETYPE_EIGHTH);
	soundBuilder.AddNote(NOTE_F, 0, NOTETYPE_EIGHTH);

	soundBuilder.BuildWavFile("StarTheme.wav");
}

void Music_MariosTheme()
{
	SoundBuilder soundBuilder;
    soundBuilder.SetTempo(60);
   
    //Row 1
    soundBuilder.AddNote(NOTE_D, 0, NOTETYPE_EIGHTH);
    soundBuilder.AddNote(NOTE_D, 0, NOTETYPE_EIGHTH);
    soundBuilder.AddNote(NOTE_NONE, 0, NOTETYPE_EIGHTH);

    soundBuilder.AddNote(NOTE_D, 0, NOTETYPE_EIGHTH);
    soundBuilder.AddNote(NOTE_NONE, 0, NOTETYPE_EIGHTH);

    soundBuilder.AddNote(NOTE_A_SHARP, 0, NOTETYPE_EIGHTH);
    soundBuilder.AddNote(NOTE_D, 0, NOTETYPE_EIGHTH);
    soundBuilder.AddNote(NOTE_NONE, 0, NOTETYPE_EIGHTH);

    soundBuilder.AddNote(NOTE_F, 0, NOTETYPE_EIGHTH);
    soundBuilder.AddNote(NOTE_NONE, 0, NOTETYPE_EIGHTH);
    soundBuilder.AddNote(NOTE_NONE, 0, NOTETYPE_QUARTER);

    soundBuilder.AddNote(NOTE_F, -1, NOTETYPE_EIGHTH);
    soundBuilder.AddNote(NOTE_NONE, 0, NOTETYPE_EIGHTH);
    soundBuilder.AddNote(NOTE_NONE, 0, NOTETYPE_QUARTER);

    soundBuilder.AddNote(NOTE_A_SHARP, 0, NOTETYPE_EIGHTH);
    soundBuilder.AddNote(NOTE_NONE, 0, NOTETYPE_EIGHTH);
    soundBuilder.AddNote(NOTE_NONE, 0, NOTETYPE_EIGHTH);
    soundBuilder.AddNote(NOTE_F, -1, NOTETYPE_EIGHTH);
    soundBuilder.AddNote(NOTE_NONE, 0, NOTETYPE_QUARTER);
    soundBuilder.AddNote(NOTE_D, -1, NOTETYPE_EIGHTH);
    soundBuilder.AddNote(NOTE_NONE, 0, NOTETYPE_EIGHTH);

    soundBuilder.AddNote(NOTE_NONE, 0, NOTETYPE_EIGHTH);
    soundBuilder.AddNote(NOTE_G, -1, NOTETYPE_EIGHTH);
    soundBuilder.AddNote(NOTE_NONE, 0, NOTETYPE_EIGHTH);
    soundBuilder.AddNote(NOTE_A, 0, NOTETYPE_EIGHTH);
    soundBuilder.AddNote(NOTE_NONE, 0, NOTETYPE_EIGHTH);

    soundBuilder.AddNote(NOTE_G_SHARP, -1, NOTETYPE_EIGHTH);
    soundBuilder.AddNote(NOTE_G, -1, NOTETYPE_EIGHTH);
    soundBuilder.AddNote(NOTE_NONE, 0, NOTETYPE_EIGHTH);
	//
	//soundBuilder.SetTempo(80);
	//soundBuilder.AddNote(NOTE_F, -1, NOTETYPE_QUARTER);
	//soundBuilder.AddNote(NOTE_D, 0, NOTETYPE_QUARTER);
	//soundBuilder.AddNote(NOTE_F, 0, NOTETYPE_QUARTER);
	//soundBuilder.SetTempo(60);
	//soundBuilder.AddNote(NOTE_G, 0, NOTETYPE_EIGHTH);

	//soundBuilder.AddNote(NOTE_NONE, 0, NOTETYPE_EIGHTH);
	//soundBuilder.AddNote(NOTE_E, 0, NOTETYPE_EIGHTH);
	//soundBuilder.AddNote(NOTE_F, 0, NOTETYPE_EIGHTH);
	////
	//soundBuilder.AddNote(NOTE_NONE, 0, NOTETYPE_EIGHTH);
	//soundBuilder.AddNote(NOTE_D, 0, NOTETYPE_EIGHTH);
	//soundBuilder.AddNote(NOTE_NONE, 0, NOTETYPE_EIGHTH);
	//soundBuilder.AddNote(NOTE_B, 0, NOTETYPE_EIGHTH);

	//soundBuilder.AddNote(NOTE_C, 0, NOTETYPE_EIGHTH);
	//soundBuilder.AddNote(NOTE_A, 0, NOTETYPE_EIGHTH);
	//soundBuilder.AddNote(NOTE_NONE, 0, NOTETYPE_QUARTER);


    soundBuilder.BuildWavFile("MariosTheme.wav");
}