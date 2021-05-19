int rojo=2;      
int amarillo=4;  
int verde=7;     

void setup() {
  pinMode(verde,OUTPUT);   
  pinMode(amarillo,OUTPUT);
  pinMode(rojo,OUTPUT);    
}

void loop() {
 digitalWrite(verde,HIGH); 
 delay(2000);             
 digitalWrite(verde,LOW);  
 delay(500);             
 
 digitalWrite(amarillo,HIGH); 
 delay(2000);                 
 digitalWrite(amarillo,LOW); 
 delay(500);                 
 
 digitalWrite(rojo,HIGH); 
 delay(2000);              
 digitalWrite(rojo,LOW);  
 delay(500);              
}
