/* indicator
 *  
 *  CSE 132 - Assignment 2
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
#define analogPin 3  //read the voltage signal 
#define red  7
#define blue  5
#define green  3
int val = 0; //voltage signal level between 0 and 1023
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);   //display val to the monitor
}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(analogPin);
  if (val > 800){  //blink red when val > 800
    analogWrite(blue,0);
    analogWrite(green,0);
    analogWrite(red,255);
    delay(100);
    analogWrite(red,0);
    delay(1000);  
  }
  else{     //change the LED color between green and blue
    analogWrite(green,val/4);
    analogWrite(blue,(800-val)/4);
  }
  Serial.println(val);
}
