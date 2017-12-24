# sparkfun-mp3-shield-microwave-switch
_In 2017, your microwave plays music while you reheat french fries..._

## Table of Contents
* [Summary](#summary)
* [Requirements](#requirements)
* [Installation](#installation)
  * [Preparation](#preparation)
  * [Download Repo](#download-repo-and-extract)
  * [Open Sketch](#open-sketch-in-arduino-ide)
  * [Edit Sketch](#edit-sketch-and-add-song-names)
  * [Upload Sketch](#verify-and-upload-sketch)
* [Support](#support)
* [Resources](#resources)

## Summary
This repository contains an Arduino sketch for
the musical microwave project. Check it out on
[YouTube](link to YouTube) and
[Instructables](link to Instructables) for a demonstration and detailed instructions.

## Requirements
* Hardware
  * [Arduino UNO](https://store.arduino.cc/usa/arduino-uno-rev3)
  * [SparkFun MP3 Player Shield](https://www.sparkfun.com/products/12660)
  * [Arduino Stackable Header Kit - R3](https://www.sparkfun.com/products/11417)
  * [3.5mm Male-to-Male Stereo Audio AUX Cable](http://a.co/3FVRnBt)
  * [Speaker with AUX Input](http://a.co/00E7tHy)
  * [Male-to-Female Jumper Wires](https://www.sparkfun.com/products/12794)
  * [3-Pin SPDT Micro Switch](http://a.co/1Jljt22)
  * [Micro SD](http://a.co/2HIo4hr)   
     * [formatted to FAT32](https://gopro.com/help/articles/Solutions_Troubleshooting/SD-Card-Reformat-on-a-Windows-Computer)
     * containing *.mp3 song files
       * [up to 320 kbps bitrate](https://www.sparkfun.com/datasheets/Components/SMD/vs1053.pdf)
       * [and 48 kHz sample rate](https://www.sparkfun.com/datasheets/Components/SMD/vs1053.pdf)
       * [with 8.3 file names](https://www.computerhope.com/jargon/num/8-3-format.htm)  


* Software  
  * [Arduino IDE](https://www.arduino.cc/en/Main/Software) (1.0.0 or greater)
  * [Sparkfun-MP3-Player-Shield-Arduino-Library](https://github.com/mpflaga/Sparkfun-MP3-Player-Shield-Arduino-Library)
    * [SFEMP3Shield](https://github.com/mpflaga/Sparkfun-MP3-Player-Shield-Arduino-Library/tree/master/SFEMP3Shield)
    * [SdFat](https://github.com/mpflaga/Sparkfun-MP3-Player-Shield-Arduino-Library/tree/master/SdFat)


* Tools
  * Computer
  * [USB 2.0 Cable Type A/B](https://store.arduino.cc/usa/usb-2-0-cable-type-a-b)

## Installation

### Preparation
1. Connect Arduino UNO to computer using a USB 2.0 Cable Type A/B.

### Download Repo and Extract
1. Download this repository:  
  i. Left-click `Clone or download`.  
  ii. Left-click `Download ZIP`.
3. Unzip the downloaded file.

### Open Sketch in Arduino IDE
1. Navigate to the `~\musical-microwave-arduino-mp3-shield\sparkfun-mp3-shield-microwave-switch` directory.
2. Open `sparkfun-mp3-shield-microwave-switch.ino` in the Arduino IDE.
3. Make sure the appropriate Board and Port are selected:  
  i. `Tools` > `Board` > `Arduino/Genuino Uno`  
  ii `Tools` > `Port` > `COM# (Arduino/Genuino Uno)`

### Edit Sketch and Add Song Names
1. Replace this section of the code with the *.mp3 filenames on
your Micro SD.  

  ![edit code](images/arduino-ide-add-song-names.png)

### Verify and Upload Sketch
1. Verify the sketch.  

  ![verify](images/arduino-ide-verify.png)

2. Upload the sketch to the Arduino UNO.   

  ![upload](images/arduino-ide-upload.png)

  If the sketch fails to upload...
  * Make sure the Arduino is connected.
  * Check that the `Board` and `Port` settings are correct.
  * Google the problem.

## Support
* If you run into an issue with the sketch, feel free to [create an issue](https://help.github.com/articles/creating-an-issue/) in this repository.
* If you would like to improve this sketch (or perhaps share a similar sketch for others to use), feel free to [fork this repository and submit a pull request](https://gist.github.com/Chaser324/ce0505fbed06b947d962) with your changes.

I'll do my best to respond to issues and pull requests!

## Resources
### Arduino
* [Arduino Official Website](https://www.arduino.cc/en/Guide/HomePage)
  * [Download the Arduino IDE](https://www.arduino.cc/en/Main/Software)
  * [Getting Started with Arduino and Genuino UNO](https://www.arduino.cc/en/Guide/ArduinoUno)
  * [Installing Additional Arduino Libraries](https://www.arduino.cc/en/Guide/Libraries)
* [Arduino SFEMP3Shield Library](https://github.com/mpflaga/Sparkfun-MP3-Player-Shield-Arduino-Library)
  * [Documetation](http://mpflaga.github.io/Sparkfun-MP3-Player-Shield-Arduino-Library/)
* [MP3 Player Shield Hookup Guide V15](https://learn.sparkfun.com/tutorials/mp3-player-shield-hookup-guide-v15)

### GitHub
* [What is GitHub, and What Is It Used For?](https://www.howtogeek.com/180167/htg-explains-what-is-github-and-what-do-geeks-use-it-for/)
* [Mastering Markdown](https://guides.github.com/features/mastering-markdown/) _(This README was written using Markdown syntax)_

### Git
* [1.3 Geting Started - Git Basics](https://git-scm.com/book/en/v2/Getting-Started-Git-Basics)
* [Git Beginner's Guide for Dummies](https://backlog.com/git-tutorial/en/)
