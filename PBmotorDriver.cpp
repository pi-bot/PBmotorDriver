#include "PBmotorDriver.h"
const unsigned char PBmotorDriver::_LMDIR = 8;
const unsigned char PBmotorDriver::_RMDIR = 7;
const unsigned char PBmotorDriver::_LMPWM = 9;
const unsigned char PBmotorDriver::_RMPWM = 10;

void PBmotorDriver::initPinsAndMaybeTimer()
{
  // Initialize the pin states used by the motor driver shield
  // It called before pinMode to handle the case where the board
  // is using an ATmega AVR to avoid ever driving the pin high, 
  // even for a short time.
  digitalWrite(_LMPWM, LOW);
  pinMode(_LMPWM, OUTPUT);
  digitalWrite(_RMPWM, LOW);
  pinMode(_RMPWM, OUTPUT);
  digitalWrite(_LMDIR, HIGH);
  pinMode(_LMDIR, OUTPUT);
  digitalWrite(_RMDIR, LOW);
  pinMode(_RMDIR, OUTPUT);

}

// power should be a number between -255 and 255
void PBmotorDriver::setLMpwr(int pwr)
{
  init(); // initialize if necessary
  boolean reverse = 1; // the left motor requires a reverse HIGH/LOW signal with respect to the right motor. 
  if (pwr < 0)
  {
    pwr = -pwr; // make power a positive quantity
    reverse = 0;    // preserve the direction
  }
  if (pwr > 255)  // max 
    pwr = 255;
    
  analogWrite(_LMPWM, pwr); // default to using analogWrite
  
  if (reverse==1) //
    digitalWrite(_LMDIR, HIGH);
  else
    digitalWrite(_LMDIR, LOW);
}

// power should be a number between -255 and 255
void PBmotorDriver::setRMpwr(int pwr)
{
  init(); // initialize if necessary
  boolean reverse = 0;
  if (pwr < 0)
  {
    pwr = -pwr;  // make speed a positive quantity
    reverse = 1;  // preserve the direction
  }
  if (pwr > 255)  // max PWM duty cycle
    pwr = 255;
    
   analogWrite(_RMPWM, pwr); // default to using analogWrite

  if (reverse==1) //
    digitalWrite(_RMDIR, HIGH);
  else
    digitalWrite(_RMDIR, LOW);
}

// set power for both motors
// power should be a number between -255 and 255
void PBmotorDriver::setPwrs(int LMpwr, int RMpwr){
  setLMpwr(LMpwr);
  setRMpwr(RMpwr);
}

// stop function for left motor
void PBmotorDriver::stopLM()
{
  setLMpwr(0);  
} 

// stop function for right motor
void PBmotorDriver::stopRM()
{
  setRMpwr(0);  
} 

// stop function for both motors
void PBmotorDriver::stopM()
{
  setPwrs(0,0);  
} 
