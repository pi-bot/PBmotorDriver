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
  digitalWrite(LMDIR, LOW);
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
  analogWrite(LMDIR, LOW);
  analogWrite(LMDIR, LOW);


  // Make PiBot turn to the right for one second
  analogWrite(LMPWM, 127);
  
  
  // Make PiBot turn to the left for one second
  analogWrite(LMPWM, 0);
  analogWrite(RMPWM, 127);
  
  delay(1000);
  
  
   // Make PiBot go foreward for 1s 
  analogWrite(LMPWM, 127);
  analogWrite(RMPWM, 127);
  
  delay(1000);
  
  
   // Make PiBot go backward for 1s 
  analogWrite(LMDIR, HIGH);
  analogWrite(LMDIR, HIGH);
  
  delay(1000);
  
  
  //Stop the robot for 3s before loop repeats  
  
  analogWrite(LMPWM, 127);
  analogWrite(RMPWM, 127);
  
  delay(3000);
  
}
