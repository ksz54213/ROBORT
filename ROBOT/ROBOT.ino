15:30 薛華慶 #include <LedControl.h>
#include <CapacitiveSensor.h>
#define p1 8
#define p2 7
#define p3 6
#define p4 5
#define trigPin 11
#define echoPin 12
#define DIN 2
#define CS 3
#define CLK 4 
int t=0,sensor=0,sen=0;
CapacitiveSensor cs_7_9 = CapacitiveSensor(9, 10);
LedControl lc = LedControl(DIN, CLK, CS, 2); 
const byte mouth [16] = { 
B00000000,
B00000000,
B00000000,
B00100000,
B11100000,
B11000000,
B00000000,
B00000000,
//
B00000000,
B00000000,
B00000000,
B00000100,
B00000111,
B00000011,
B00000000,
B00000000,
 };
const byte mouth2 [16] = { 

B00000000,
B00000000,
B00000000,
B10000000,
B11000000,
B11100000,
B11100000,
B00000000,
//
B00000000,
B00000000,
B00000000,
B00000001,
B00000011,
B00000111,
B00000111,
B00000000,
 };
const  byte mouth3 [16] = { 

B11111111,
B00000001,
B00000001,
B00000001,
B00000001,
B00000001,
B00000001,
B11111111,
//
B11111111,
B10000000,
B10000000,
B10000000,
B10000000,
B10000000,
B10000000,
B11111111,
 };
const byte mouth4 [16] = {
     
B00000000,    
B00000000,
B00000000,
B00010000,
B10101000,
B01000000,
B00000000,
B00000000,
//
B00000000,
B00000000,
B00000000,
B00010001,
B00101010,
B00000100,
B00000000,
B00000000,
 };
const byte mouth5 [16] = { 

B11110000,
B01010000,
B01010000,
B01010000,
B01010000,
B01010000,
B01010000,
B11111000,
//
B00011111,
B00010101,
B00010101,
B00010101,
B00010101,
B00010101,
B00010101,
B00111111,
 };
 //-------------------math--------------------------//
const byte math [16] = {
     
B11000000,    
B00000000,
B00000000,
B11000000,
B01000000,
B01000000,
B11000000,
B00000000,
//
B00000011,
B00000010,
B00000010,
B00000011,
B00000000,
B00000000,
B00000011,
B00000000,
 };

 const byte math1 [16] = {
     
B01000000,    
B01000000,
B01000000,
B11000000,
B01000000,
B01000000,
B01000000,
B00000000,
//
B00000010,
B00000010,
B00000010,
B00000011,
B00000000,
B00000000,
B00000000,
B00000000,
 };
 
const byte math2 [16] = {
     
B11000000,    
B01000000,
B01000000,
B11000000,
B01000000,
B01000000,
B11000000,
B00000000,
//
B00000011,
B00000000,
B00000000,
B00000011,
B00000000,
B00000000,
B00000011,
B00000000,
 };
 
const byte math3 [16] = {
     
B11000000,    
B01000000,
B01000000,
B11000000,
B00000000,
B00000000,
B11000000,
B00000000,
//
B00000011,
B00000000,
B00000000,
B00000011,
B00000010,
B00000010,
B00000011,
B00000000,
 };

const byte math4 [16] = {
     
B10000000,    
B10000000,
B10000000,
B10000000,
B10000000,
B10000000,
B10000000,
B00000000,
//
B00000001,
B00000001,
B00000001,
B00000001,
B00000001,
B00000001,
B00000001,
B00000000,
 };

 const byte math5 [16] = {
     
B11000000,    
B01000000,
B01000000,
B01000000,
B01000000,
B01000000,
B11000000,
B00000000,
//
B00000011,
B00000010,
B00000010,
B00000010,
B00000010,
B00000010,
B00000011,
B00000000,
 };
