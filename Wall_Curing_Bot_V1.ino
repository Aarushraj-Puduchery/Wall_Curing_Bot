//NUMPAD
#include <Keypad.h>
const byte ROWS = 4; 
const byte COLS = 4; 
char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[ROWS] = {22, 23, 24, 25};
byte colPins[COLS] = {26, 27, 28, 29}; 
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

//LCD
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2); 

//Servo
#include <Servo.h>
Servo myservo;
int pos = 0;

int Buzzer = 42;
int Relay = 44;
int SpeedS = 19;

//MOTOR
const int LFF = 46;
const int LFB = 47;
const int RFF = 48;
const int RFB = 49;
const int RBF = 50;
const int RBB = 51;
const int LBF = 52;
const int LBB = 53;
const int EN1 = 2;
const int EN2 = 3;
const int EN3 = 4;
const int EN4 = 5;

//UltraSonic
int UST1 = 11;
int USE1 = 12;
int UST2 = 9;
int USE2 = 10;
int UST3 = 7;
int USE3 = 8;

int RobotDistance;
int MinDistance = 30;
int num,D1,D2,D3;
int Dimensions[20],i,Sides,SideCount;
int Steps = 0;
int SW =1;
float Distance =0;

void Forward();
void Right();
void Left();
void Spray();
void Setup();
int GetNum();
int MinDist();
int DistTravel();
void DoorSpray();

void setup() {
  
  //LCD
  lcd.init();                    
  lcd.init();
  lcd.backlight();
  
  //Servo
  myservo.attach(13);

  //BUZZER
  pinMode(Buzzer,OUTPUT);

  //Relay
  pinMode(Relay,INPUT);

  //MOTOR
  pinMode(RFF, OUTPUT);
  pinMode(RFB, OUTPUT);
  pinMode(LFF, OUTPUT);
  pinMode(LFB, OUTPUT);
  pinMode(RBF, OUTPUT);
  pinMode(RBB, OUTPUT);
  pinMode(LBF, OUTPUT);
  pinMode(LBB, OUTPUT);
  pinMode(EN1, OUTPUT); 
  pinMode(EN2, OUTPUT);
  pinMode(EN3, OUTPUT); 
  pinMode(EN4, OUTPUT);

  //UltraSonic
  pinMode(UST1,OUTPUT);
  pinMode(USE1,INPUT);
  pinMode(UST2,OUTPUT);
  pinMode(USE2,INPUT);
  pinMode(UST3,OUTPUT);
  pinMode(USE3,INPUT);

  //Speed Sensor
  pinMode(SpeedS,INPUT_PULLUP);
  Setup();
      
  Serial.begin(9600);
  SideCount = 0;
  attachInterrupt(digitalPinToInterrupt(19), DistTravel, CHANGE);
}

void loop(){
      
      //UltraSonic
      digitalWrite(UST1, LOW);
      delayMicroseconds(2);
      digitalWrite(UST1, HIGH);
      delayMicroseconds(10);
      digitalWrite(UST1, LOW);
      int duration1 = pulseIn(USE1, HIGH);
      D1 = duration1/58.2;
      
      digitalWrite(UST2, LOW);
      delayMicroseconds(2);
      digitalWrite(UST2, HIGH);
      delayMicroseconds(10);
      digitalWrite(UST2, LOW);
      int duration2 = pulseIn(USE2, HIGH);
      D2 = duration2/58.2;
      
      digitalWrite(UST3, LOW);
      delayMicroseconds(2);
      digitalWrite(UST3, HIGH);
      delayMicroseconds(10);
      digitalWrite(UST3, LOW);
      int duration3 = pulseIn(USE3, HIGH);
      D3 = duration3/58.2;
      Serial.println("S1");
      Serial.println(D1);
      Serial.println("S2");
      Serial.println(D2);
      Serial.println("S3");
      Serial.println(D3);
      delay(1500);
  //Movement
  analogWrite(EN1, 200);
  analogWrite(EN2, 200);
  analogWrite(EN3, 200);
  analogWrite(EN4, 200);

    //while(SideCount<Sides)
    //{
  if((D1<=MinDistance) && D2>MinDistance && D3>MinDistance)
  {
    Forward();
  }
  else if((D1<=MinDistance) && D2<=MinDistance && (D3>MinDistance))
  { 
    Left();
  }
  else if((D1=D2=D3>MinDistance) || (D2=D3<=MinDistance && D1>MinDistance))
  {
    Right();  
  }
// }
}

void Forward()
{ 
  Serial.println("Forward");
  digitalWrite(RFF,LOW);
  digitalWrite(LFF,LOW);
  digitalWrite(RBF,LOW);
  digitalWrite(LBF,LOW);
  digitalWrite(RFF,HIGH);
  digitalWrite(LFF,HIGH);
  digitalWrite(RBF,HIGH);
  digitalWrite(LBF,HIGH);
  delay(300);
  digitalWrite(RFF,LOW);
  digitalWrite(LFF,LOW);
  digitalWrite(RBF,LOW);
  digitalWrite(LBF,LOW);
  Spray();
}

void Left()
{
  analogWrite(EN1, 130);
  analogWrite(EN2, 130);
  analogWrite(EN3, 130);
  analogWrite(EN4, 130);
  Serial.println("Left");
  digitalWrite(RFF,LOW);
  digitalWrite(LFF,LOW);
  digitalWrite(RBF,LOW);
  digitalWrite(LBF,LOW);
  digitalWrite(RFF,LOW);
  digitalWrite(LFF,HIGH);
  digitalWrite(RBF,LOW);
  digitalWrite(LBF,HIGH);
  SideCount++;
  Distance =0;
  delay(2200); 
  digitalWrite(RFF,LOW);
  digitalWrite(LFF,LOW);
  digitalWrite(RBF,LOW);
  digitalWrite(LBF,LOW);
  digitalWrite(RFF,LOW);
}

