#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

const int trig = 11;
const int echo = 12;

void setup() {
  // put your setup code here, to run once:
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
  lcd.begin();

  // Turn on the blacklight and print a message.
  lcd.backlight();
}
float time,distance;

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trig,LOW);
  delayMicroseconds(3);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  
  time = pulseIn(echo, HIGH);
  distance = (time*0.0343)/2;
  Serial.print("Distance: Cm");
  Serial.println(distance);
  lcd.setCursor(0,0);
  lcd.print("Distance(in cm): ");
  lcd.setCursor(0,1);
  lcd.print(distance);
  delay(1000);
  lcd.clear();
}
