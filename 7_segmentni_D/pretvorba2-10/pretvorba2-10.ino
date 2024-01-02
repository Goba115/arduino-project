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


int vhod1 = A0;
int vhod2 = A1;
int vhod3 = A2;
int vhod4 = A3;

int stanje1;
int stanje2;
int stanje3;
int stanje4;

int cifra1;
int cifra2;
int cifra3;
int cifra4;

int vrednost;
int vsota[2];    //pretvorjene dvojiške vrednosti v desetiške

void stevilo(){
  
  stanje1 = digitalRead(vhod1);
  stanje2 = digitalRead(vhod2);
  stanje3 = digitalRead(vhod3);
  stanje4 = digitalRead(vhod4);

  if (stanje1 == HIGH){
    cifra1 = 1;
  }else{
    cifra1 = 0;
  }
  
  if (stanje2 == HIGH){
    cifra2 = 2;
  }else{
    cifra2 = 0;
  }

  if(stanje3 == HIGH){
    cifra3 = 4;
  }else{
    cifra3 = 0;
  }

  if(stanje4 == HIGH){
    cifra4 = 8;
  }else{
    cifra4 = 0;
  }

  vsota[2] = cifra1 + cifra2 + cifra3 + cifra4;  //izhod je desetiški

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
void niPika(){
  digitalWrite(pikaPin, HIGH);
}



void setup(){
  pinMode(vhod1, INPUT);
  pinMode(vhod2, INPUT);
  pinMode(vhod3, INPUT);
  pinMode(vhod4, INPUT);

  for (int i = 0; i < 7; i++)
    pinMode(vseLucke[i], OUTPUT);
  
  for (int i = 0; i < 7; i++)
    digitalWrite(vseLucke[i], HIGH);  // izklopi vse segmente na začetku

}


void loop(){
  stevilo();  // preberi vrednosti na vhodih
  niPika();   // izklopi piko

  switch (vsota[2]) {
    case 0:
      nic();
      break;
    case 1:
      ena();
      break;
    case 2:
      dve();
      break;
    case 3:
      tri();
      break;
    case 4:
      stiri();
      break;
    case 5:
      pet();
      break;
    case 6:
      sest();
      break;
    case 7:
      sedem();
      break;
    case 8:
      osem();
      break;
    case 9:
      devet();
      break;
    default:
      niPika();
      break;
  }

  delay(1000);
}

