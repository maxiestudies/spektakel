// Analog output controlled from Pure Data
// Written by Alexandros Drymonitis
// This code was written for the "Arduino for Pd'ers" tutorial
// and is in the public domain

// variable to hold LED's pin number
int led = 9;

void setup()
{
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  while(Serial.available()){
    byte LEDpwm = Serial.read();
    // use the analogWrite function for PWM
    analogWrite(led, LEDpwm);
  }
}
