// Motor A
int ENA = 10;
int IN1 = 9;
int IN2 = 8;

void setup ()
{
 // Declaramos todos los pines como salidas
 pinMode (ENA, OUTPUT);
 pinMode (IN1, OUTPUT);
 pinMode (IN2, OUTPUT);
}
void loop ()
{
 Adelante ();
 delay (1000);
 Atras ();
 delay (1500);
}
 
void Adelante ()
{
 //Direccion motor A
 digitalWrite (IN1, HIGH);
 digitalWrite (IN2, LOW);
 analogWrite (ENA, 255); //Velocidad motor A
}
void Atras ()
{
 //Direccion motor A
 digitalWrite (IN1, LOW);
 digitalWrite (IN2, HIGH);
 analogWrite (ENA, 128); //Velocidad motor A

}
