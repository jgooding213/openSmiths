/*
Welcome to OpenSmiths
Main code for smiths clock tachometer

Author: James Gooding 
v0.1 May 2024

This file may be distributed under the terms .... @@@
*/

#include <Servo.h>
#include <FreqMeasure.h>

Servo myservo;         // create servo object to control a servo
                       // twelve servo objects can be created on most boards
int pos = 0;           // variable to store the servo position
float frequency = 0;   //= FreqMeasure.countToFrequency(sum / count);
float RPM = 0;         //frequency *60;
float servoAngle = 0;  //map(RPM, 500, 5200, 0, 180);  // clockwise with 0 at the top of the smiths clock

void setup() {
  Serial.begin(57600);
  FreqMeasure.begin();
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

double sum = 0;
int count = 0;
int lowerNeedleOffset = 10;

void loop() {
  elapsedMillis timeout;
  while (timeout < 100) { // If zero frequency is read in 100ms (< 6RPM) then set servo to zero position 
    //Serial.println("ZERO");
    if (FreqMeasure.available()) {
      // can average several reading together, will affect the needles "realistic flicker"
      sum = sum + FreqMeasure.read();
      count = count + 1;

      Serial.println(timeout);


      if (count > 1) {
        frequency = FreqMeasure.countToFrequency(sum / count);
        RPM = frequency * 60;
        servoAngle = map(RPM, 500, 5200, 0, 180);  // clockwise with 0 at the top of the smiths clock
        Serial.print("Frequency: ");
        Serial.print(frequency);
        Serial.print("   RPM: ");
        Serial.print(RPM);
        Serial.print("   Smiths needle angle: ");
        Serial.print(servoAngle);
        Serial.println("");
        pos = (int)servoAngle + lowerNeedleOffset;
        Serial.println(pos);
        myservo.write(pos);
        sum = 0;
        count = 0;
      }
    }
  }

// If zero frequency is read in 100ms (< 6RPM) then set servo to zero position //hopefully while teensy still has power...
  Serial.println("ZERO");
  myservo.write(0 + lowerNeedleOffset);





}

