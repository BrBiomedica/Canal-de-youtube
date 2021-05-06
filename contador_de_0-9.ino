int a = 2;
int b = 3;
int c = 4;
int d = 5;
int e = 9;
int f = 7;
int g = 8;

void setup(){
pinMode(a, OUTPUT);
pinMode(b, OUTPUT);
pinMode(c, OUTPUT);
pinMode(d, OUTPUT);
pinMode(e, OUTPUT);
pinMode(f, OUTPUT);
pinMode(g, OUTPUT);}

void escribirEnElDisplay(int va, int vb, int vc, int vd, int ve, int vf, int vg){

digitalWrite(a,va);
digitalWrite(b,vb);
digitalWrite(c,vc);
digitalWrite(d,vd);
digitalWrite(e,ve);
digitalWrite(f,vf);
digitalWrite(g,vg);

}

void loop(){

//Cero
escribirEnElDisplay(0,0,0,0,0,0,1);
delay(1000);
//Uno
escribirEnElDisplay(1,0,0,1,1,1,1);
delay(1000);
//Dos
escribirEnElDisplay(0,0,1,0,0,1,0);
delay(1000);
//Tres
escribirEnElDisplay(0,0,0,0,1,1,0);
delay(1000);
//Cuatro
escribirEnElDisplay(1,0,0,1,1,0,0);
delay(1000);
//Cinco
escribirEnElDisplay(0,1,0,0,1,0,0);
delay(1000);
//Seis
escribirEnElDisplay(0,1,0,0,0,0,0);
delay(1000);
//Siete
escribirEnElDisplay(0,0,0,1,1,1,1);
delay(1000);
//Ocho
escribirEnElDisplay(0,0,0,0,0,0,0);
delay(1000);
//Nueve
escribirEnElDisplay(0,0,0,1,1,0,0);
delay(1000);

}
