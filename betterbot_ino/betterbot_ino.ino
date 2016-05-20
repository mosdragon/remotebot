// Adafruit Motor shield library
// copyright Adafruit Industries LLC, 2009
// this code is public domain, enjoy!

#include <AFMotor.h>
#include <Servo.h> 

#define AHEAD "F"
#define BACK "B"
#define LEFT "L"
#define RIGHT "R"    
#define STOP "S"


// DC motor on M1
AF_DCMotor left(1);
// DC motor on M2
AF_DCMotor right(2);


void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Motor party!");
   
  left.setSpeed(200);
  right.setSpeed(200);
  left.run(RELEASE);
  right.run(RELEASE);
}


void moveForward()
{
  left.run(FORWARD);
  right.run(FORWARD);
}

void moveBackward()
{
  left.run(BACKWARD);
  right.run(BACKWARD);
}

void turnLeft()
{
  left.run(FORWARD);
  right.run(BACKWARD);
}

void turnRight()
{
  left.run(BACKWARD);
  right.run(FORWARD);
}

void stopBot()
{
  left.run(RELEASE);
  right.run(RELEASE);
}

void loop() {
  String s = getData();
  if (s == AHEAD) {
    moveForward();
  } else if (s == BACK) {
    moveBackward();
  } else if (s == LEFT) {
    turnLeft();
  } else if (s == RIGHT) {
    turnRight();
  } else if (s == STOP) {
    stopBot();
  }
  // otherwise, don't care what it is
  if (s != "") {
    Serial.println(s);
  }
  delay(500);
  
}


String getData()
{
  String content = "";
  char character;

  while(Serial.available()) {
      character = Serial.read();
      content.concat(character);
  }
  content.trim();
  return content;
}
