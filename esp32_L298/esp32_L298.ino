// connect motor controller pins to Arduino digital pins
// motor one
#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial walle;
int enA = 22;
int enB = 18;
int in1 = 14;
int in2 = 23;
// motor two
int in3 = 21;
int in4 = 19;

char receivedChar;
void setup()
{
  // set all the motor control pins to outputs
  Serial.begin(115200);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  walle.begin("MY ROBOT CAR");

  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}

void loop()
{
  if(walle.available()){
    receivedChar = walle.read();
    Serial.println(receivedChar);
    if(receivedChar == 'F'){
      Forward();
    }
    else if(receivedChar=='B'){
      BackWard();
    }
    else if(receivedChar=='R'){
      Right();
    }
    else if(receivedChar=='L'){
      Left();
    }
    else if(receivedChar=='G'){
      Left_Forward();
    }
    else if(receivedChar=='I'){
      RIGHT_Forward();
    }
    else if(receivedChar=='H'){
      LEFT_BACKWARD();
    }
    else if(receivedChar=='J'){
      RIGHT_BACKWARD();
    }
    else if(receivedChar=='S'){
      stop();
    }
  }
  
}
void Forward()
{
  // this function will run the motors in both directions at a fixed speed
  // turn on motor A
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  // set speed to 200 out of possible range 0~255
  analogWrite(enA, 200);
  analogWrite(enB,200);
  // turn on motor B
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  // set speed to 200 out of possible range 0~255
  // analogWrite(enB, 200);
  // now change motor directions
}
void BackWard(){
  analogWrite(enA,200);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);  
  analogWrite(enB, 200);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH); 
}
void Right(){
  analogWrite(enA,200);
  digitalWrite(in1,HIGH);
  analogWrite(enB,200);
  digitalWrite(in4,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
}  
void Left(){
  analogWrite(enA,200);
  digitalWrite(in1,LOW);
  analogWrite(enB,200);
  digitalWrite(in4,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,HIGH);
}
void Left_Forward(){
  analogWrite(enA,200);
  analogWrite(enB,140);
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
}
void RIGHT_Forward(){
  analogWrite(enA,140);
  analogWrite(enB,200);
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
}
  // now turn off motors
void RIGHT_BACKWARD(){
  analogWrite(enA,0);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);  
  analogWrite(enB, 200);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH); 
}
void LEFT_BACKWARD(){
  analogWrite(enA,200);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);  
  analogWrite(enB, 0);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH); 
}
void stop(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);  
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enA,0);
  analogWrite(enB,0);
} 
