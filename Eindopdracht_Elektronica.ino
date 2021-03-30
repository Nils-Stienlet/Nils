#include <Servo.h>
#include <LiquidCrystal.h>
#include <NewPing.h>    
#define trigPin 12  
#define echoPin 13  
#define MAX_DISTANCE 500

NewPing sonar(trigPin, echoPin, MAX_DISTANCE); 
LiquidCrystal lcd(9,8,7,6,5,4);

int val = 0;
int potPin = A0;
int greenLed = 2; 
int redLed = 3; 
int potPin1 = A1;

int pos = 20;
Servo myservo;

void setup() {

lcd.begin(16,2);
  
  Serial.begin (115200);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(redLed, OUTPUT);
 

 
  myservo.attach(11);  
}
void loop() {
  
  val = analogRead(potPin);
  int duration, distance, pos = 0, i;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);  
  distance = (duration / 2) / 29.1;

  lcd.setCursor(0,0);
  lcd.print("Range: ");
  lcd.print(distance);
  lcd.println(" cm");

  if (distance <= map(analogRead(A1), 0, 1023,0, 70))       
  {
    digitalWrite(greenLed, LOW); 
    digitalWrite(redLed, HIGH);  
    myservo.write(180);
    delay(val);
    digitalWrite(redLed, LOW);
    myservo.write(90);
    delay(val);
    digitalWrite(redLed, HIGH);
    myservo.write(0);
    delay(val);
    digitalWrite(redLed, LOW);
    myservo.write(90);
  }
  else { 
    digitalWrite(redLed, LOW); 
    digitalWrite(greenLed, HIGH);
    myservo.write(90);
  }

  delay(val);
}
