const int EchoPin = 7;
const int TriggerPin = 8;
const int VACIO = 13;
const int CUARTO = 12;
const int MITAD = 11;
const int TRES = 10;
const int LLENO = 9;
float distancia;
long tiempo;
 
void setup() {
   Serial.begin(9600);
   pinMode(VACIO, OUTPUT);
  pinMode(CUARTO, OUTPUT);
  pinMode(MITAD, OUTPUT);
  pinMode(TRES, OUTPUT);
  pinMode(LLENO, OUTPUT);
   pinMode(TriggerPin, OUTPUT);
   pinMode(EchoPin, INPUT);
}
 
void loop() {
  long tiempo, distancia;
  digitalWrite(TriggerPin, LOW);  
  delayMicroseconds(2);
  digitalWrite(TriggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(TriggerPin, LOW);
  tiempo = pulseIn(EchoPin, HIGH);

  distancia = tiempo / 29 / 2 ;

   Serial.print("Distancia: "); 
   Serial.println(distancia);
   

if (distancia >= 30) {
        digitalWrite(VACIO , HIGH);
        digitalWrite(CUARTO , LOW);
        digitalWrite(MITAD , LOW);
        digitalWrite(TRES , LOW);
        digitalWrite(LLENO , LOW);
                      }
else if((distancia < 30) && (distancia >= 20)){
        digitalWrite(VACIO , HIGH);
        digitalWrite(CUARTO , HIGH);
        digitalWrite(MITAD , LOW);
        digitalWrite(TRES , LOW);
        digitalWrite(LLENO , LOW);
       
} 
else if((distancia < 30) && (distancia >= 10)){
        digitalWrite(VACIO , HIGH);
        digitalWrite(CUARTO , HIGH);
        digitalWrite(MITAD , HIGH);
        digitalWrite(TRES , LOW);
        digitalWrite(LLENO , LOW);
       
} 
else if((distancia < 30) && (distancia >= 5)) {
        digitalWrite(VACIO , HIGH);
        digitalWrite(CUARTO , HIGH);
        digitalWrite(MITAD , HIGH);
        digitalWrite(TRES , HIGH);
        digitalWrite(LLENO , LOW);
} 
else if(distancia < 30 ) {
        digitalWrite(VACIO , HIGH);
        digitalWrite(CUARTO , HIGH);
        digitalWrite(MITAD , HIGH);
        digitalWrite(TRES , HIGH);
        digitalWrite(LLENO , HIGH);
} 
delay(1000);

}
