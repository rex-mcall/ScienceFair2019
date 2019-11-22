
#include <Servo.h>
Servo servo0;
Servo servo1;
Servo servo2;
Servo servo3;

int pos0 = 120;
int pos1 = 60;
int pos2 = 0;
int pos3 = 0;

void setup() {
  servo0.attach(10);  // attaches the servo on pin 9 to the servo object
  servo1.attach(9);  // attaches the servo on pin 9 to the servo object
  servo2.attach(6);  // attaches the servo on pin 9 to the servo object
  servo3.attach(5);  // attaches the servo on pin 9 to the servo object
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  servo0.write(pos0);
  delay(500);
  servo0.write(pos1);
  delay(500);
  Serial.println("hi mr kahler");
}
