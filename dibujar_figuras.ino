#define __DEBUG__
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 display(128, 64, &Wire, -1);

void setup() {
#ifdef __DEBUG__
  Serial.begin(9600);
  delay(100);
  Serial.println("Iniciando pantalla OLED");
#endif

  // Iniciar pantalla OLED en la dirección 0x3C
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
#ifdef __DEBUG__
    Serial.println("No se encuentra la pantalla OLED");
#endif
    while (true);
  }

  // Limpir buffer
  display.clearDisplay();
  // Dibujar línea horizontal
  display.drawLine(0, 18, display.width(), 18, SSD1306_WHITE);
  // Dibujar línea vertical
  display.drawLine(63, 0, 63, display.height(), SSD1306_WHITE);
  // Enviar a pantalla
  display.display();
  delay(10000);

  // Limpir buffer
  display.clearDisplay();
  // Dibujar un rectángulo
  display.drawRect(10, 18, 20, 28, SSD1306_WHITE);
  // Enviar a pantalla
  display.display();
  delay(5000);
  // Rellenar rectángulo
  display.fillRect(10, 18, 20, 28, SSD1306_WHITE);
  // Enviar a pantalla
  display.display();
  delay(5000);

  // Limpir buffer
  display.clearDisplay();
  // Dibujar un ciículor
  display.drawCircle(64, 32, 10, SSD1306_WHITE);
  // Enviar a pantalla
  display.display();
  delay(5000);
  // Rellenar cículo
  display.fillCircle(64, 32, 10, SSD1306_WHITE);
  // Enviar a pantalla
  display.display();
  delay(5000);

  // Limpir buffer
  display.clearDisplay();
  // Dibujar un rectángulo redondeado
  display.drawRoundRect(10, 18, 20, 28, 5, SSD1306_WHITE);
  // Enviar a pantalla
  display.display();
  delay(5000);
  // Rellenar rectángulo redondeado
  display.fillRoundRect(10, 18, 20, 28, 5, SSD1306_WHITE);
  // Enviar a pantalla
  display.display();
  delay(5000);

  // Limpir buffer
  display.clearDisplay();
  // Dibujar un rectángulo redondeado
  display.drawTriangle(10, 18, 50, 18, 30, 58, SSD1306_WHITE);
  // Enviar a pantalla
  display.display();
  delay(5000);
  // Rellenar rectángulo redondeado
  display.fillTriangle(10, 18, 50, 18, 30, 58, SSD1306_WHITE);
  // Enviar a pantalla
  display.display();
  delay(5000);
}

void loop() {}
