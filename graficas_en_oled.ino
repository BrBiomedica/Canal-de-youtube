#include <Wire.h>      // libreria para bus I2C
#include <Adafruit_GFX.h>   // libreria para pantallas graficas
#include <Adafruit_SSD1306.h>   // libreria para controlador SSD1306

#define OLED_RESET 4      // necesario por la libreria pero no usado
Adafruit_SSD1306 oled(128, 64, &Wire, OLED_RESET);  // crea objeto
int anteriorMillis = 0;
int tiempo = 0;
float valorAnalogico = 0;
float voltaje = 0;
float graficaVoltaje = 0;

int x[128]; //buffer de la grafica 
int y[128]; //buffer secundario de la grafica 
void setup() {
  oled.begin(SSD1306_SWITCHCAPVCC, 0x3C); // inicializa pantalla con direccion 0x3C
}
 
void loop() {
  oled.clearDisplay(); //limpia el buffer del display
  //dibuja eje X y Y 
  oled.drawLine(0, 53, 127, 53, WHITE);
  oled.drawLine(25, 53, 25, 0, WHITE);
  valorAnalogico = analogRead(A0); //lee el valor analogico del pin A0
  voltaje=(valorAnalogico*5)/1024; //calcula el valor en voltaje
  graficaVoltaje=map(valorAnalogico,0,1023,53,0); //escala el valor analogico a un pixel imprimible en pantalla

  x[127]=graficaVoltaje; //asigna el valor escalado a el ultimo dato de la matriz
  
  for(int i=127;i>=25;i--){ 
      oled.drawPixel(i, x[i], WHITE); //dibuja punto a punto el contenido de x
      y[i-1]=x[i]; //guarda la informacion desplazada una posicion temporalmente en y
    }
  oled.display(); //despliega la informacion del buffer en la pantalla
  for(int i=127;i>=0;i--){
    x[i]=y[i]; //envia los datos desplazados de vuelta a la variable x
  }
}