void Right()
{
  if(CheckDoor() == 0)
  {
    analogWrite(EN1, 130);
  analogWrite(EN2, 130);
  analogWrite(EN3, 130);
  analogWrite(EN4, 130);
  Serial.println("Right");
  digitalWrite(RFF,LOW);
  digitalWrite(LFF,LOW);
  digitalWrite(RBF,LOW);
  digitalWrite(LBF,LOW);
  digitalWrite(RFF,HIGH);
  digitalWrite(LFF,LOW);
  digitalWrite(RBF,HIGH);
  digitalWrite(LBF,LOW);
  SideCount++;
  Distance =0;
  delay(2200); 
  digitalWrite(RFF,LOW);
  digitalWrite(LFF,LOW);
  digitalWrite(RBF,LOW);
  digitalWrite(LBF,LOW);
  digitalWrite(RFF,LOW);
  }
  else
  {
    DoorSpray();
  }
}

void Spray()
{
  int h = 0;
  for(h=0;h<2;h++)
  {
  for (pos = 0; pos <= 90; pos += 1) 
  { 
    digitalWrite(Relay,HIGH);
    myservo.write(pos);              
    delay(50);
  }
  for (pos = 90; pos >= 0; pos -= 1) 
  { 
    digitalWrite(Relay,HIGH);
    myservo.write(pos);              
    delay(50);                     
  }
  digitalWrite(Relay,LOW);
  }
}

void Setup()
{
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print("welcome message");
   delay(2000);
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print("Number of Sides");
   Sides = GetNum();
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print("Enter Dimensions");
   lcd.setCursor(0,1);
   lcd.print("In Anti-Clockwise");
   delay(4000);
   
   for(i=0;i<Sides;i++)
   {
     int j=i+1;
     lcd.clear();
     lcd.setCursor(0,0);
     lcd.print("Dimension");
     lcd.setCursor(11,0);
     lcd.print(j);
     lcd.setCursor(4,1);
     lcd.print("Press A");
     Dimensions[i] = GetNum();
     delay(1500);
   }
  lcd.clear();
  MinDist();
}

int GetNum()
{
  int choice = 0;
    num = 0;
   while(choice == 0)
    {
     char key = customKeypad.getKey();   
  switch (key)
   {

    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
      Serial.println(key);
      lcd.setCursor(0,1);
      lcd.print(key);
      num = num * 10 + (key - '0');
      break;

    case 'A':
    lcd.clear();
    lcd.print(num);
    return num;
    choice = 1;
    break;  
   }
  }
}

int MinDist()
{ 
  lcd.clear();
  int choice2 = 0;
  while(choice2 == 0)
    {
      digitalWrite(UST1, LOW);
      delayMicroseconds(2);
      digitalWrite(UST1, HIGH);
      delayMicroseconds(10);
      digitalWrite(UST1, LOW);
      int duration1 = pulseIn(USE1, HIGH);
      D1 = duration1/58.2;
      lcd.setCursor(0,0);
      lcd.print(D1);
      delay(1000);
  if(D1 == MinDistance)
  {
    lcd.clear();
    digitalWrite(Buzzer,HIGH);
    delay(1500);
    digitalWrite(Buzzer,LOW);
    choice2 = 1;
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Done Setup");
    delay(1500);
    lcd.clear();
    break;
   
  }
  else if(D1 > MinDistance)
  {
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("Move Closer");
    continue;
  }
  else 
  {
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("Move Away");
    continue;
  }
 }
}

int CheckDoor()
{
  if(DistTravel() == Dimensions[SideCount])
  {
    return 0;//end
  }
  else
  {
    return 1;//door
  }
}

int DistTravel()
{ 
  if(digitalRead(SpeedS) == 1 && SW==1)
  {
    Steps++;
    SW = 0;
    Serial.println("Steps");
    Serial.println(Steps);
    Distance = Steps*1.75;
    return Distance;
    lcd.setCursor(0,0);
    lcd.print(Distance);
  }
  else if(digitalRead(SpeedS) == 0 && SW==0)
  {
    SW =1;
  }

}

void DoorSpray()
{ 
  digitalWrite(RFF,LOW);
  digitalWrite(LFF,LOW);
  digitalWrite(RBF,LOW);
  digitalWrite(LBF,LOW);
  digitalWrite(RFF,HIGH);
  digitalWrite(LFF,HIGH);
  digitalWrite(RBF,HIGH);
  digitalWrite(LBF,HIGH);
  delay(300);
  digitalWrite(RFF,LOW);
  digitalWrite(LFF,LOW);
  digitalWrite(RBF,LOW);
  digitalWrite(LBF,LOW);
  int h = 0;
  for(h=0;h<2;h++)
  {
  for (pos = 75; pos <= 90; pos += 1) 
  { 
    digitalWrite(Relay,HIGH);
    myservo.write(pos);              
    delay(100);
  }
  for (pos = 90; pos >= 75; pos -= 1) 
  { 
    digitalWrite(Relay,HIGH);
    myservo.write(pos);              
    delay(100);                     
  }
  digitalWrite(Relay,LOW);
  }
}
