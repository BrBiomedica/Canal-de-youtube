#include <SPI.h>
#include <WString.h>
#include <Ethernet.h>

byte mac[]= {0x90, 0xA2, 0xDA, 0x0D, 0x4F, 0x6C};//direccion MAC de tu Ethernet 
byte ip[]= {192, 168, 1, 72};// ip que le pones a tu red como fija y configurar en tu router

EthernetServer server(80);

int dig[] = {2, 3, 4, 5, 6, 7, 8,9};// pines digitales a usar. No uso 0 y 1 que son transmision de serie

// Tampoco uso el 10,11,12 y 13 ya que los uso para la ethernet
int digTotal =8; //Numero de pines a usar 
int vdig[]= {0, 0, 0, 0, 0, 0, 0, 0};//valores iniciales(tanto pines usemos)
int pin;
int nivel;
String cad = String(100);

void setup() 
{
  Ethernet.begin(mac, ip);//inicio la Ethernet
  server.begin();//inicio el servidor
  Serial.begin(9600);//inicio el serial monitor
  for (int i = 0; i < digTotal; i++)
  {
    pinMode(dig[i], OUTPUT);//inicializo los pines digitales como salida 
    digitalWrite(dig[i], vdig[i]);//Los pongo a nivel bajo LOW= 0
   }
}

void loop() 
{
  cad = ""; // inicializando la cad donde almaceno los datos recibidos
  EthernetClient cliente = server.available();
  if (cliente)
  {
    while (cliente.connected())
    {
      if (cliente.available())
      {
        char c = cliente.read();
        cad = cad + c;
        Serial.print(c);
        if (c == '\n')
        {
          if (cad.lastIndexOf("dig") > -1)//Si la variable cad contiene 'dig' hacer...
          {
            pin = pinElegido(cad);
            int posicionPin;
            for (int i = 0; i < digTotal; i++)
            {
              if(dig[i] ==pin)
              {
                posicionPin =i;
                break;
              }
            }
            nivel = nivelElegido(cad);
            vdig[posicionPin] = nivel;
            Serial.print(pin);//comprobamos que el pin eligido
            Serial.print("pin. -- ");
            Serial.print(nivel);
            Serial.print(" nivel ");
            digitalWrite(pin, nivel);
            }//... hasta aqui 'dig'
            if (cad.lastIndexOf("apaga")> -1)
            {//la funcion apaga todos
              apagaTodos();
            }
            if (cad.lastIndexOf("encender") > -1)
            {//la funcion enciendeTodos()
             enciendeTodos();
            }
            // Comienza la transmision de datos
            cliente.println("HTTP/1.1 200 OK");
            cliente.println("Content-Type: text/html");
            cliente.println();
            for (int i = 0; i < digTotal; i++)
            {
              cliente.print("Digital ");
              cliente.print(dig[i]);
              cliente.print(" ");
              if (vdig[i] == 1)
              {
                cliente.println("<font color='green'>ON</font>");
                cliente.print("<form method=get><input type=hidden name=dig");
                cliente.print(dig[i]);
                cliente.print(" value=0><input type=submit value=OFF></form>");
               }
               if (vdig[i] == 0)
               {
                cliente.println("<font color='grey'>OFF</font>");
                // cliente.println("<td>");
                cliente.print("<form method=get>");
                cliente.print("<input type=hidden name=dig");
                cliente.print(dig[i]);
                cliente.print(" value=1>");
                cliente.print("<input type=submit value=ON>");
                cliente.print("</form>");
               }
              }
              cliente.print("<form method=get><input type=hidden name=apaga");
              cliente.print(" value=1><input type=submit value=APAGA_TODOS></form>");
              cliente.print("<form method=get><input type=hidden name=encender");
              cliente.print(" value=1><input type=submit value=ENCENDER_TODOS></form>");
              cliente.stop();
             }    
            }
           }
          }
         }
 
 //////////FUNCIONES////////////
 //// Funcion: Extrae el pin del array cad (contiene la lectura de lo que el cliente devuelve)
 int pinElegido(String cad)
 {
  int pos_dig = cad.lastIndexOf("dig");
  int pos_igual = cad.lastIndexOf("=");
  char vpin1 = cad.charAt(pos_dig + 3);
  char vpin2 = cad.charAt(pos_dig + 4);
  if (vpin2 != '=')
  {
    vpin1 += vpin2;
   }
   int pinElegido = vpin1 - 48; //toInt();
   return pinElegido;
 }

 // Funcion: Extrae en nivel de la cadena cad
 int nivelElegido(String cad)
 {
  int pos_igual = cad.lastIndexOf("=");
  char v = cad.charAt(pos_igual +1)- 48;
  if (v == 0) return 0;
  if (v == 1) return 1;
  }

  //Funcion para apagar todos los leds al tiempo
  void apagaTodos()
  {
    for (int i = 0; i < digTotal; i ++)
    {
      vdig[i] =0;
      digitalWrite(dig[i], vdig[i]);
    }
  }

  //Funcion para encender todos los leds al tiempo
  void enciendeTodos()
  {
    for (int i = 0; i < digTotal; i ++)
    {
       vdig[i] =1;
       digitalWrite(dig[i], vdig[i]);
    }
  }

     
