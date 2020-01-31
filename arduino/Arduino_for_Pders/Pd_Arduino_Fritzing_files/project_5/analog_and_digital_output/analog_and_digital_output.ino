// Analog and digital output controlled from Pure Data
// Written by Alexandros Drymonitis
// This code was written for the "Arduino for Pd'ers" tutorial
// and is in the public domain

// variables to hold pin numbers
int pwmLED = 9;
int dspLED = 2;
// variables to hold pin states
int pwmLEDvalue;
int dspLEDstate;
// variable to hold and assemble incoming data
int temporary;

void setup()
{
  pinMode(pwmLED, OUTPUT);
  pinMode(dspLED, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
   while(Serial.available()){
     byte inByte = Serial.read();
     if((inByte >= '0') && (inByte <= '9'))
       temporary = 10 * temporary + inByte - '0';
     else{
       if(inByte == 'p'){
         pwmLEDvalue = temporary;
         temporary = 0;
       }
       else if(inByte == 'd'){
         dspLEDstate = temporary;
         temporary = 0;
       }
     }
     analogWrite(pwmLED, pwmLEDvalue);
     digitalWrite(dspLED, dspLEDstate);
   }
}
