int VhodniPin = A2;     //napetostni delilnik priključimo na analogni pin
int IzhodniPin = 5;     //izhodni signal na pinu 5
int pozitivniPin = A4;  //pozitivna stran potenciometra
int negativniPin = A=   //negativna stran potenciometra
int knof = 2;           //knof za izvajanje funkcije testiranjeVezja()

int beri();              //funkcije
void pisi();
int porocaj();
void testirajVezje();
void normalnaUporaba();
void 


void setup() {

  pinMode(VhodniPin, INPUT);         // vhod
  pinMode(knof, INPUT);

  pinMode(IzhodniPin, OUTPUT);       //izhod

  pinMode(pozitivniPin, OUTPUT);     //potenciometer
  pinMode(negativniPin, OUTPUT); 
  digitalWrite(pozitivniPin, HIGH);
  digitalWrite(negativniPin, LOW);

  digitalWrite(5, LOW);              //zaščita pred nenamernim visokim stanjem 

  Serial.begin(9600);

}

void loop() {
  if ()
  normalnaUporaba();



}

int beri() {

  int PrebranaVrednost = analogRead(VhodniPin);
  float x = PrebranaVrednost /= 4;

  if (x < 4){
    x = 0;
  }
  return x;
}

void pisi() {

  analogWrite(IzhodniPin, beri());
}

int porocaj(int vhod){
  
  vhod *= 4;
  vhod /= 10;
  if (vhod > 100){
    vhod = 100;
  }

  return vhod;
}

void testirajVezje(int x){

  int prevzeto = x;

  for (int i; i < )

}

void normalnaUporaba(){

  beri();
  pisi();
  Serial.println(porocaj(beri()));  
  delay(10);
  
}


