#include <Wire.h>
#include <Adafruit_MotorShield.h>
//#include "utility/Adafruit_PWMServoDriver.h"
 
Adafruit_Motorshield *left;
Adafruit_Motorshield *right;
 
void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Motor test!");
  
  left = AFMS.getMotor(1);
  right = AFMS.getMotor(2);
  
  left.setSpeed(200);     // set the speed to 200/255
  right.setSpeed(200);     // set the speed to 200/255
}
 
void loop() {
  Serial.print("tick");
  
  left.run(FORWARD);      // turn it on going forward
  delay(1000);
 
  Serial.print("tock");
  right.run(BACKWARD);     // the other way
  delay(1000);
  
  Serial.print("tack");
  left.run(RELEASE);      // stopped
  right.run(RELEASE);      // stopped
  delay(1000);
}
