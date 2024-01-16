int perioda = 2;        // začetna frekvenca      [mS]
int delovniCikelj = 50; // začetni delovni cikelj [%]

int onTime;             //čas visokega stanja
int offTime;            //čas nizkega stanja

int povecavaP = 10;    // povečanje frekvence
int povecavaDC = 10;    // povečanje delovnega cikla
int zmanjsavaP = 10;   // zmanjševanje frekvence
int zmanjsavaDC = 10;   // zmanjševanje delovnega cikla

bool zastavica2 = false; // zastavice so namenjene enkratni ponovitvi kode ob pritisku gumba
bool zastavica4 = false;
bool zastavica7 = false;
bool zastavica8 = false;

void setup() {
  pinMode(2, INPUT);  // povečava frekvence
  pinMode(4, INPUT);  // povečava delovnega cikla
  pinMode(5, OUTPUT); // glavni izhod  
  pinMode(7, INPUT);  // pomanjšanje delovnega cikla
  pinMode(8, INPUT);  // pomanjšanje frekvence

  digitalWrite(5, LOW);


}

void loop() {
  
  onTime = (perioda * delovniCikelj) / 100;  //simpl matematka za izračun visokega stanja
  offTime = perioda - onTime;                //izračun nizkega stanja

  onTime = abs(onTime);
  offTime = abs(offTime);

  digitalWrite(5, HIGH);          // visoko stanje izhoda
  delay(onTime);                  // zakasnitev visokega stanja
  digitalWrite(5, LOW);           // nizko stanje izhoda 
  delay(offTime);                 // zakasnitev nizkega stanja

  if (digitalRead(2) == HIGH && !zastavica2) { //podaljšujemo periodo
    perioda += povecavaP;
    zastavica2 = true;
  }
  
  if (digitalRead(8) == HIGH && !zastavica8) { //zmanjšujemo periodo
      perioda -= zmanjsavaP;        
      zastavica8 = true;
  }

  if (digitalRead(4) == HIGH && !zastavica4) { //podaljšujemo delovni cikelj
    delovniCikelj += povecavaDC;       
    zastavica4 = true;
  }
  
  if (digitalRead(7) == HIGH && !zastavica7) { //zmanjšujemo delovni cikelj
    delovniCikelj -= povecavaDC;
    zastavica7 = true;
  }

class zastavce;
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

}
