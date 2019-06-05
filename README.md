# Fuzzy-DAC-Audio
Audio playback for Arduino SAMD21-based boards, with compression.

This library is a SAMD21 port of the Yusaino(https://github.com/hozuki/Yusaino) library, using the DAC function of the micro-controller. A simple audio amplifier such as LM386, PAM8302 is used.

Audio data is stored as a C++ array in the sketch (in the sounddata.h file), no external memory card/chip required. The default audio format is 8bit, 22050 Hz, monochrome.

The wav file compression is done according this great [Yusaino-Audio](https://github.com/hozuki/yusaino-audio) library. With around 50% compression ratio, approximately 15~20 seconds of sound track can be stored in the 256k flash memory, while leaving some ~50k of program space.

The playback is non-blocking, interrupt driven. Also refer to the [AudioZero](https://github.com/arduino-libraries/AudioZero/blob/master/src/AudioZero.cpp) for the playback code.