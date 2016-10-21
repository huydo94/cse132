/* cricket
 *  
 *  CSE 132 - Assignment 3
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
const int FILTER_COUNTS = 5;
float temps[FILTER_COUNTS];
int count = 0;
#define analogPin 2
int val=0;
unsigned long previoustime = 0;
unsigned long previoustime1 = 0;
int ledPin = 13;
float temp = 0;
float avgtemp =0;
int period = 400;
boolean light = false;



void setup() {
  // put your setup code here, to run once:
  analogReference(INTERNAL);
  Serial.begin(9600);
  pinMode(ledPin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long currenttime = millis();  
  if (currenttime - previoustime >= 250){  //doesn't work with == sign
    previoustime = currenttime;
    readTemp();
  }
  if (light){
      if (currenttime - previoustime1 >= 200){ //doesn't work with == sign
        previoustime1 = currenttime;
        digitalWrite(ledPin,LOW);
        light = false;
      }
  }    
  else{
      if (currenttime - previoustime1 >= (period-200)){   //doesn't work with == sign
        previoustime1 = currenttime;
        digitalWrite(ledPin,HIGH);  
        light = true;
      }
  }
}

void readTemp(){
  val = analogRead(analogPin);
  temp = (1.1/1023)*val*100-50;
  temps[count % FILTER_COUNTS] = temp;
  count += 1;
  avgtemp = (temps[0]+temps[1]+temps[2]+temps[3]+temps[4])/5;
  period = 60000/(7*avgtemp-30);
  Serial.print(temp);
  Serial.print(",");
  Serial.println(avgtemp);
}
