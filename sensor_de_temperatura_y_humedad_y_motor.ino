// Sensor 
#include <DHT.h>    // importa la Librerias DHT
#include <DHT_U.h>
int SENSOR = 7;     // 
int TEMPERATURA;
int HUMEDAD;
DHT dht(SENSOR, DHT11); 

// Motor A
int ENA = 10;
int IN1 = 9;
int IN2 = 8;


void setup ()
{
 Serial.begin(9600);   // inicializacion de monitor serial
 dht.begin();      // inicializacion de sensor
 // Declaramos todos los pines como salidas
 pinMode (ENA, OUTPUT);
 pinMode (IN1, OUTPUT);
 pinMode (IN2, OUTPUT);
}
void loop ()
{
  TEMPERATURA = dht.readTemperature();  // obtencion de valor de temperatura
  HUMEDAD = dht.readHumidity();   // obtencion de valor de humedad
  Serial.print("Temperatura: ");  // escritura en monitor serial de los valores
  Serial.print(TEMPERATURA);
  Serial.print("Humedad:");
  Serial.println(HUMEDAD);
  delay(1000);
  if (TEMPERATURA > 25)
  digitalWrite (IN1, HIGH);
  digitalWrite (IN2, LOW);
  analogWrite (ENA, 255); //Velocidad motor A
     
  if (TEMPERATURA <= 25){
  digitalWrite (IN1, LOW);
  digitalWrite (IN2, LOW);
}
}
