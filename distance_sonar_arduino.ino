/*
 * ultrasonic sensor pins:
 *    VCC: +5VDC
 *    Trig - pin 11
 *    Echo - pin 12
 *    GND - GND
 */
 int trigPin = 11;
 int echoPin = 12;
 long duration, cm, inches;
 
 void setup() {
  //serial port begin
  Serial.begin (9600);
  //Define inputs and outputs
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin,INPUT);

}

void loop() {
  //The sensor is triggered by a HIGH pulse of 10 or more microseconds
  //Give a short LOW pulse beforehand to ensure a clean HIGH pulse:

  digitalWrite(trigPin,LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);

  //read the signal from sensor : a HIGH pulse whose
  //duration is the time (in microseconds) from the sending 
  //of the ping to the reception of its echo off an object

  pinMode(echoPin,INPUT);
  duration = pulseIn(echoPin,HIGH);

  //convert the time into a distance
  cm = (duration/2)/29.1;
  inches = (duration/2)/74;

  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm, ");
  Serial.println();

  delay(250);

}
