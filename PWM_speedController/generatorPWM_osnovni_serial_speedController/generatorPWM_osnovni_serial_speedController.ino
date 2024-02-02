int VhodniPin = A2;     //napetostni delilnik priključimo na analogni pin
int IzhodniPin = 5;     //izhodni signal na pinu 5
int pozitivniPin = A4;  //pozitivna stran potenciometra
int negativniPin = A0;  //negativna stran potenciometra

int beri();              //funkcije
void pisi();
int porocaj();
void normalnaUporaba();



void setup() {

  pinMode(VhodniPin, INPUT);         // vhod

  pinMode(IzhodniPin, OUTPUT);       //izhod

  pinMode(pozitivniPin, OUTPUT);     //potenciometer
  pinMode(negativniPin, OUTPUT); 
  digitalWrite(pozitivniPin, HIGH);
  digitalWrite(negativniPin, LOW);

  digitalWrite(5, LOW);              //zaščita pred nenamernim visokim stanjem 

  Serial.begin(9600);

}

void loop() {

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


void normalnaUporaba(){

  beri();
  pisi();
  Serial.println(porocaj(beri()));  
  delay(10);
  
}


