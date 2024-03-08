void setup(){
  pinMode(10, INPUT);
  pinMode(13, OUTPUT);
}
void loop(){
  if(digitalRead(10)==LOW){
    digitalWrite(13,HIGH);
    delay(10);
  }
  else{
    digitalWrite(13, LOW);
    delay(10);
  }
}
