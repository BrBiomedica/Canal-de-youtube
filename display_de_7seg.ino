int mensaje=0;
void setup(){

  Serial.begin(9600);
  pinMode(2, OUTPUT);  
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);

}
void display (int a, int b, int c, int d, int e, int f, int g)// Función del display
{
  digitalWrite (2,a);   
  digitalWrite (3,b);   
  digitalWrite (4,c);
  digitalWrite (5,d);
  digitalWrite (9,e);
  digitalWrite (7,f);
  digitalWrite (8,g);
}

void loop(){
  if(Serial.available()>0){
    mensaje=Serial.read();
  if(mensaje=='0'){
    display (0,0,0,0,0,0,1);
  }
  if(mensaje=='1'){
    display (1,0,0,1,1,1,1);
  }
  if(mensaje=='2'){
    display (0,0,1,0,0,1,0);
  }
  if(mensaje=='3'){
    display (0,0,0,0,1,1,0);
  }
  if(mensaje=='4'){
    display (1,0,0,1,1,0,0);
  }
  if(mensaje=='5'){
     display (0,1,0,0,1,0,0);
  }
  if(mensaje=='6'){
     display (0,1,0,0,0,0,0);
  }
  if(mensaje=='7'){
     display (0,0,0,1,1,1,1);
  }
  if(mensaje=='8'){
     display (0,0,0,0,0,0,0);
  }
  if(mensaje=='9'){
     display (0,0,0,1,1,0,0);
  }
  }

}
