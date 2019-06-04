/*
    Name:       Audio_Playback.ino
    Created:	2019/6/4 02:23:13
    Author:     MSI_GS70\georgychen
*/

#include "Fuzzy_DAC_Audio.h"
#include "sounddata.h"

FuzzyDACAudio audio;

void setup()
{
	Serial.begin(115200);
	while (!Serial);
	Serial.println("Audio playback example started.");
	Serial.println("Audio data is stored in the sounddata.h file. Refer to the comments there.");
	Serial.println("Input 0-9 in this serial window to play the audio files.");
	audio.begin();
}

void loop()
{
	if (Serial.available() > 0)
	{
		char readByte = Serial.read();
		Serial.print(readByte,DEC);
		if (readByte > 47 && readByte < 58)
		{
			//when the input char is between 0 and 9
			uint8_t num = (uint8_t)readByte - 48;
			play(num);
		}	
	}
}

void play(uint8_t trackNumber)
{
	switch (trackNumber)
	{
	case 0:
	{
		audio.playHuffArray(HuffDict_Yawing, SoundDataBits_Yawing, SoundData_Yawing);
		break;
	}
	case 1:
	{
		audio.playHuffArray(HuffDict_short_1, SoundDataBits_short_1, SoundData_short_1);
		break;
	}
	case 2:
	{
		audio.playHuffArray(HuffDict_short_2, SoundDataBits_short_2, SoundData_short_2);
		break;
	}
	case 3:
	{
		audio.playHuffArray(HuffDict_short_3, SoundDataBits_short_3, SoundData_short_3);
		break;
	}
	case 4:
	{
		audio.playHuffArray(HuffDict_short_4, SoundDataBits_short_4, SoundData_short_4);
		break;
	}
	case 5:
	{
		audio.playHuffArray(HuffDict_short_5, SoundDataBits_short_5, SoundData_short_5);
		break;
	}
	case 6:
	{
		audio.playHuffArray(HuffDict_short_6, SoundDataBits_short_6, SoundData_short_6);
		break;
	}
	case 7:
	{
		audio.playHuffArray(HuffDict_medium_1, SoundDataBits_medium_1, SoundData_medium_1);
		break;
	}
	case 8:
	{
		audio.playHuffArray(HuffDict_medium_2, SoundDataBits_medium_2, SoundData_medium_2);
		break;
	}
	case 9:
	{
		audio.playHuffArray(HuffDict_medium_3, SoundDataBits_medium_3, SoundData_medium_3);
		break;
	}
	case 24:
	{
		//audio.playHuffArray(HuffDict_medium_4, SoundDataBits_medium_4, SoundData_medium_4);
		break;
	}
	case 10:
	{
		audio.playHuffArray(HuffDict_long_1, SoundDataBits_long_1, SoundData_long_1);
		break;
	}
	case 32:
	{
		//audio.playHuffArray(HuffDict_long_2, SoundDataBits_long_2, SoundData_long_2);
		break;
	}

	default:
	{
		break;
	}
	}
}
