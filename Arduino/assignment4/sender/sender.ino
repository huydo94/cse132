/* sender
 *  
 *  CSE 132 - Assignment 4
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
unsigned long previoustime = 0;
unsigned long currenttime = 0;
unsigned long data = 10000;
const int FILTER_COUNTS = 5;
float temps[FILTER_COUNTS];
int count = 0;
float temp = 0;
float avgtemp =0;
short val2 = 0;
#define analogPin 2 //input PIN for temp sensor
#define analogPin2 4 //input PIN for POT


void setup() {
  // put your setup code here, to run once:
  analogReference(DEFAULT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  currenttime = millis();
  if (currenttime - previoustime >= 2000){
    previoustime = currenttime;
    timemessage();
    readTemp();
    readpot();
    if (val2 > 800){
      sendDebug("highalarm");
  }
    sendDebug("huydo");
  }
}  
void sendDebug(String myString){
  //byte debug[] = {0x00, 0x05, 0x48, 0x65, 0x6C, 0x6C, 0x6F};
  Serial.write(0x21);
  Serial.write(0x30);
  int j =0;
  byte debug[100];
  for (int i = 2;myString[i-2] !='\0';i++){
     debug[i]=myString[i-2];
     j = j+1;
     }
  debug[0] = 0x00;
  debug[1] = (byte)j;
  Serial.write(debug,sizeof(debug));  
}
void timemessage(){
    byte buf[4];
    buf[3] = currenttime & 255;
    buf[2] = (currenttime >> 8)  & 255;
    buf[1] = (currenttime >> 16) & 255;
    buf[0] = (currenttime >> 24) & 255;
    Serial.write(0x21);
    Serial.write(0x32);
    Serial.write(buf, sizeof(buf));

    //Serial.write((byte*)&currenttime, sizeof(currenttime)); //another way, but the bytes are flipped in java
  }
  
void readpot(){
  val2 = analogRead(analogPin2);
  byte pot[2];
  pot[1] = val2 & 255;
  pot[0] = (val2 >> 8) & 255;
  Serial.write(0x21);
  Serial.write(0x33);
  Serial.write(pot, sizeof(pot));
}

void readTemp(){
  int val = analogRead(analogPin);
  temp = (5.0/1023)*val*100-50;
  temps[count % FILTER_COUNTS] = temp;
  count += 1;
  avgtemp = (temps[0]+temps[1]+temps[2]+temps[3]+temps[4])/5;

 ////////////// Send the raw temp data
  unsigned long raw;
  raw = *(unsigned long*) &temp;
  Serial.write(0x21);
  Serial.write(0x34);
  byte temp1[4];
  temp1[3] = raw & 255;
  temp1[2] = (raw >> 8)  & 255;
  temp1[1] = (raw >> 16) & 255;
  temp1[0] = (raw >> 24) & 255;
  Serial.write(temp1, sizeof(temp1));
 ////////////
  unsigned long avg;
  avg = *(unsigned long*) &avgtemp;
  Serial.write(0x21);
  Serial.write(0x36);
  byte temp2[4];
  temp2[3] = avg & 255;
  temp2[2] = (avg >> 8)  & 255;
  temp2[1] = (avg >> 16) & 255;
  temp2[0] = (avg >> 24) & 255;
  Serial.write(temp2, sizeof(temp2));
 /////////////////
}

