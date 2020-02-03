#include <CapacitiveSensor.h>

/*
 * CapitiveSense Library Demo Sketch
 * Paul Badger 2008
 * Uses a high value resistor e.g. 10M between send pin and receive pin
 * Resistor effects sensitivity, experiment with values, 50K - 50M. Larger resistor values yield larger sensor values.
 * Receive pin is the sensor pin - try different amounts of foil/metal on this pin
 */

CapacitiveSensor   cs_3 = CapacitiveSensor(2,3);
CapacitiveSensor   cs_4 = CapacitiveSensor(2,4);        // 10M resistor between pins 2 & 4, pin 4 is sensor pin, add a wire and or foil if desired
CapacitiveSensor   cs_5 = CapacitiveSensor(2,5);
CapacitiveSensor   cs_6 = CapacitiveSensor(2,6);        
CapacitiveSensor   cs_7 = CapacitiveSensor(2,7);
CapacitiveSensor   cs_8 = CapacitiveSensor(2,8);
CapacitiveSensor   cs_9 = CapacitiveSensor(2,9);
CapacitiveSensor   cs_10 = CapacitiveSensor(2,10);
CapacitiveSensor   cs_11 = CapacitiveSensor(2,11);
CapacitiveSensor   cs_12 = CapacitiveSensor(2,12);
byte output[10] = {0};


void setup()                    
{
   cs_4.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1 - just as an example
   Serial.begin(9600);

}

void loop()                    
{

    output[0] =  cs_3.capacitiveSensor(5);
    output[1] =  cs_4.capacitiveSensor(5);
    output[2] =  cs_5.capacitiveSensor(30);
    output[3] =  cs_6.capacitiveSensor(30);
    output[4] =  cs_7.capacitiveSensor(30);
    output[5] =  cs_8.capacitiveSensor(30);
    output[6] =  cs_9.capacitiveSensor(30);
    output[7] =  cs_10.capacitiveSensor(30);
    output[8] =  cs_11.capacitiveSensor(30);
    output[9] =  cs_12.capacitiveSensor(30);
    
//    for(int i = 0; i <= sizeof(output)/sizeof(byte); i++){
//      Serial.print(output[i]);
//      Serial.print("\t");
//    }
//    Serial.println();

    Serial.write(output, 10);                  // write to serial line

    delay(1);                             // arbitrary delay to limit data to serial port 
}
