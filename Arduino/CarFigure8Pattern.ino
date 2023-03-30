#include <Servo.h>

// Create Servo objects for each servo
Servo steeringServo;
Servo throttleServo;

void setup() {
  // Attach the servos to the PWM pins
  steeringServo.attach(9);
  throttleServo.attach(10);
}

void loop() {
  // Move the RC car in a figure 8 pattern continuously
  while (true) {
    // Move the RC car in the first half of the figure 8 pattern
    for (int i = 0; i < 2; i++) {
      // Set the steering angle to turn left
      steeringServo.write(0);

      // Set the throttle to move forward
      throttleServo.write(180);

      delay(2000); // Wait for 2 seconds

      // Set the steering angle to turn right
      steeringServo.write(180);

      // Set the throttle to move forward
      throttleServo.write(180);

      delay(2000); // Wait for 2 seconds
    }

    // Move the RC car in the second half of the figure 8 pattern
    for (int i = 0; i < 2; i++) {
      // Set the steering angle to turn right
      steeringServo.write(180);

      // Set the throttle to move forward
      throttleServo.write(180);

      delay(2000); // Wait for 2 seconds

      // Set the steering angle to turn left
      steeringServo.write(0);

      // Set the throttle to move forward
      throttleServo.write(180);

      delay(2000); // Wait for 2 seconds
    }
  }
}
