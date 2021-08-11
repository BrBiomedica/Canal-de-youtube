#include <Servo.h>

Servo servoMotor;

void setup() {
  Serial.begin(9600);
  servoMotor.attach(9);
}

void loop() {
  
  // Desplazamos a la posición 0º
  servoMotor.write(1);
  delay(1000);
  
  // Desplazamos a la posición 180º
  servoMotor.write(180);
  delay(1000);
  
  // Desplazamos a la posición 180º
  servoMotor.write(180);
  delay(1000);
}
