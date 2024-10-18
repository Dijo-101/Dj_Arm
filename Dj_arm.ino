//Here is the code for my project
#include <Servo.h>

int pot_pin_claw = A0;
int pot_pin_bottom = A1;
int pot_pin_joint1 = A2;
int pot_pin_joint2 = A3;
int value_claw;
int value_bottom;
int value_joint1;
int value_joint2;
Servo servo_claw;
Servo servo_bottom;
Servo servo_joint1;
Servo servo_joint2;
void setup() {
  servo_claw.attach(2);
  servo_bottom.attach(3);
  servo_joint1.attach(4);
  servo_joint2.attach(5);
  Serial.begin(9600);
}
void loop() {
  int pot_inputs[4];
  pot_inputs[0] = analogRead(pot_pin_claw);
  pot_inputs[1] = analogRead(pot_pin_bottom);
  pot_inputs[2] = analogRead(pot_pin_joint1);
  pot_inputs[3] = analogRead(pot_pin_joint2);
  value_claw = (pot_inputs[0] > 100) ? 1 : 0;
  value_bottom = map(pot_inputs[1], 500, 900, 10, 170);
  value_joint1 = map(pot_inputs[2], 500, 900, 10, 170);
  value_joint2 = map(pot_inputs[3], 500, 900, 10, 170);
  if (value_claw) {
    servo_claw.write(120);
  } else {
    servo_claw.write(180);
  }
  servo_bottom.write(value_bottom);
  servo_joint1.write(value_joint1);
  servo_joint2.write(value_joint2);
  delay(20);
}
