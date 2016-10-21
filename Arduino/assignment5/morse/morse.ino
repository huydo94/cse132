/* morse
 *  
 *  CSE 132 - Assignment 5
 *  
 *  Fill this out so we know whose assignment this is.
 *  
 *  Name: Huy Do
 *  WUSTL Key: huy.do
 *   
 *  and if two are partnered together
 *  
 *  Name:
 *  WUSTL Key:
 */

#include "morse.h"
#include <Arduino.h>
#include <Wire.h>
#include <ST7036.h>
ST7036 lcd = ST7036 ( 2, 16, 0x7c );
char incomingByte = 0;
int ledPin = 13;
unsigned long previoustime = 0;
unsigned long currenttime = 0;
int var = 8;
int j = 0;
int i = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.init ();
  lcd.setContrast(0);
  pinMode(ledPin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  readmessage();
}

void readmessage(){
    delay(1000); //very important to display LCD correctly
    
    int number = Serial.available();
    if (number > 0){
      
      char incomingBytes[number];
      unsigned int morsecode[number][5]; // two dimensional Morse code arrays
      
      for (i=0;i<=number;i++){
        byte data = Serial.read(); // read data from Serial Monitor
        // display on LCD
        incomingBytes[i] = (char) data;
        incomingBytes[number]='\0';
        lcd.clear();
        lcd.print(incomingBytes);
        // put the data into Morse code arrays
        int eachmorse = convertByte(data);
        if (eachmorse != -1){ 
          morsecode[i][0] = morse_chars[eachmorse][0];
          morsecode[i][1] = morse_chars[eachmorse][1];
          morsecode[i][2] = morse_chars[eachmorse][2];
          morsecode[i][3] = morse_chars[eachmorse][3];
          morsecode[i][4] = morse_chars[eachmorse][4];
          } else {
          Serial.println("There exists an invalid character.");
          }
      }
      // delta + case statement to control the LED. At first I used for loops for i and j, but it didn't work because j increments without control => need to 
      // use while loop in order to control the order.
        i = 0;
          while(j<=4 && i<number){
            currenttime = millis();
            switch (var){
              case 1: // the dot
                digitalWrite(ledPin,HIGH);
                if (currenttime - previoustime >= 1000){
                  digitalWrite(ledPin,LOW);
                  previoustime = currenttime;
                  var = 8;
                  j++;
                  Serial.println("1");
                }
                break;
             case 3: // the dash
                digitalWrite(ledPin,HIGH);
                if (currenttime - previoustime >= 3000){
                  digitalWrite(ledPin,LOW);
                  previoustime = currenttime;
                  var = 8;
                  j++;
                  Serial.println("3");  
                }
                break;
             case 0: // space between letters
                digitalWrite(ledPin,LOW);  
                if (currenttime - previoustime >= 1000){                   
                   previoustime = currenttime;
                   var = 8;
                   i++;
                   j=0;
                   Serial.println("0");  
                }
                break;
             case 7: // space between words
                digitalWrite(ledPin,LOW);
                if (currenttime - previoustime >= 4000){
                    previoustime = currenttime;
                    var = 8; 
                    i++;
                    j=0;
                    Serial.println("space");
                }
                break;               
             case 8: //space between parts of the same letters
                if (currenttime - previoustime >= 1000){                 
                  previoustime = currenttime;
                  var = morsecode[i][j];
                  if (morsecode[i][0] == 0){
                    var = 7;
                  }
                }
             break;   
            }
          }             
   }
}
















