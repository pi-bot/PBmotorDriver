/**
 * PiBot Motor Control Demo
 * Demonstration without using a library
 * 
 * Description:
 *  Run the sketch and open a serial
 *  monitor. Give 
 * 
 * Hardware Connections:
 *  PiBot | Motor Driveer 
 *  -------------------
 *    8    |   LM-dir     
 *    7    |   RM-dir    
 *    9    |   LM-power     
 *    10   |   RM-power 
 *  
 */

// Pins
const int LMDIR = 8;
const int RMDIR = 7;
const int LMPWM = 9;
const int RMPWM = 10;

void setup() {

  // Initialize the pin states used 
  digitalWrite(LMPWM, LOW);
  pinMode(LMPWM, OUTPUT);
  digitalWrite(RMPWM, LOW);
  pinMode(RMPWM, OUTPUT);
  digitalWrite(LMDIR, HIGH);
  pinMode(LMDIR, OUTPUT);
  digitalWrite(RMDIR, LOW);
  pinMode(RMDIR, OUTPUT);

  // We'll use the serial monitor to view and send movement commands
  Serial.begin(9600);
}

void loop() {

  // Reset the motors to stationary and in forward direction
  
  analogWrite(LMPWM, 0);
  analogWrite(RMPWM, 0);
  digitalWrite(LMDIR, HIGH);
  digitalWrite(RMDIR, LOW);

  // Make PiBot turn to the right for two second
  Serial.println("Left motor moving forward");
  analogWrite(LMPWM, 127);
  delay(2000);
  
  // Make PiBot turn to the left for two second
  Serial.println("Left motor stopped. Right Motor moving forward");
  analogWrite(LMPWM, 0);
  analogWrite(RMPWM, 127);
  delay(2000);
  
  
   // Make PiBot go foreward for 2s 
  Serial.println("Both motors moving forward at half speed");
  analogWrite(LMPWM, 127);
  analogWrite(RMPWM, 127);
  
  delay(2000);
  
  
   // Make PiBot go backward for 2s 
  Serial.println("Both motors moving backward at half speed");
  digitalWrite(LMDIR, LOW);
  digitalWrite(RMDIR, HIGH);
  
  delay(2000);
  
  
  //Stop the robot and pause before loop repeats  
  Serial.println("Both motors stopping for six seconds before next loop");
  analogWrite(LMPWM, 0);
  analogWrite(RMPWM, 0);
  
  delay(6000);
  
}
