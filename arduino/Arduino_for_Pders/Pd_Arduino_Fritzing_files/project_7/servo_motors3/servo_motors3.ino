// Controlling two Servo motors from Pure Data
// Written by Alexandros Drymonitis
// This code was written for the "Arduino for Pd'ers" tutorial
// and is in the public domain

// import the Servo library
#include <Servo.h>
// define the number of servos used
#define NUM_OF_SERVOS 2

// create a Servo object array
Servo *servos[NUM_OF_SERVOS];
//servos = this Servo;

// array to hold the PWM pin numbers
int PWMpins[NUM_OF_SERVOS] = { 3, 9 };

// array to hold the motors degree values
byte PWMbyte[NUM_OF_SERVOS];

// variable to hold and assemble incoming data
// int temporary;

void setup()
{
  // attach pins to servo objects with a for loop
  for(int i = 0; i < NUM_OF_SERVOS; i++){
    servos->attach(PWMpins[i]);
    servos++;
  }
  Serial.begin(9600);
}

void loop()
{
   while(Serial.available()){
     static int temporary;
     byte inByte = Serial.read();
     if((inByte >= '0') && (inByte <= '9'))
       temporary = 10 * temporary + inByte - '0';
     else if((inByte >= 'a') && (inByte <= 'z')){
       // check whether we're exceeding array size
       if(inByte - 'a' >= NUM_OF_SERVOS) break;
       // if we're fine, write byte to corresponding array element
       PWMbyte[inByte - 'a'] = temporary;
       temporary = 0;
     }
     // write to servo pins with a for loop
     for(int i = 0; i < NUM_OF_SERVOS; i++){
       servos->write(PWMbyte[i]);
       servos++;
     }
   }
}
