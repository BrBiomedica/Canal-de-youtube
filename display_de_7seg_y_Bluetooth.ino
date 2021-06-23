const int A = 2;
const int B = 3;
const int C = 4;
const int D = 5;
const int E = 7;
const int F = 8;
const int G = 9;

// Variavel para leitura serial
char input;

void setup() {
  // Inicial serial
  Serial.begin(9600);

  // Define os pinos {2-8} como saida
  pinMode(A, OUTPUT); 
  pinMode(B, OUTPUT); 
  pinMode(C, OUTPUT); 
  pinMode(D, OUTPUT); 
  pinMode(E, OUTPUT); 
  pinMode(F, OUTPUT); 
  pinMode(G, OUTPUT);

  // Apaga o display
  digitalWrite(A, LOW); 
  digitalWrite(B, LOW); 
  digitalWrite(C, LOW); 
  digitalWrite(D, LOW); 
  digitalWrite(E, LOW); 
  digitalWrite(F, LOW); 
  digitalWrite(G, LOW);
}

void loop() {
  // Verifica se existem dados na serial
  if (Serial.available() > 0) {
    // Ler dado
    input = Serial.read();
    // Verifica se o dado é um numero
    if (input == '0') {
      //desenha o 0:
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, HIGH);
      digitalWrite(E, HIGH);
      digitalWrite(F, LOW);
      digitalWrite(G, HIGH);
    } else if (input == '1') {
      //desenha o 1:
      digitalWrite(A, LOW);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, LOW);
      digitalWrite(E, LOW);
      digitalWrite(F, LOW);
      digitalWrite(G, LOW);
    } else if (input == '2') {
      //desenha o 2:
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, LOW);
      digitalWrite(D, HIGH);
      digitalWrite(E, HIGH);
      digitalWrite(F, HIGH);
      digitalWrite(G, LOW);
    } else if (input == '3') {
      //desenha o 3:
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, HIGH);
      digitalWrite(E, LOW);
      digitalWrite(F, HIGH);
      digitalWrite(G, LOW);
    } else if (input == '4') {
      //desenha o 4:
      digitalWrite(A, LOW);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, LOW);
      digitalWrite(E, LOW);
      digitalWrite(F, HIGH);
      digitalWrite(G, HIGH);
    } else if (input == '5') {
      //desenha o 5:
      digitalWrite(A, HIGH);
      digitalWrite(B, LOW);
      digitalWrite(C, HIGH);
      digitalWrite(D, HIGH);
      digitalWrite(E, LOW);
      digitalWrite(F, HIGH);
      digitalWrite(G, HIGH);
    } else if (input == '6') {
      //desenha o 6:
      digitalWrite(A, LOW);
      digitalWrite(B, LOW);
      digitalWrite(C, HIGH);
      digitalWrite(D, HIGH);
      digitalWrite(E, HIGH);
      digitalWrite(F, HIGH);
      digitalWrite(G, HIGH);
    } else if (input == '7') {
      //desenha o 7:
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, LOW);
      digitalWrite(E, LOW);
      digitalWrite(F, LOW);
      digitalWrite(G, LOW);
    } else if (input == '8') {
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, HIGH);
      digitalWrite(E, HIGH);
      digitalWrite(F, HIGH);
      digitalWrite(G, HIGH);
    } else if (input == '9') {
      //desenha o 9:
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, LOW);
      digitalWrite(E, LOW);
      digitalWrite(F, HIGH);
      digitalWrite(G, HIGH);
    }
  }
}
