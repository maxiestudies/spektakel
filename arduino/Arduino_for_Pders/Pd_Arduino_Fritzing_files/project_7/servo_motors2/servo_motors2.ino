// Controlling two Servo motors from Pure Data
// Written by Alexandros Drymonitis
// This code was written for the "Arduino for Pd'ers" tutorial
// and is in the public domain

// import the Servo library
#include <Servo.h>
// define the number of servos used
#define NUM_OF_SERVOS 2

// create a Servo object array
Servo servos[NUM_OF_SERVOS];

// array to hold the PWM pin numbers
int PWMpins[NUM_OF_SERVOS] = { 3, 9 };

byte PWMbyte[NUM_OF_SERVOS];

int temp_val;

void setup()
{
  // attach pins to servo objects with a for loop
  for(int i = 0; i < NUM_OF_SERVOS; i++)
    servos[i].attach(PWMpins[i]);
    
  Serial.begin(9600);
}

void loop()
{
  while(Serial.available()){
    byte inByte = Serial.read();
    if((inByte >= '0') && (inByte <= '9'))
      temp_val = temp_val * 10 + inByte - '0';
    else if((inByte >= 'a') && (inByte <= 'z')){
      if(inByte - 'a' >= NUM_OF_SERVOS) break;
      PWMbyte[inByte - 'a'] = temp_val;
      temp_val = 0;
    }
   for(int i = 0; i < NUM_OF_SERVOS; i++)
     servos[i].write(PWMbyte[i]);
  }
}
