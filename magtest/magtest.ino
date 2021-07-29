  #include <Wire.h>
  #include <Adafruit_Sensor.h>
  #include <Adafruit_HMC5883_U.h>
  
  Adafruit_HMC5883_Unified mag = Adafruit_HMC5883_Unified(12345);
  const int trigPin = 10;
  const int echoPin = 9;

  double duration;
  double distance;

  void ultrasonicDist()
  {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(echoPin, HIGH);
    // Calculating the distance
    distance= duration/2/74.0524781;
    // Prints the distance on the Serial Monitor
    Serial.print("Distance (inches): ");
    Serial.println(distance);
  }
  void magAngle()
  {
      sensors_event_t event; 
  mag.getEvent(&event);
 float declinationAngle = -0.195;
  
  float heading = atan2(event.magnetic.y, event.magnetic.x);
  heading += declinationAngle;
  if(heading < 0)
    heading += 2*PI;
    
  // Check for wrap due to addition of declination.
  
   
  // Convert radians to degrees for readability.
  float headingDegrees = heading * 180/M_PI; 
  
  Serial.print("Heading (degrees): "); Serial.println(headingDegrees);
  }
  void setup() {
  Serial.begin(9600);
  
  mag.begin();
  sensor_t sensor;
  mag.getSensor(&sensor);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  
  }
  
  void loop() {
  ultrasonicDist();
  magAngle();
  Serial.println("--------------------------");
  delay(500);
  }
