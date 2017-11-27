# PBmotorDriver
Library for driving the PiBots DC motors

Version: 0.1 <br>
Release date: 2017-11-27 <br>

## Getting started
There is a script that automatically loads this library into the PiBots Arduino IDE. (See the config directory of the Pioneers repo for more details.) 


## Example program
An example sketch is available that shows how to use the library.  You
can access it from the Arduino IDE by opening the "File" menu,
selecting "Examples", and then selecting "PBmotorDriver".  If
you cannot find these examples, the library was probably installed
incorrectly and you should retry the installation instructions above.

### Demo
The demo ramps motor 1 from stopped to full speed forward, ramps down
to full speed reverse, and back to stopped. Then, it does the same
with the other motor.

## Documentation
- `void setLMpwr(int pwr)` <br> Set the power factor and direction for
  motor 1. Power factor should be between -255 and 255. The motors brake at 0. 
- `void setRMpwr(int pwr)` <br> Set the power factor and direction for the right motor.
Power factor should be between -255 and 255. The motors brake at 0. 
- `void setPwrs(int LMpwr, int RMpwr)` <br> Set power and
  direction for both motors.

**N.B.** The voltage supplied to the motors are directly from the battery when a micro-usb power supply is disconnected. This means that the power and subsequent speeds of the motors will depend on the batteries charge level.

## Version history
* 0.1 (2017-11-27): Original release.


### Manual Install

If this does not work, you can manually install the library:

1. Download the
   [latest release archive from GitHub](https://github.com/pi-bot/PBmotorDriver/releases)
   and decompress it.
2. Drag the "PBmotorDriver" folder into the "libraries" directory inside your Pioneers 
   Arduino sketchbook directory. You can view your sketchbook location by
   opening the "File" menu and selecting "Preferences" in the Arduino IDE. If
   there is not already a "libraries" folder in that location, you should make
   the folder yourself.
4. After installing the library, restart the Arduino IDE.
