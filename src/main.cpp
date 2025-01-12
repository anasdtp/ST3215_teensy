#include <Arduino.h>

#include <SCServo.h>

SCSCL sc;

int TEST_ID = 0xfe;

//Marche en tx mais pas encore en rx, pourqUOI?

void setup()
{
  Serial.begin(115200);
  Serial1.begin(1000000);
  sc.pSerial = &Serial1;
  delay(1000);
}

void loop()
{
  sc.WritePos(TEST_ID, 1000, 0, 1500);//All servos move at the max speed=1500, move to Position=1000
  delay(500);
  int Pos;
  int Speed;
  int Load;
  int Voltage;
  int Temper;
  int Move;
  if(sc.FeedBack(TEST_ID)!=TEST_ID){
    Pos = sc.ReadPos(TEST_ID);
    Speed = sc.ReadSpeed(TEST_ID);
    Load = sc.ReadLoad(TEST_ID);
    Voltage = sc.ReadVoltage(TEST_ID);
    Temper = sc.ReadTemper(TEST_ID);
    Move = sc.ReadMove(TEST_ID);
    Serial.print("Position:");
    Serial.println(Pos);
    Serial.print("Speed:");
    Serial.println(Speed);
    Serial.print("Load:");
    Serial.println(Load);
    Serial.print("Voltage:");
    Serial.println(Voltage);
    Serial.print("Temper:");
    Serial.println(Temper);
    Serial.print("Move:");
    Serial.println(Move);
    delay(10);
  }else{
    Serial.println("FeedBack err");
    delay(500);
  }
  
  Pos = sc.ReadPos(TEST_ID);
  if(Pos!=TEST_ID){
    Serial.print("Servo position:");
    Serial.println(Pos, DEC);
    delay(10);
  }else{
    Serial.println("read position err");
    delay(500);
  }
  
  Voltage = sc.ReadVoltage(TEST_ID);
  if(Voltage!=TEST_ID){
	  Serial.print("Servo Voltage:");
    Serial.println(Voltage, DEC);
    delay(10);
  }else{
    Serial.println("read Voltage err");
    delay(500);
  }
  
  Temper = sc.ReadTemper(TEST_ID);
  if(Temper!=TEST_ID){
    Serial.print("Servo temperature:");
    Serial.println(Temper, DEC);
    delay(10);
  }else{
    Serial.println("read temperature err");
    delay(500);    
  }

  Speed = sc.ReadSpeed(TEST_ID);
  if(Speed!=TEST_ID){
    Serial.print("Servo Speed:");
    Serial.println(Speed, DEC);
    delay(10);
  }else{
    Serial.println("read Speed err");
    delay(500);    
  }
  
  Load = sc.ReadLoad(TEST_ID);
  if(Load!=TEST_ID){
    Serial.print("Servo Load:");
    Serial.println(Load, DEC);
    delay(10);
  }else{
    Serial.println("read Load err");
    delay(500);    
  }

  Move = sc.ReadMove(TEST_ID);
  if(Move!=TEST_ID){
    Serial.print("Servo Move:");
    Serial.println(Move, DEC);
    delay(10);
  }else{
    Serial.println("read Move err");
    delay(500);    
  }
  Serial.println();
  
  sc.WritePos(TEST_ID, 20, 0, 1500);//All servos move at the max speed=1500, move to Position=20
  delay(500);//[(P1-P0)/V]*1000+100
}