void setup(){
  pinMode(10,OUTPUT);
  digitalWrite(10,0);
  pinMode(p1, OUTPUT);
  pinMode(p2, OUTPUT);
  pinMode(p3, OUTPUT);
  pinMode(p4, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  cs_7_9.set_CS_AutocaL_Millis(0xFFFFFFF);
  Serial.begin(115200);
  lc.shutdown(0, false);
  lc.shutdown(1, false);
  lc.setIntensity(0,1); 
  lc.setIntensity(1,1); 
  lc.clearDisplay(0);
  lc.clearDisplay(1);
}
void loop(){
 
  digitalWrite(trigPin,LOW);//UltraSonic
  delayMicroseconds(5);//UltraSonic
  digitalWrite(trigPin,HIGH);//UltraSonic
  delayMicroseconds(10);//UltraSonic
  digitalWrite(trigPin,LOW);//UltraSonic
  long microsec = pulseIn(echoPin,HIGH);//UltraSonic
  float cmMsec=(microsec/2)/29.1;//UltraSonic Distance
   
 
sen = Start(cmMsec); // 開機判斷

 

while (sen==1)
{
  digitalWrite(trigPin,LOW);//UltraSonic
  delayMicroseconds(5);//UltraSonic
  digitalWrite(trigPin,HIGH);//UltraSonic
  delayMicroseconds(10);//UltraSonic
  digitalWrite(trigPin,LOW);//UltraSonic
  long microsec = pulseIn(echoPin,HIGH);//UltraSonic
  float cmMsec=(microsec/2)/29.1;//UltraSonic Distance
  long total2 = cs_7_9.capacitiveSensor(50);Serial.print(total2);
 Serial.println(total2);

    t++;
   
  
   
  
  if(t==0)
  {
    for(int i = 0;i<8;i++)
    {
       lc.setColumn(0,7-i,mouth[i]);
       lc.setColumn(1,7-i,mouth[i+8]);
    }
  }
  
  else if(t==1)
  {
    for(int i = 0;i<8;i++)
     {
       lc.setColumn(0,7-i,mouth2[i]);
       lc.setColumn(1,7-i,mouth2[i+8]);
     }
  }
     
  else if(t==2)
  {
    for(int i = 0;i<8;i++)
    {
      lc.setColumn(0,7-i,mouth3[i]);
      lc.setColumn(1,7-i,mouth3[i+8]);
    }
  }
  
  else if(t==3)
  {
    for(int i = 0;i<8;i++)
    {
      lc.setColumn(0,7-i,mouth4[i]);
      lc.setColumn(1,7-i,mouth4[i+8]);
    }
  } 
  
  else if(t==4)
  {
    for(int i = 0;i<8;i++)
    {
      lc.setColumn(0,7-i,mouth5[i]);
      lc.setColumn(1,7-i,mouth5[i+8]);
    }
  } 
  else if(t==5)
  {
    t=0;
  }
  Ring();
  if(cmMsec<=22)
  {Onfwd(1350,-1350);//middle;//轉彎
  delay(300);}
  else
  Onfwd(250,1350);

}

  
}

void Ring(){
  tone(9,262,100);
  noTone(9);
  delay(300);
  tone(9,262,300);
  noTone(9);
  delay(300);
  tone(9,262,100);
  noTone(9);
  delay(300);

}
int Start(float cmMsec){
  if(cmMsec<=12)
  {
 //5
      for(int i = 0;i<8;i++)
      {
        lc.setColumn(0,7-i,math[i]);
        lc.setColumn(1,7-i,math[i+8]);
      }
      delay(1000);
  //4 
      for(int i = 0;i<8;i++)
      {
        lc.setColumn(0,7-i,math1[i]);
        lc.setColumn(1,7-i,math1[i+8]);
      }
      delay(1000);
    //3
      for(int i = 0;i<8;i++)
      {
        lc.setColumn(0,7-i,math2[i]);
        lc.setColumn(1,7-i,math2[i+8]);
     }
     delay(1000);
    //2
      for(int i = 0;i<8;i++)
      {
       lc.setColumn(0,7-i,math3[i]);
       lc.setColumn(1,7-i,math3[i+8]);
      }
      delay(1000);
    //1
      for(int i = 0;i<8;i++)
      {
        lc.setColumn(0,7-i,math4[i]);
        lc.setColumn(1,7-i,math4[i+8]);
      }
      delay(1000);
    //0
      for(int i = 0;i<8;i++)
      {
        lc.setColumn(0,7-i,math5[i]);
        lc.setColumn(1,7-i,math5[i+8]);
      }
      delay(1000);
     // 左右擺
  Onfwd(1350,-250); //left
  delay(200);
  Onfwd(-250,1350);//middle
  delay(200);
  Onfwd(-250,1350);//right
  delay(200);
  Onfwd(1350,-250);//middle
  delay(200);
  Onfwd(-250,1350);//right
  delay(200);

    sen=1;
  }
  return sen;
}
//----------------------------
void Onfwd(int R,int L){
  if(R>=0){
    int PR = R*5/2;
    if(PR>255)
      PR=255;
    analogWrite(p1,PR);
    analogWrite(p2,0);
  }
  else{
    int PR=-R*5/2;
    if(PR>255)
      PR=255;
    analogWrite(p1,0);
    analogWrite(p2,PR);
  }
//---------------------
  if(L>=0){
    int PL = L*5/2;
    if(PL>255)
      PL=255;
    analogWrite(p3,PL);
    analogWrite(p4,0);
  }
  else{
    int PL=-L*5/2;
    if(PL>255)
      PL=255;
    analogWrite(p3,0);
    analogWrite(p4,PL);
  }
  
}
