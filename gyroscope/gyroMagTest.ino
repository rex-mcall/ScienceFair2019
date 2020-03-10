#include<PID_v1.h>
#include<Wire.h>
#include<Servo.h>
int pos = 90;
Servo servo;
const int MPU_addr=0x68;
int16_t AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ;
double Setpoint, Input, Output;
PID myPID(&Input, &Output, &Setpoint,2,5,1, DIRECT);
int minVal=265;
int maxVal=402;

double x;
double y;
double z;
 


void setup(){
  servo.attach(10);
  Wire.begin();
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);
  Serial.begin(9600);
  Input = y;
  Setpoint = 90;
  myPID.SetOutputLimits(-22.5, 22.5);
  myPID.SetMode(AUTOMATIC);
  myPID.SetSampleTime(5);
}
void loop(){
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_addr,14,true);
  AcX=Wire.read()<<8|Wire.read();
  AcY=Wire.read()<<8|Wire.read();
  AcZ=Wire.read()<<8|Wire.read();
    int xAng = map(AcX,minVal,maxVal,-90,90);
    int yAng = map(AcY,minVal,maxVal,-90,90);
    int zAng = map(AcZ,minVal,maxVal,-90,90);

       x= RAD_TO_DEG * (atan2(-yAng, -zAng)+PI);
       y= RAD_TO_DEG * (atan2(-xAng, -zAng)+PI);
       z= RAD_TO_DEG * (atan2(-yAng, -xAng)+PI);

     Serial.print("AngleX= ");
     Serial.println(x);

     Serial.print("AngleY= ");
     Serial.println(y);

     Serial.print("AngleZ= ");
     Serial.println(z);
     Serial.println("-----------------------------------------");
     /*
     if(y <= 180)
     {
      pos = y;
     }
     else
     {
      pos = y - 180;
      pos = 180 - y;
     }
     */
     if(y >180)
     {
      y = y/2;
      y = 0 - y;
     }
     //myPID.Compute();
     //pos = 90 + Output;
     pos = y / 4;
     pos = 90 + pos;
     servo.write(pos);
     
}
