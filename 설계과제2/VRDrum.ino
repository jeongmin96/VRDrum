#include <AcceleroMMA7361.h>
#include <Wire.h>
#include <MMA_7455.h>
#define N 10
AcceleroMMA7361 accelSensor;
MMA_7455 tiltSensor = MMA_7455();
int tiltZ; //tilt Z-axis
int acZ; //accel Z-axis
int piezo;
char buf[3];

void setup() 
{
  Serial.begin(19200);
  delay(500);
  pinMode(A3,INPUT);
  tiltSensor.initSensitivity(2); //민감도 설정
  accelSensor.begin(13, 12, 11, 10, A0, A1, A2); //핀설정 sleepPin, selfTestPin, zeroGPin, gSelectPin, X, Y, Z 순
  accelSensor.setARefVoltage(5); //AREF 전압
  accelSensor.setSensitivity(LOW); // +/-6G 감도설정 (HIGH는 1.5G)
  accelSensor.calibrate(); // 초기값 보정함수 (초기값은 지면과 수평하게 놓을 것)
}

int MovingAverage(int new) {
    static int backup[N]={0};
    static int pivot=0;
    static bool first=true;
    int i=0;
    int sum=0;
    backup[pivot++]=new;
    if(pivot==N) {
        if(first) first=false;
        pivot=0;
    }
    for(i=0; i<((first)?pivot:N); i++) {
        sum+=backup[i];
    }
    return sum/((first)?pivot:N);
}

void loop() 
{
  if(Serial.availableForWrite()<10) return;
  
  //read Sensor Values
  acZ = accelSensor.getZRaw();   // accel Sensor
  piezo=analogRead(A3);
  tiltZ = MovingAverage(tiltSensor.readAxis('z')); //tilt sensor

    //print tilt and accel values
  if(acZ<0) acZ=0;
  Serial.print(acZ,HEX);
  Serial.print("\t");
  
  if(piezo>255) piezo=255;
  Serial.print(piezo,HEX);
  Serial.print("\t");
  /*  if(tiltZ< -9) Serial.println("open");
    else if(tiltZ>=-9 && tiltZ< 4) Serial.println("3/4 open");
    else if(tiltZ>= 4 && tiltZ<16) Serial.println("half");
    else if(tiltZ>=16 && tiltZ<29) Serial.println("1/4 open");
    else Serial.print("close");
    Serial.print(tiltZ,DEC);*/
  if(tiltZ>127) tiltZ=127;
  sprintf(buf, "%02x", tiltZ);
  Serial.println(buf);

  delay(10);
 }