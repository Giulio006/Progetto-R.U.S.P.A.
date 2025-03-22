#include <Servo.h>

Servo s1;

void setup() {
  // put your setup code here, to run once:
  s1.attach(2);
  Serial.begin(9600);
}

void loop() {
  for(int cont=0; cont<180; cont++){
  s1.write(cont);
  delay(10);
  }
  for(int cont=180; cont>0; cont--){
    s1.write(cont);
    delay(10);
  }
}
