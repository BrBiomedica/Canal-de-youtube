#include <SoftwareSerial.h> // Libreria de manejo de comunicacion serial alterna

const int RX_1 = 4; // Pin de UART virtual RX del NODO 1 conectado al pin TX del NODO 2
const int TX_1 = 3; // Pin de UART virtual TX del NODO 1 conectado al pin RX del NODO 2
int POT = 0;        // Variable de almacenamiento del valor leido del potenciometro del NODO 2

SoftwareSerial Serialvirt(RX_1, TX_1); // Declaracion de pines usados para comunicacion con el NODO 2
// y el nombre del puerto virtual

void setup() {
  Serial.begin(9600);     // Velocidad de comunicacion con la PC
  Serialvirt.begin(9600); // Velocidad de comunicacion del NODO 2
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  // Mensaje inicial en el Monitor Serial
  Serial.println("Los valores del potenciometro se observan de 0 a 100% ");
  Serial.println("Esperar...");
  delay(100);
}

void loop() {
  if (Serialvirt.available()) { // Verificacion que el puerto serial virtual recibe datos
    delay(10);

    lectura_pot(); // Rutina de lectura del potenciometro
    delay(100);    // Tiempo de demora para siguiente lectura de puerto
  }
}

void lectura_pot() {       // RUTINA DE LECTURA DE DATOS DEL POTENCIOMETRO
  POT = Serialvirt.read(); // Lectura del valor del potenciometro del NODO 2

  // Mensaje de muestra del porcentaje del voltaje leido del potenciometro
  Serial.print("Porcentaje de voltaje: ");
  Serial.print(POT);
  Serial.println(" %");
  if (POT >= 1) {
    digitalWrite(5, HIGH);
  }
  else {
    digitalWrite(5, LOW);
  }
  if (POT >= 33) {
    digitalWrite(6, HIGH);
  }
  else {
    digitalWrite(6, LOW);
  }
  if (POT >= 66) {
    digitalWrite(7, HIGH);
  }
  else {
    digitalWrite(7, LOW);
  }
}
