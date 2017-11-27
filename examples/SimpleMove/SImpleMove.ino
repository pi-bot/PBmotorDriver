#include <PBmotorDriver.h>

/*
 * This example uses the PBmotorDriver library to drive each motor forward, then backward first individually and then together. 
 * The LED is on when a motor is set to a positive speed and off when a motor is set to a negative speed.
 */

#define LED_PIN 13

PBmotorDriver motors;

void setup()
{
  pinMode(LED_PIN, OUTPUT);
  
}

void loop()
{
  // run LM forward : turns PiBot to the right
  
  digitalWrite(LED_PIN, HIGH);
  
    motors.setLMpwr(122);
    delay(500);
    motors.setLMpwr(255);
    delay(500);
    
   // run LM backward : turns PiBot to the left
    
    digitalWrite(LED_PIN, LOW);
    
    motors.setLMpwr(122);
    delay(500);
    motors.setLMpwr(255);
    delay(500);
 
   // run RM motor forward : turns PiBot to the left
  
  digitalWrite(LED_PIN, HIGH);
  
    motors.setLMpwr(122);
    delay(500);
    motors.setLMpwr(255);
    delay(500);
    
   // run RM backward : turns PiBot to the right
    
    digitalWrite(LED_PIN, LOW);
    
    motors.setLMpwr(122);
    delay(500);
    motors.setLMpwr(255);
    delay(500);
 
   // run both motors forward : moves PiBot forward 
  digitalWrite(LED_PIN, HIGH);
  
    motors.setPwrs(122, 122);
    delay(500);
    motors.setPwrs(255, 255);
    delay(500);
 
    // run both motors backward : moves PiBot backward 
  digitalWrite(LED_PIN, HIGH);
  
    motors.setPwrs(-122, -122);
    delay(500);
    motors.setPwrs(-255, -255);
    delay(500);
 
  delay(3000);   // wait 3 seconds before repeating the loop
}
