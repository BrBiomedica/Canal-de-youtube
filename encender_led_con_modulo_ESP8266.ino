int salida = 2; 

void setup() { 
pinMode(salida, OUTPUT); 
} 

void loop() { 

digitalWrite(salida, HIGH);
delay(1000); 
digitalWrite(salida, LOW); 
delay(1000); 
}
