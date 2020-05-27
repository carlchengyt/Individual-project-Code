#include <AFMotor.h>
#include <SPI.h> // This library allows communication with SPI devices
#include <WiFly.h> //include the WiFly experimental library
char msg[128];//variables for reading in the html responses
int letterCount = 0; 
int speed_scale = 4;//from 1-5
int input_mode = 0;
//msg = 'BR'

// setting motor names
AF_DCMotor motor1(1); // left front
AF_DCMotor motor2(2); // right front
AF_DCMotor motor3(3); // left back
AF_DCMotor motor4(4); // right back
void setup() {
  // put your setup code here, to run once:
  const int trigPin = A4; // Trigger Pin of Ultrasonic Sensor
  const int echoPin = A5; // Echo Pin of Ultrasonic Sensor
  pinMode (trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode (echoPin, INPUT); // Sets the echoPin as an Input 
  Serial.begin(9600);  //Serial communication at 9600 buad for debugging 
  
}

void loop() {
  
if (msg == 'L' )// Move Left
  {
    motor1.setSpeed(51*speed_scale);
        motor1.run(BACKWARD);
    motor2.setSpeed(51*speed_scale);
        motor1.run(FORWARD);
    motor3.setSpeed(51*speed_scale);
        motor1.run(FORWARD);
    motor4.setSpeed(51*speed_scale);
        motor1.run(BACKWARD);
        delay(1000);
  }
  //-------------------------------------------------------
  else if (msg == 'R')// Move Right
  {
    motor1.setSpeed(51*speed_scale);
        motor1.run(BACKWARD);
    motor2.setSpeed(51*speed_scale);
        motor1.run(FORWARD);
    motor3.setSpeed(51*speed_scale);
        motor1.run(FORWARD);
    motor4.setSpeed(51*speed_scale);
        motor1.run(BACKWARD);
        delay(1000);
  }
  //-------------------------------------------------------
  else if (msg == 'F')// Move Forward
  {
    motor1.setSpeed(51*speed_scale);
        motor1.run(FORWARD);
    motor2.setSpeed(51*speed_scale);
        motor1.run(FORWARD);
    motor3.setSpeed(51*speed_scale);
        motor1.run(FORWARD);
    motor4.setSpeed(51*speed_scale);
        motor1.run(FORWARD);
        delay(1000);
  }  
  //-------------------------------------------------------

  else if (msg == 'B')// Move Backward
  {
    motor1.setSpeed(51*speed_scale);
        motor1.run(BACKWARD);
    motor2.setSpeed(51*speed_scale);
        motor1.run(BACKWARD);
    motor3.setSpeed(51*speed_scale);
        motor1.run(BACKWARD);
    motor4.setSpeed(51*speed_scale);
        motor1.run(BACKWARD);
        delay(1000);
  }
  //-------------------------------------------------------


  else if (msg == 'RT')// Move Backward
  {
    motor1.setSpeed(51*speed_scale);
        motor1.run(FORWARD);
    motor2.setSpeed(51*speed_scale);
        motor1.run(BACKWARD);
    motor3.setSpeed(51*speed_scale);
        motor1.run(FORWARD);
    motor4.setSpeed(51*speed_scale);
        motor1.run(BACKWARD);
        delay(1000);
  }
  //-------------------------------------------------------
  else if (msg == 'LT')// Move Backward
  {
    motor1.setSpeed(51*speed_scale);
        motor1.run(BACKWARD);
    motor2.setSpeed(51*speed_scale);
        motor1.run(FORWARD);
    motor3.setSpeed(51*speed_scale);
        motor1.run(BACKWARD);
    motor4.setSpeed(51*speed_scale);
        motor1.run(FORWARD);
        delay(1000);
  }
  //-------------------------------------------------------
  else if (msg == 'FL')// Move Backward
  {
    motor1.setSpeed(51*speed_scale);
        motor1.run(RELEASE);
    motor2.setSpeed(51*speed_scale);
        motor1.run(BACKWARD);
    motor3.setSpeed(51*speed_scale);
        motor1.run(BACKWARD);
    motor4.setSpeed(51*speed_scale);
        motor1.run(RELEASE);
        delay(1000);
  }
  //-------------------------------------------------------
  else if (msg == 'BR')// Move Backward
  {
    motor1.setSpeed(51*speed_scale);
        motor1.run(BACKWARD);
    motor2.setSpeed(51*speed_scale);
        motor1.run(RELEASE);
    motor3.setSpeed(51*speed_scale);
        motor1.run(BACKWARD);
    motor4.setSpeed(51*speed_scale);
        motor1.run(RELEASE);
        delay(1000);
  }
  //-------------------------------------------------------

// angled turn needs to be added after testing
}//end checkAction()
