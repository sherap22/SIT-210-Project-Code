#define r1 2
#define y1 3
#define g1 4

#define r2 5
#define y2 6
#define g2 7

#define ir1 8
#define ir2 9
#define ir3 10
#define ir4 11

int T1=8000;

unsigned char ir1_v,ir2_v,ir3_v,ir4_v;

void readCongestion()
{
  
  ir1_v=digitalRead(ir1);
  ir2_v=digitalRead(ir2);
  ir3_v=digitalRead(ir3);
  ir4_v=digitalRead(ir4);
  
  if(ir1_v==1  && ir2_v==0)
     {
      Serial.println("L3");
      }
  else if(ir1_v==1  && ir2_v==1)
     {
      Serial.println("L6");
      }   
      else{ Serial.println("LN");}  
      
  if(ir3_v==1  && ir4_v==0)
     {
      Serial.println("R3");
      }
  else if(ir3_v==1  && ir4_v==1)
     {
      Serial.println("R6");
      }
    else{ Serial.println("LR");}         

      
  while (Serial.available()) 
  {
       int Val=Serial.read()-'0';    
 
       T1=T1+(Val*1000);
     }
  
  }


void setup() 
{
  
  Serial.begin(9600);
  pinMode(r1,OUTPUT);
  pinMode(y1,OUTPUT);
  pinMode(g1,OUTPUT);

  pinMode(r2,OUTPUT);
  pinMode(y2,OUTPUT);
  pinMode(g2,OUTPUT);
 
  pinMode(ir1,INPUT);
  pinMode(ir2,INPUT);
  pinMode(ir3,INPUT);
  pinMode(ir4,INPUT);
 
  digitalWrite(r1,LOW);digitalWrite(y1,LOW);digitalWrite(g1,LOW);
  digitalWrite(r2,LOW);digitalWrite(y2,LOW);digitalWrite(g2,LOW); 

  }

void loop() 
{
  
  digitalWrite(r1,HIGH);digitalWrite(y1,LOW);digitalWrite(g1,HIGH);//light 1 yellow
  digitalWrite(r2,LOW);digitalWrite(y2,HIGH);digitalWrite(g2,HIGH); 
  readCongestion();
  delay(4000);

  digitalWrite(r1,HIGH);digitalWrite(y1,HIGH);digitalWrite(g1,LOW);//light 1 green
  digitalWrite(r2,LOW);digitalWrite(y2,HIGH);digitalWrite(g2,HIGH);
  readCongestion();
  delay(T1);

  digitalWrite(r1,LOW);digitalWrite(y1,HIGH);digitalWrite(g1,HIGH);//light 2 yellow
  digitalWrite(r2,HIGH);digitalWrite(y2,LOW);digitalWrite(g2,HIGH);
  readCongestion();
  delay(4000);

  digitalWrite(r1,LOW);digitalWrite(y1,HIGH);digitalWrite(g1,HIGH);//light 2 green
  digitalWrite(r2,HIGH);digitalWrite(y2,HIGH);digitalWrite(g2,LOW);
  readCongestion();
  delay(T1);  
  
}
