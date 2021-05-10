void setup()
{
  for (int i = 0; i <= 13; i++)
    pinMode(i, OUTPUT); //Establecemos todos los pines a OUTPUT
}
//Hacemos un array que contengan todos los numeros de el 0 al 9 en binario para luego porder pasarlo a las pantallas
const int number[11] = {0b1000000, 0b1111001, 0b0100100, 0b0110000, 0b0011001, 0b0010010, 0b0000010, 0b1111000, 0b0000000, 0b0010000};

void loop()
{
  for (int decimas = 0; decimas < 10; decimas++)
  {
    display_decimas(decimas);
  }
}

void display_decimas(const int decimas)
{
  int pin1, a, unidades;     
  //El pin 1 se usa para los pines que llevan la pantalla uno que se refiere a los decimales
  for (pin1 = 0, a = 0; pin1 < 7; pin1++, a++)
  {
    digitalWrite(pin1, bitRead(number[decimas], a));
  }
  for (unidades = 0; unidades < 10; unidades++)
  {
    display_unidades(unidades);
    delay(1000); 
    //Establecemos el tiempo que tarda los numeros en cambiar con el delay
  }
}

void display_unidades(const int x)
{ int pin2, b;             
//El pin 2 se usa para los pines que llevan la pantalla dos que se refiere a las unidades
  for (pin2 = 7, b = 0; pin2 <= 13; pin2++, b++)
  {
    digitalWrite(pin2, bitRead(number[x], b));
  }

}
