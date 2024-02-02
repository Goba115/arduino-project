int vrh = 2;         //na kateren digitalnem pinu je povezan displey
int desnoZgoraj = 3;
int levoZgoraj = 4;
int sredina = 5;
int desnoSpodaj = 6;
int podn = 7;
int levoSpodaj = 8;
int pikaPin = 9;    //na povezan pin
int pika;           //katera je po vrsti


//                 0       1            2          3         4         5         6       7   
int vseLucke[] = {vrh, desnoZgoraj, levoZgoraj, sredina, desnoSpodaj, podn, levoSpodaj, pika};


void setup() {
  for (int i = 0; i < 7; i++) {
    pinMode(vseLucke[i], OUTPUT);
  }
  for (int i = 0; i < 7; i++)
    digitalWrite(vseLucke[i], HIGH);  // izklopi vse segmente na začetku

  vrh = 0;
  desnoZgoraj = 1;  // za lažje programiranje ukazov in segmentov
  levoZgoraj = 2;
  sredina = 3;
  desnoSpodaj = 4;
  podn = 5;
  levoSpodaj = 6;
  pika = 7;
}  

void nic(){
  for (int i = 0; i < 7; i++)
    digitalWrite(vseLucke[i], (i == sredina) ? HIGH : LOW);

}
void ena() {
  for (int i = 0; i < 7; i++) {
    digitalWrite(vseLucke[i], (i == desnoZgoraj || i == desnoSpodaj) ? LOW : HIGH);
  }
}
void dve(){
  for(int i = 0; i < 7; i++){
    digitalWrite(vseLucke[i], (i == levoZgoraj || i == desnoSpodaj) ? HIGH : LOW);
  }
}
void tri(){
  for(int i = 0; i < 7; i++){
    digitalWrite(vseLucke[i], (i == levoZgoraj || i == levoSpodaj) ? HIGH : LOW);
  }
}
void stiri(){
  for(int i = 0; i < 7; i++){
    digitalWrite(vseLucke[i], (i == levoSpodaj || i == vrh || i == podn) ? HIGH : LOW);
  }
}
void pet(){
  for(int i = 0; i < 7; i++){
    digitalWrite(vseLucke[i], (i == desnoZgoraj || i == levoSpodaj) ? HIGH : LOW);
  }
}
void sest(){
  for(int i = 0; i < 7; i++){
    digitalWrite(vseLucke[i], (i == desnoZgoraj) ? HIGH : LOW);
  }
}
void sedem(){
  for(int i = 0; i < 7; i++){
    digitalWrite(vseLucke[i], (i == levoZgoraj || i == levoSpodaj || i == sredina || i == podn) ? HIGH : LOW);
  }
}
void osem(){
  for(int i = 0; i < 7; i++){
    digitalWrite(vseLucke[i], LOW);
  }
}
void devet(){
  for(int i = 0; i < 7; i++){
    digitalWrite(vseLucke[i], (i == levoSpodaj) ? HIGH : LOW);
  }
}
void jePika(){
  digitalWrite(pikaPin, LOW);
}
void deset(){
  ena();
  delay(500);
  nic();
}
void niPika(){
  digitalWrite(pikaPin, HIGH);
}

void loop() {
  
  nic();
  delay(1000);
  ena();
  delay(1000);
  dve();
  delay(1000);
  tri();
  delay(1000);
  stiri();
  delay(1000);
  pet();
  delay(1000);
  sest();
  delay(1000);
  sedem();
  delay(1000);
  osem();
  delay(1000);
  devet();
  delay(1000);
  deset();
  delay(1000);

  

}
