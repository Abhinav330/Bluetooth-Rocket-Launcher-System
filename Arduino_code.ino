#include <Servo.h>

int pos1 = 90;
int pos2 = 50;

Servo s1;  //servo for moving left and rigth.
Servo s2;  // servo for moving up and down
 int s;
void setup() {
  Serial.begin(9600); // for turning on serial monitor.
  s1.attach(9); // connecting servo1 to pin 3
  s2.attach(5); // connecting servo2 to pin 5
  pinMode(2, OUTPUT); //connecting relay module with pin 2.
  s1.write(pos1);
  s2.write(pos2);
}

void loop() {
 
 if (Serial.available() > 0) {
    s = Serial.read();
    
 }
//    Serial.println(s);
  
  if (s == 1) {
  
    if (pos1 <= 175) {
      for (int i = 1; i <=5; i++) {
        s1.write(pos1+i);
        delay(60);
      }
      pos1+=5;
      Serial.print("Servo1 is at = "); Serial.println(pos1);
    }
    }
  
  else if (s == 2) {
    if (pos1 >= 5) {
      for (int i = 1; i <= 5; i++) {
        s1.write(pos1-i);
        delay(60);
      }
      pos1 -=5;
      Serial.print("Servo1 is at = "); Serial.println(pos1);
    }
  }
  
  else if (s == 3) {
    if (pos2 <= 95) {
      
      for (int i = 1; i <=5; i++) {
        s2.write(pos2+i);
        delay(60);
      }
      pos2+=5;
      Serial.print("Servo2 is at = "); Serial.println(pos2);
    }
  }

  else if (s == 4) {

    if (pos2 >= 10) {
      for (int i = 1; i <= 5; i++) {
        s2.write(pos2-i);
        delay(75);
      }
      pos2 -=5;
      Serial.print("Servo2 is at = "); Serial.println(pos2);
    }
  }
  else if (s == 5) {
    digitalWrite(2, HIGH);
    delay(5000);
    digitalWrite(2, LOW);
  }
s = -1;
}
