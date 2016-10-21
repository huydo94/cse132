/* display
 *  
 *  CSE 132 - Assignment 7
 *  
 *  Fill this out so we know whose assignment this is.
 *  
 *  Name: Huy.Do
 *  WUSTL Key: huy.do
 *  
 *  Name:
 *  WUSTL Key:
 *  
 */

#include <Arduino.h>
#include <Wire.h>
#include <ST7036.h>
#include "font.h"

ST7036 lcd = ST7036 ( 2, 16, 0x7c );

int left = 12;
int right = 15;
int up = 13;
int down = 16;

int left1 = 0;
int right1 = 0;
int up1 = 0;
int down1 = 0;

int row[] = {0,1,2,3,4,5,6};

int col[] = {7,8,9,10,11};
byte c = 0x03;

int val = 0;
int count = 0;

void setup ()
{
  lcd.init ();
  lcd.setContrast(0);
  // insert code here as needed
  
  pinMode(left,INPUT_PULLUP); //push button goes high when open and low when pressed
  pinMode(right,INPUT_PULLUP);
  pinMode(up,INPUT_PULLUP);
  pinMode(down,INPUT_PULLUP);
  
  for (int j = 0;j<=6;j++){
    pinMode(row[j],OUTPUT);
  }
  for (int k = 0; k<=4;k++){
    pinMode(col[k],OUTPUT);
  } 
}

void loop ()
{
  lcd.clear ();
  // insert code here as needed
  left1 = digitalRead(left);
  right1 = digitalRead(right);
  up1 = digitalRead(up);
  down1 = digitalRead(down);
  if (left1 == LOW){
    count = count - 1;
    delay(1000);
  }
  if (right1 == LOW){
    count = count + 1;
    delay(1000);
  }
  if (up1 == LOW){
    count = count + 16;
    delay(1000);
  }
  if (down1 == LOW){
    count = count - 16;
    delay(1000);
  }
  byte disp = (byte) count + 0x20;
  lcd.write(disp);
  if (count > 0 && count <=96){
    for (int x=0;x<=4;x++){
      digitalWrite(col[x-1],LOW);
      digitalWrite(col[x-2],LOW);
      digitalWrite(col[x-3],LOW);
      digitalWrite(col[x-4],LOW);
      digitalWrite(col[x],HIGH);
      digitalWrite(col[x+1],LOW);
      digitalWrite(col[x+2],LOW);
      digitalWrite(col[x+3],LOW);
      digitalWrite(col[x+4],LOW);
      int eachled = font_5x7[count][x];
      for (int y=0;y<=6;y++){
        int lightstate = bitRead(eachled,y+1);
        digitalWrite(row[6-y],1-lightstate);
      }
      delay(5);
    }
  } else {
    count = 0;
  }
}
