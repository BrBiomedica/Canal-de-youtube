/*Programa diseñado para el funcionamiento de un cubo led 2x2x2
 * basico, ideal para el aprendizaje de rutinas breves en 
 * programacion.
 */


#define L1 2
#define L2 3
#define L3 4
#define L4 5
int a=200;

void setup()
{
  pinMode(L1,OUTPUT);
  pinMode(L2,OUTPUT);
  pinMode(L3,OUTPUT);
  pinMode(L4,OUTPUT);
  pinMode(A0,OUTPUT);
  pinMode(A1,OUTPUT);
}

void loop() 
{
  digitalWrite(A0,HIGH);
  digitalWrite(A1,LOW);
  digitalWrite(L1, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(L2,LOW);
  digitalWrite(L3,LOW);
  digitalWrite(L4,LOW);
  delay(a);
  digitalWrite(L1,LOW);
  digitalWrite(L2,HIGH);
  delay(a);
  digitalWrite(L2,LOW);
  digitalWrite(L3,HIGH);
  delay(a);
  digitalWrite(L3,LOW);
  digitalWrite(L4,HIGH);
  delay(a);
  digitalWrite(A0,LOW);
  digitalWrite(A1,HIGH);
  digitalWrite(L1,LOW);
  digitalWrite(L2,LOW);
  digitalWrite(L3,LOW);
  digitalWrite(L4,HIGH);
  delay(a);
  digitalWrite(L3,HIGH);
  digitalWrite(L4,LOW);
  delay(a);
  digitalWrite(L3,LOW);
  digitalWrite(L2,HIGH);
  delay(a);
  digitalWrite(L2,LOW);
  digitalWrite(L1,HIGH);
  delay(a);
  digitalWrite(L1,LOW);
  digitalWrite(A1,LOW);
  delay(a);
  digitalWrite(L1,LOW);
  digitalWrite(L2,LOW);
  digitalWrite(L3,LOW);
  digitalWrite(L4,LOW);
  delay(a);
  digitalWrite(L1,HIGH);
  digitalWrite(L2,HIGH);
  digitalWrite(L3,HIGH);
  digitalWrite(L4,HIGH);
  delay(a);
  

  
}
