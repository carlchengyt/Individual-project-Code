#include <AFMotor.h>
#include <SPI.h> // This library allows communication with SPI devices
int speed_scale = 5;//from 1-5
//msg = 'BR'

// setting motor names
AF_DCMotor motor1(1); // left front
AF_DCMotor motor2(2); // right front
AF_DCMotor motor3(3); // left back
AF_DCMotor motor4(4); // right back
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600); // Starts the serial communication

}

void loop() {
  // put your main code here, to run repeatedly:
motor1.setSpeed(51*speed_scale);
    motor1.run(FORWARD);
motor2.setSpeed(51*speed_scale);
    motor2.run(BACKWARD);
motor3.setSpeed(51*speed_scale);
    motor3.run(FORWARD);
motor4.setSpeed(51*speed_scale);
    motor4.run(BACKWARD);
    delay(1000);
}
