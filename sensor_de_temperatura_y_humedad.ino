#include <DHT.h>    // importa la Librerias DHT
#include <DHT_U.h>
#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int SENSOR = 7;     // pin DATA de DHT22 a pin digital 7
int TEMPERATURA;
int HUMEDAD;

DHT dht(SENSOR, DHT11);   // por DHT11 
void setup(){
  Serial.begin(9600);   // inicializacion de monitor serial
  dht.begin();      // inicializacion de sensor
  lcd.begin(16, 2);
}

void loop(){
  TEMPERATURA = dht.readTemperature();  // obtencion de valor de temperatura
  HUMEDAD = dht.readHumidity();   // obtencion de valor de humedad
  lcd.clear();
  lcd.print("Temperatura: ");  // escritura en monitor serial de los valores
  lcd.print(TEMPERATURA);
  lcd.setCursor(0, 1);
  lcd.print("Humedad:");
  lcd.println(HUMEDAD);
  delay(1000);
}
