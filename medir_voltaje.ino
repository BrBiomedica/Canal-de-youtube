#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

void setup() {

  
  // Set up the display
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); 
  display.setTextColor(WHITE);

 
}
void loop(){

   // draw scrolling text
  delay(1);
  display.clearDisplay();

  // text display tests
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("VOLTAJE");
 
  display.setTextColor(WHITE);
  display.println();
  display.setTextSize(2);
  display.setTextSize(2);
  int sensorValue = analogRead(A0);
  float voltaje = sensorValue * (5.0 / 1023.0);
  display.print(voltaje); 
  display.println("V");
  display.display();

}
