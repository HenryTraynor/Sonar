#include <Servo.h>


const int trigPin = 4;
const int echoPin = 6;

long duration;
int distance;
Servo myServo;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  myServo.attach(2); 
}

void loop() {
  // rotates the servo motor from 15 to 165 degrees
  for(int i=15;i<=165;i++){  
    myServo.write(i);
    delay(30);
    distance = calculateDistance();
  
    myServo.write(i);
    delay(30);
    Serial.print(i); // 
    Serial.print(","); // Sends addition character right next to the previous value needed later in the Processing IDE for indexing
    Serial.print(distance);
    Serial.print("."); // Sends addition character right next to the previous value needed later in the Processing IDE for indexing
  }
  
  
  for(int i=165;i>15;i--){  
    distance = calculateDistance();
    Serial.print(i);
    Serial.print(",");
    Serial.print(distance);
    Serial.print(".");
  }
}

int calculateDistance(){ 
  pinMode(trigPin, OUTPUT);
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(5);
  digitalWrite(trigPin, LOW);
  pinMode(trigPin, INPUT);
  
  duration = pulseIn(echoPin, HIGH);
  distance= duration/29/2;
  return distance;
}
