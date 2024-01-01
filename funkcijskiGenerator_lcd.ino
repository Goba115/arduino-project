int frekvenca = 1;     // začetna frekvenca
int delovniCikelj = 1; // začetni delovni cikelj

int povecavaF = 1;     // povečanje frekvence
int povecavaDC = 1;    // povečanje delovnega cikla
int zmanjsavaF = 1;    // zmanjševanje frekvence
int zmanjsavaDC = 1;   // zmanjševanje delovnega cikla

bool zastavica2 = false; // zastavice so namenjene enkratni ponovitvi kode ob pritisku gumba
bool zastavica4 = false;
bool zastavica7 = false;
bool zastavica8 = false;

#include <LiquidCrystal.h>


const int rs = 12, en = A0, d4 = A1, d5 = A2, d6 = A3, d7 = A4;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  pinMode(2, INPUT);  // povečava frekvence
  pinMode(4, INPUT);  // povečava delovnega cikla
  pinMode(5, OUTPUT); // glavni izhod  
  pinMode(7, INPUT);  // pomanjšanje delovnega cikla
  pinMode(8, INPUT);  // pomanjšanje frekvence


  digitalWrite(5, LOW);

  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);

}

void loop() {
  digitalWrite(5, HIGH); // visoko stanje izhoda
  delay(delovniCikelj);  // zakasnitev visokega stanja
  digitalWrite(5, LOW);  // nizko stanje izhoda 
  delay(frekvenca);      // zakasnitev nizkega stanja

  if (digitalRead(2) == HIGH && !zastavica2) {
    frekvenca += povecavaF; // s to funkcijo podaljšujemo izkljopljen čas
    zastavica2 = true;
  }

  if (digitalRead(4) == HIGH && !zastavica4) {
    delovniCikelj += povecavaDC; 
    zastavica4 = true;
  }

  if (digitalRead(8) == HIGH && !zastavica8) {
    frekvenca = max(1, frekvenca - zmanjsavaF);
    zastavica8 = true;
  }

  if (digitalRead(7) == HIGH && !zastavica7) {
    delovniCikelj = max(1, delovniCikelj - zmanjsavaDC);
    zastavica7 = true;
  }

  if (digitalRead(2) == LOW) {
    zastavica2 = false;
  }
  if (digitalRead(4) == LOW) {
    zastavica4 = false;
  }
  if (digitalRead(7) == LOW) {
    zastavica7 = false;
  }
  if (digitalRead(8) == LOW) {
    zastavica8 = false;
  }

  if (frekvenca <= 0) {
    frekvenca++;
  }
  if (delovniCikelj <= 0) {
    delovniCikelj++;
  }


  lcd.setCursor(0, 0);
  lcd.print(frekvenca);

  lcd.setCursor(0, 1);
  lcd.print(delovniCikelj);

}
