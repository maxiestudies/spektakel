// Digital input to be transferred to Pure Data
// Written by Alexandros Drymonitis
// This code was written for the "Arduino for Pd'ers" tutorial
// and is in the public domain

// set a variable to hold the button's pin number
int pushButton = 2;

void setup()
{
  pinMode(pushButton, INPUT);
  Serial.begin(9600);
}

void loop()
{
  // read and store the data from the push button
  byte buttonState = digitalRead(pushButton);
  // write the stored data to the serial port
  Serial.write(buttonState);
}
