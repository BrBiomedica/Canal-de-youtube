#include <ESP8266WiFi.h>
#include "DHT.h"
#define DHTTYPE DHT11  

// Reemplaza con la información de tu red wifi
const char* ssid = "nombre de wifi";
const char* password = "cotraseña";
WiFiServer server(80);

// Sensor DHT
const int DHTPin = 5;  //Comunicación de datos en el pin 5 (GPIO 5 -- D1)

DHT dht(DHTPin, DHTTYPE);

static char celsiusTemp[7];
static char humidityTemp[7];


void setup() {
  Serial.begin(9600);
  delay(10);

  dht.begin();

  // Conectando a la red WiFi
  Serial.println();
  Serial.print("Conectando a ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi conectado");

  // iniciando web
  server.begin();
  Serial.println("Ejecutándose. Esperando a la ESP IP...");
  delay(1000);

  // Mostrar la dirección IP 
  Serial.println(WiFi.localIP());
}

// Esta sección se repetirá continuamente
void loop() {
  // Esperando nuevas conexiones (clientes)
  WiFiClient client = server.available();

  if (client) {
    Serial.println("Reinicio");
    // Boleano para localizar el fin de una solicitud http
    boolean blank_line = true;
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();

        if (c == '\n' && blank_line) {
          float h = dht.readHumidity();
          // Leyendo temperatura 
          float t = dht.readTemperature();
          // Revisión de fallas
          if (isnan(h) || isnan(t) ) {
            Serial.println("Fallos al leer el sensor DHT");
            strcpy(celsiusTemp, "Fallido");
            strcpy(humidityTemp, "Fallido");
          }
          else {
            // Calculando valores de temperatura
            float hic = dht.computeHeatIndex(t, h, false);
            dtostrf(hic, 6, 2, celsiusTemp);
            float hif = dht.computeHeatIndex(h);
            dtostrf(h, 6, 2, humidityTemp);
            Serial.print("Humedad: ");
            Serial.print(h);
            Serial.print(" %\t Temperatura: ");
            Serial.print(t);
            Serial.print(" *C ");
            Serial.print(hic);
            Serial.print(" *C ");
            Serial.print(hif);
            Serial.print(" *F");
            Serial.print("Humidity: ");
            Serial.print(h);
            Serial.print(" %\t Temperature: ");
            Serial.print(t);
            Serial.print(" *C ");
            Serial.print(hic);
            Serial.print(" *C ");
            Serial.print(hif);
            Serial.println(" *F");
          }
          //Maquetación de la página con HTML
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");
          client.println("Connection: close");
          client.println();
          // Código para mostrar la temperatura y humedad en la página
          client.println("<!DOCTYPE HTML>");
          client.println("<html>");
          client.println("<head></head><body><h1>Humedad y temperatura</h1><h3>Temperatura: ");
          client.println(celsiusTemp);
          client.println("C</h3><h3>Humedad: ");
          client.println(humidityTemp);
          client.println("%</h3><h3>");
          client.println("</body>");
          client.print("<meta http-equiv=\"refresh\" content=\"1\">");  //Actualización de la página cada segundo
          client.println("</html>");
          break;
        }
        if (c == '\n') {
          //se empieza a leer una nueva línea
          blank_line = true;
        }
        else if (c != '\r') {
          //encuentra un caracter en la línea actual
          blank_line = false;
        }
      }
    }
    // Cerrando la conexión con el cliente
    delay(1);
    client.stop();
    Serial.println("recargando");
  }
}
