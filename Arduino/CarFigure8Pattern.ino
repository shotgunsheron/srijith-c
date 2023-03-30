#include <Servo.h>

Servo steeringServo;
Servo throttleServo;

void setup() {
  
  steeringServo.attach(9);
  throttleServo.attach(10);
  
  
}

void loop() {
  while (true) {
    for (int i = 0; i < 2; i++) {
      steeringServo.write(0);

      throttleServo.write(180);

      delay(2000);
      steeringServo.write(180);
      throttleServo.write(180);

      delay(2000); 
    }

    for (int i = 0; i < 2; i++) {
      steeringServo.write(180);
      throttleServo.write(180);
      delay(2000); 
      steeringServo.write(0);
      throttleServo.write(180);
      delay(2000); 
    }
  }
}
