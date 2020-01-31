// Controlling a Servo motor from Pure Data
// Written by Alexandros Drymonitis
// This code was written for the "Arduino for Pd'ers" tutorial
// and is in the public domain

// import the Servo library
#include <Servo.h>

// create a Servo object
Servo servo;

// variable to hold the PWM pin number
int PWMpin = 3;

void setup()
{
  servo.attach(PWMpin);
  Serial.begin(9600);
}

void loop()
{
  while(Serial.available()){
    byte PWMbyte = Serial.read();
    servo.write(PWMbyte);
  }
}
