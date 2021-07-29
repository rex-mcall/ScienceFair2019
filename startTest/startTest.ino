  #include<Servo.h>
  Servo servo1;
  Servo servo2;
  Servo servo3;
  Servo servo4;
  Servo fan;
  int pos0 = 1000;
  int pos1 = 1500;
  int pos2 = 2000;
  int DELAY = 1000;
  int del1 = 350;
  int adj1 = -33;
  void set1(int a)
  {
    servo1.write(a + adj1);
  }
  int adj2 = -63;
  void set2(int a)
  {
    servo2.write(a + adj2);
  }
  int adj3 = 33;
  void set3(int a)
  {
    servo3.write(a + adj3);
  }
  int adj4 = -116;
  void set4(int a)
  {
    servo4.write(a + adj4);
  }
  void allSet(int a)
  {
    set1(a);
    set2(a);
    set3(a);
    set4(a);
  }
  void xSet(int a)
  {
    set1(1500 + a);
    set2(1500 -a);  
  }
  void ySet(int a)
  {
    set3(1500 + a);
    set4(1500 - a);  
  }
  void ex()
  {
    xSet(500);
    delay(del1);
    set4(1150);
    delay(del1);
    set4(1850);
    delay(del1);
    set4(1500);
    delay(del1);
    xSet(-500);
    delay(del1);
    set3(1150);
    delay(del1);
    set3(1850);
    delay(del1);
    set3(1500);
    xSet(0);
  }
  void why()
  {
    ySet(500);
    delay(del1);
    set1(1150);
    delay(del1);
    set1(1850);
    delay(del1);
    set1(1500);
    delay(del1);
    ySet(-500);
    delay(del1);
    set2(1150);
    delay(del1);
    set2(1850);
    delay(del1);
    set2(1500);
    ySet(0);
  }
  void fullTest()
  {
    allSet(1100);
    delay(DELAY);
    allSet(1900);
    delay(DELAY);
    allSet(1500);
    delay(DELAY);
    ex();
    why();
  }
  void setup() {
    // put your setup code here, to run once:
    servo1.attach(10);
    servo2.attach(9);
    servo3.attach(6);
    servo4.attach(5);
    fan.attach(3);
    fan.write(1000);
    Serial.begin(9600);
    delay(2000);
    Serial.println("Setting all to midpoint...");
    delay(500);
    
    allSet(1500);
    Serial.println("Set.");
    Serial.println("Waiting 2.5 seconds...");
    delay(2500);
    Serial.println("Performing full control surface test");
    delay(500);
    fullTest();
    Serial.println("Done.");
    Serial.println("Perparing for throttle up to 20% power");
    for(int i = 19; i >= 0; i--)
    {
      Serial.println(i);
      delay(1000);
    }
    Serial.println("Performing throttle up to 20% power for 5 seconds");
    fan.write(1200);
    for(int i = 4; i >= 0; i--)
    {
      Serial.println(i);
      delay(1000);
    }
    double currentFanVal;
    Serial.println("Throttling down...");
    for(int i = 5; i > 0; i--)
    {
      currentFanVal = fan.read();
      currentFanVal -= 3.6;
      fan.write(currentFanVal);
      Serial.println(i);
      delay(500);
    }
    fan.write(1000);
    Serial.println("Fan powered down. Ending program.");
    Serial.println("----------------------------------");
    Serial.println("Thank you for watching this demo!");
    Serial.println("----------------------------------");
    
  }
  
  void loop() {
    // put your main code here, to run repeatedly:
  
  }
