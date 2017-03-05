#include <AcceleroMMA7361.h>
#include <Wire.h>
#include <MMA_7455.h>

AcceleroMMA7361 accelero;
MMA_7455 tiltSensor = MMA_7455();
char tiltZ; //tilt Z-axis
int acZ; //accel Z-axis

void setup() 
{
  Serial.begin(19200);
  delay(500);
  pinMode(A3,INPUT);
  tiltSensor.initSensitivity(2); //민감도 설정
  accelero.begin(13, 12, 11, 10, A0, A1, A2); //핀설정 sleepPin, selfTestPin, zeroGPin, gSelectPin, X, Y, Z 순
  accelero.setARefVoltage(5); //AREF 전압
  accelero.setSensitivity(LOW); // +/-6G 감도설정 (HIGH는 1.5G)
  accelero.calibrate(); // 초기값 보정함수 (초기값은 지면과 수평하게 놓을 것)
}

void loop() 
{
  if(Serial.availableForWrite()<20) {
     Serial.end(); return;}

    //read Sensor Values
  acZ = accelero.getZRaw();   // accel Sensor
  tiltZ = tiltSensor.readAxis('z'); //tilt sensor
   
    //print tilt and accel values
  Serial.print(acZ,HEX);
  Serial.print("\t");
  Serial.print(tiltZ,HEX);
  Serial.print("\t");
/*  if(tiltZ< -9) Serial.println("open");
  else if(tiltZ>=-9 && tiltZ< 4) Serial.println("3/4 open");
  else if(tiltZ>= 4 && tiltZ<16) Serial.println("half");
  else if(tiltZ>=16 && tiltZ<29) Serial.println("1/4 open");
  else Serial.print("close");
  Serial.print(tiltZ,DEC);*/

  //ac \t tilt \t 순으로 출력, tilt는 5ms단위로 값을 읽어서 20개를 MAver한다.

    //read and print piezoSensor
  Serial.println(analogRead(A3),HEX);
  //Serial.flush();
  delay(10);
 }