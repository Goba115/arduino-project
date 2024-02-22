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
  int vhod = analogRead(vhodniPin);  //10 kvadratkov je 1V
  int nastavitev = analogRead(pot);
  nastavitev /= 2;
  short vrednost = nastavitev - vhod;
  if (vrednost > 0){
    if (vrednost > 2){
      analogWrite(izhodniPin, 10);
      if (vrednost > 4){
        analogWrite(izhodniPin, 20);
        if (vrednost > 5){
          analogWrite(izhodniPin, 30);
          if (vrednost > 6){
            analogWrite(izhodniPin, 40);
            if (vrednost > 10){
              analogWrite(izhodniPin, 75);
              if (vrednost > 10){
                analogWrite(izhodniPin, 104);
              }
            }
          }
        }
      }
    }
  }
  else{
    analogWrite(izhodniPin, 0);
  }

  //Serial.println(vhod);


}
