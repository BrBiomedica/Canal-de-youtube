#include "Ultrasonic.h"     
Ultrasonic ultrasonic(5,7); //Trigger, Echo
#include "pitches.h"        
int sonido = NOTE_E5;       

int sonar;                 

void setup()
{
   //Serial.begin(9600);    
}

void loop()
{
   
   sonar = ultrasonic.Ranging(CM);   
                                                                      
   while (sonar < 60)             
   {   
       noTone(8);                  //Mantenemos el sonido apagado
       
       delay(sonar*10);                   
       tone(8, sonido);                   
       delay(100);                        
       noTone(8);                  //Apagamos el sonido
    
       while (sonar < 10)                 {
         tone(8, sonido);                //Suena sin interrupciones indicando la proximidad del objeto
         sonar = ultrasonic.Ranging(CM); //Distancia  
       }  
       sonar = ultrasonic.Ranging(CM); //Leemos la distancia 
   }
  
}
