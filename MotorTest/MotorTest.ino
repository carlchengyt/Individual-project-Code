// Adafruit Motor shield library
// copyright Adafruit Industries LLC, 2009
// this code is public domain, enjoy!

#include <AFMotor.h>

AF_DCMotor motor(1);

void setup() {

motor.setSpeed(200);
 
}

void loop() {
motor.run(FORWARD);
motor.setSpeed(255);  
delay(10);
  
}
