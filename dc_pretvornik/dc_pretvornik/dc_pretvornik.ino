const short izhodniPin = 10;
const short vhodniPin = A7;
const short pot = A2;

void setup() {
TCCR1B = B00000001;

pinMode(pot, INPUT);
pinMode(izhodniPin, OUTPUT);
pinMode(A0, OUTPUT);
pinMode(A4, OUTPUT);
pinMode(vhodniPin, INPUT);

digitalWrite(A0, LOW);
digitalWrite(A4, HIGH);

Serial.begin(9600);
}

void loop() {
  int vhod = analogRead(vhodniPin);  //100 kvadratkov je 10V
  int nastavitev = analogRead(pot);
  nastavitev /= 2;
  short vrednost = nastavitev - vhod;
  if (vrednost < 3){
    analogWrite(izhodniPin, 0);
    analogWrite(izhodniPin, 25); //0.1
  }
  if (vrednost < 5 && vrednost > 3) {
    analogWrite(izhodniPin, 0);
    analogWrite(izhodniPin, 50); //0.2
  }
  if (vrednost < 15 && vrednost	> 5) {
    analogWrite(izhodniPin, 0);
    analogWrite(izhodniPin, 77);//0.3
  }
  if (vrednost > 15) {
    analogWrite(izhodniPin, 0);
    analogWrite(izhodniPin , 104);  //0.4
  }
  else{
    analogWrite(izhodniPin, 0);
  }
  Serial.println(vrednost);
  //Serial.println(vhod);


}
