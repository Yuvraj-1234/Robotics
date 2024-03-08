#include<Servo.h>
Servo s1;
void setup() {
  // put your setup code here, to run once:
  s1.attach(8);
  s1.write(0);
  delay(2000);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i <= 180; i += 1) {
    s1.write(i);
    delay(15);
  }
  for (int i = 180; i >= 0; i -= 1) {
    s1.write(i);
    delay(15);
  }
  delay(10);
}
