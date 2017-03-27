#include <Arduino.h>
#include <MuxShield.h>
void setup(void);
void loop(void);
#line 1 "src/sketch.ino"
/* Photocell simple testing sketch. 
 
Connect one end of the photocell to 5V, the other end to Analog 0.
Then connect one end of a 10K resistor from Analog 0 to ground 
Connect LED from pin 11 through a resistor to ground 
For more information see http://learn.adafruit.com/photocells */

//#include <MuxShield.h>

//Initialize the Mux Shield
MuxShield muxShield;

/* 
int photocellPin = 0;     // the cell and 10K pulldown are connected to a0
int photocellReading;     // the analog reading from the sensor divider
int LEDpin = 11;          // connect Red LED to pin 11 (PWM pin)
int LEDbrightness;        // 
*/
void setup(void) {

  //Set I/O 1, I/O 2, and I/O 3 as analog inputs on the mux shield
  muxShield.setMode(1,ANALOG_IN);
  muxShield.setMode(2,ANALOG_IN);
  muxShield.setMode(3,ANALOG_IN);
    
  // We'll send debugging information via the Serial monitor
  //Serial.begin(9600);   
  Serial.begin(28800);
}
 
void loop(void) {
  for (int i=0; i<16; i++)
  {
    //Analog read on all 16 inputs on IO1, IO2, and IO3
    IO1AnalogVals[i] = muxShield.analogReadMS(1,i);
    IO2AnalogVals[i] = muxShield.analogReadMS(2,i);
    IO3AnalogVals[i] = muxShield.analogReadMS(3,i);
  }
  
  //Print IO1 values for inspection
  Serial.print("IO1 analog values: ");
  for (int i=0; i<16; i++)
  {
    Serial.print(IO1AnalogVals[i]);
    Serial.print('\t');
  }
  Serial.println();
  /*
  photocellReading = analogRead(photocellPin);  
 
  Serial.print("Analog reading = ");
  Serial.println(photocellReading);     // the raw analog reading
 
  // LED gets brighter the darker it is at the sensor
  // that means we have to -invert- the reading from 0-1023 back to 1023-0
  photocellReading = 1023 - photocellReading;
  //now we have to map 0-1023 to 0-255 since thats the range analogWrite uses
  LEDbrightness = map(photocellReading, 0, 1023, 0, 255);
  analogWrite(LEDpin, LEDbrightness);
 
  delay(100);
  */
}
