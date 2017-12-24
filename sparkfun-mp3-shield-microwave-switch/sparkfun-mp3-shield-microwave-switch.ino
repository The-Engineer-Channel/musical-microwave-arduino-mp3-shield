// Name: Microwave Music Player (Christmas Carols)
// Author: Joseph Coombe (The Engineer)
// Email: theengineerchannel@gmail.com
// Date: 12/21/2017
// Attributions:
//  https://learn.sparkfun.com/tutorials/mp3-player-shield-hookup-guide-v15
//  https://www.arduino.cc/en/Tutorial/Debounce
//  https://playground.arduino.cc/Code/TimingRollover
//  https://www.arduino.cc/reference/en/language/functions/time/millis/
//  https://www.computerhope.com/jargon/num/8-3-format.htm
//  https://arduino.stackexchange.com/a/13443
//  Mom & Dad
//  George Washington

#include <SFEMP3Shield.h>
#include <SFEMP3ShieldConfig.h>
#include <SFEMP3Shieldmainpage.h>

#include <ArduinoStream.h>
#include <bufstream.h>
#include <ios.h>
#include <iostream.h>
#include <istream.h>
#include <MinimumSerial.h>
#include <ostream.h>
#include <Sd2Card.h>
#include <SdBaseFile.h>
#include <SdFat.h>
#include <SdFatConfig.h>
#include <SdFatmainpage.h>
#include <SdFatStructs.h>
#include <SdFatUtil.h>
#include <SdFile.h>
#include <SdInfo.h>
#include <SdSpi.h>
#include <SdStream.h>
#include <SdVolume.h>

// PIN NUMBERS
const int switchPin = 10;     // Pin contact switch is connected to

// GLOBAL VARIABLES
int switchState;              // HIGH = microwave door CLOSED, LOW = microwave door OPEN
int prevSwitchState = HIGH;    
bool microwaveOn = false;     // false = microwave not in use, high = microwave in use
bool prevMicrowaveOn = false;
int microwaveOpenCloseCnt = 0;

unsigned long lastDebounceTime = 0;  // last time switch was toggled
unsigned long debounceDelay = 500;   // the debounce time in ms

// MP3 SHIELD
SdFat sd;                     // Create object to handle SD functions
SFEMP3Shield MP3player;       // Create Mp3 library object
const uint8_t volume = 0;     // MP3 Player volume 0=max, 255=lowest (off)
const uint16_t monoMode = 1;  // Mono setting 0=off, 3=max

// SONG NAMES
//  note: these must be in 8.3 format, e.g.
//        char* mp3SongNames[] = {"rudolph.mp3", "1stnoel.mp3", "12daysof.mp3"};
char * mp3SongNames[] = 
  {
    "rudolph.mp3",  // TODO: Replace with your *.mp3 file names
    "1stnoel.mp3",
    "12daysof.mp3"
  };
int songCnt = sizeof(mp3SongNames)/sizeof(char*);    // total number of songs
int songIndex = 0;  // index of next song to play

void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(115200); // intitialize arduinio USB serial connection
  Serial.println("Starting USB Serial at 115200 baud");
  Serial.println("Adjust your serial monitor's settings accordingly");
  Serial.println("Remember to set the serial monitor to 'Newline'");
  Serial.println();
  Serial.print("The MicroSD card should contain ");
  Serial.print(songCnt);
  Serial.println(" songs:");
  for (int i=0; i < songCnt; i++)
  {
    Serial.print("  ");
    Serial.println(mp3SongNames[i]);
  }
  Serial.println();
  
  pinMode(switchPin, INPUT_PULLUP); // Set contact switch pin's mode to Input Pullup
  initSD();                         // Initialize the SD card
  initMP3Player();                  // Initialize the MP3 Shield

  Serial.println("LOG:");
}

void loop() {
  // put your main code here, to run repeatedly:
  
  int switchReading = digitalRead(switchPin);  // Check switchPin's value and store in a local variable.

  if (switchReading != prevSwitchState) 
  {
    lastDebounceTime = millis();  // Reset debouncing timer.
  }

  if ((millis() - lastDebounceTime) > debounceDelay) 
  {
    if(switchReading != switchState)  // Microwave door was either opened or closed
    {
      switchState = switchReading;
      // Update microwave state
      if (switchState == LOW)  // Microwave door opens.
      {
        microwaveOn = false;
      } 
      else  // microwave door closes.
      {
        microwaveOpenCloseCnt++;
        if (microwaveOpenCloseCnt % 2 == 1)  // I'm assuming that the microwave turns on every other time the door closes
        {                                    // (e.g. open door, put in food, close door, cook, open door, take out food, close door)
          microwaveOn = true;                
        }
      }
    }
  }

  if (microwaveOn != prevMicrowaveOn)  // Do something if the microwave door was opened/closed.
  {
    if (microwaveOn)
    {
      Serial.println("TURN MUSIC ON");
      Serial.print("  Playing "); 
      Serial.println(mp3SongNames[songIndex]);
      int result = MP3player.playMP3(mp3SongNames[songIndex]);
      songIndex = songIndex + 1;  // or songIndex++;
      songIndex = songIndex % songCnt;
      if (result == 0)  // playTrack() returns 0 on success
      {
        // Success
      }
      else // Otherwise there's an error, check the code
      {
        Serial.print("MP3player.playMP3(songName) error: ");
        Serial.println(result);
      }
    }
    else
    {
      Serial.println("TURN MUSIC OFF");
      if (MP3player.isPlaying())
      {
        MP3player.stopTrack();
      }
    }
  }

  prevSwitchState = switchReading;
  prevMicrowaveOn = microwaveOn;
}


// initSD() initializes the SD card and checks for errors.
void initSD()
{
  //Initialize the SdCard.
  if(!sd.begin(SD_SEL, SPI_FULL_SPEED)) 
    sd.initErrorHalt();
  if(!sd.chdir("/")) 
    sd.errorHalt("sd.chdir");
}


// initMP3Player() sets up all of the initialization for the
// MP3 Player Shield. It runs the begin() function, checks
// for errors, applies a patch if found, and sets the volume/
// stero mode.
void initMP3Player()
{
  uint8_t result = MP3player.begin(); // init the mp3 player shield
  if(result != 0) // check result, see readme for error codes.
  {
    Serial.print("MP3player.begin() error: ");
    Serial.println(result);
  }
  MP3player.setVolume(volume, volume);
  MP3player.setMonoMode(monoMode);
}
