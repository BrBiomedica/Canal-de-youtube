#include <Arduino.h>
#define ACCION_ENCENDER 97 // La letra a
#define ACCION_APAGAR 98   // La letra b
#define LED_FOCO_HABITACION 2

void setup()
{
  Serial.begin(9600);
  pinMode(LED_FOCO_HABITACION, OUTPUT);
}

void loop()
{
  if (Serial.available())
  {
    int accion = Serial.read();
    if (accion == ACCION_ENCENDER)
    {
      digitalWrite(LED_FOCO_HABITACION, HIGH);
    }
    else if (accion == ACCION_APAGAR)
    {
      digitalWrite(LED_FOCO_HABITACION, LOW);
    }
  }
}
