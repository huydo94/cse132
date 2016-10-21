/* health
 *  
 *  CSE 132 - Assignment 10
 *  
 *  Fill this out so we know whose studio this is.
 *  
 *  Name: Huy Do
 *  WUSTL Key: huy.do
 *  
 *  Name:
 *  WUSTL Key:
 *  
 */

#include <Arduino.h>
#include <Wire.h>
#include <ST7036.h>
#include <Adafruit_MMA8451.h>
#include <Adafruit_Sensor.h>

int sensor = A3;
unsigned long currenttime = 0;
unsigned long previoustime = 0;
unsigned long currenttime2 = 0;

Adafruit_MMA8451 mma = Adafruit_MMA8451();
ST7036 lcd = ST7036 ( 2, 16, 0x7c );

void setup ()
{
  Serial.begin(115200);
  lcd.init ();
  lcd.setContrast(0);
   if (! mma.begin()) {
    while (1);
  }
  // insert code here as needed
  mma.setRange(MMA8451_RANGE_8_G);
}

void loop ()
{

  // insert code here as needed
   // Read the 'raw' data in 14-bit counts
  mma.read();

  /* Get a new sensor event */ 
  sensors_event_t event; 
  mma.getEvent(&event);

//send the z values
  unsigned long zvalue;
  zvalue = *(long*) &(event.acceleration.z);
  Serial.write(0x21);
  Serial.write(0x34);
  byte z[4];
  z[3] = zvalue & 255;
  z[2] = (zvalue >> 8)  & 255;
  z[1] = (zvalue >> 16) & 255;
  z[0] = (zvalue >> 24) & 255;
  Serial.write(z, sizeof(z));

  delay(10);
  
  short sensorValue = analogRead(sensor);
  currenttime = micros();
  if (currenttime - previoustime >= 2000){
    Serial.write(0x21);
    Serial.write(0x35);
    byte sendpulse[2];
    sendpulse[1] = sensorValue & 255;
    sendpulse[0] = (sensorValue >> 8)  & 255;

    Serial.write(sendpulse, sizeof(sendpulse));
  }
  displaym();
}
void displaym(){
  //delay(1000);

  int number = Serial.available();
    if (number > 0){   
      byte data = Serial.read(); // read data from Serial Monitor
        // display on LCD
        if (data==0x22){
          byte data2 = Serial.read();
          byte data3 = Serial.read();
          byte data4 = Serial.read();
          byte data5 = Serial.read();
          int stepcount = (data2)+(data3<<8);
          int pulsecount = (data4)+(data5<<8);
          lcd.clear();
          lcd.print(stepcount);
          lcd.setCursor (1,0);
          lcd.print(pulsecount);
        }
    }
  }


