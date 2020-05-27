const int pingPin = A4; // Trigger Pin of Ultrasonic Sensor
const int echoPin = A5; // Echo Pin of Ultrasonic Sensor
int cm1 = 0;
int cm2 = 0;
int cm3 = 0;
int sum = 0;
void setup() {
   Serial.begin(9600); // Starting Serial Terminal
}

void loop() {
   long duration, inches, cm;
   pinMode(pingPin, OUTPUT);
   digitalWrite(pingPin, LOW);
   delayMicroseconds(5);
   digitalWrite(pingPin, HIGH);
   delayMicroseconds(15);
   digitalWrite(pingPin, LOW);
   pinMode(echoPin, INPUT);
   duration = pulseIn(echoPin, HIGH);
   cm = microsecondsToCentimeters(duration);
   // exclude values larger than 3m
   cm1 = cm2;
   cm2 = cm3;
   if (cm <= 500){
     cm3 = cm;}
     else {
     cm3 = cm2;
     Serial.print("out of range");}
   sum = cm1 + cm2 + cm3;
   delay(85);
}


long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}
