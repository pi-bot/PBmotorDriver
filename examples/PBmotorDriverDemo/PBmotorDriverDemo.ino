#include <PBmotorDriver.h>

/*
 * This example uses the PBmotorDriver library to drive each motor forward, then backward. 
 * The LED is on when a motor is set to a positive speed and off when
 * a motor is set to a negative speed.
 */

#define LED_PIN 13

PBmotorDriver motors;

void setup()
{
  pinMode(LED_PIN, OUTPUT);
  
}

void loop()
{
  // run LM motor with positive power
  
  digitalWrite(LED_PIN, HIGH);
  
  for (int pwr = 0; pwr <= 255; pwr++)
  {
    motors.setLMpwr(pwr);
    delay(5);
  }

  for (int speed = 255; pwr >= 0; pwr--)
  {
    motors.setLMpwr(pwr);
    delay(5);
  }
  
  // run LM motor with negative power
  
  digitalWrite(LED_PIN, LOW);
  
  for (int pwr = 0; pwr >= -255; pwr--)
  {
    motors.setLMpwr(pwr);
    delay(5);
  }
  
  for (int pwr = -255; pwr <= 0; pwr++)
  {
    motors.setLMpwr(pwr);
    delay(5);
  }



  // run RM motor with positive power
  
  digitalWrite(LED_PIN, HIGH);
  
  for (int pwr = 0; pwr <= 255; pwr++)
  {
    motors.setRMpwr(pwr);
    delay(5);
  }

  for (int speed = 255; pwr >= 0; pwr--)
  {
    motors.setRMpwr(pwr);
    delay(5);
  }
  
  // run RM motor with negative power
  
  digitalWrite(LED_PIN, LOW);
  
  for (int pwr = 0; pwr >= -255; pwr--)
  {
    motors.setRMpwr(pwr);
    delay(5);
  }
  
  for (int pwr = -255; pwr <= 0; pwr++)
  {
    motors.setLMpwr(pwr);
    delay(5);
  }

  
  delay(500);
}
