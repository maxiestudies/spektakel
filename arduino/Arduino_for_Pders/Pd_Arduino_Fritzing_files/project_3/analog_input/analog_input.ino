// Analog input to be transferred to Pure Data
// Written by Alexandros Drymonitis
// This code was written for the "Arduino for Pd'ers" tutorial
// and is in the public domain

// variable to hold the knob's pin number, analog pin 0
int knob = 0;
// declare the array to be transferred over serial
byte myArray[3];

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  // set the first byte of the array to the hexadecimal value 192
  myArray[0] = 0xc0;
  int knobValue = analogRead(knob);
  myArray[1] = knobValue & 0x007f;
  myArray[2] = knobValue >> 7;
  Serial.write(myArray, 3);
}
