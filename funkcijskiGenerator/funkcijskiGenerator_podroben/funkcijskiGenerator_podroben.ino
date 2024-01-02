int frekvenca = 100;    // začetna frekvenca
int delovniCikelj = 100; // začetni delovni cikelj

int povecavaF = 10;     // povečanje frekvence
int povecavaDC = 10;    // povečanje delovnega cikla
int zmanjsavaF = 10;    // zmanjševanje frekvence
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
  digitalWrite(5, HIGH); // visoko stanje izhoda
  delayMicroseconds(delovniCikelj);  // zakasnitev visokega stanja
  digitalWrite(5, LOW);  // nizko stanje izhoda 
  delayMicroseconds(frekvenca);      // zakasnitev nizkega stanja

  if (digitalRead(2) == HIGH && !zastavica2) { //podaljšujemo izklopljen čas
    frekvenca += povecavaF;
    zastavica2 = true;
  }
  
  if (digitalRead(8) == HIGH && !zastavica8) { //zmanjšujemo izključen čas
    frekvenca = max(1, frekvenca - zmanjsavaF);
    zastavica8 = true;
  }

  if (digitalRead(4) == HIGH && !zastavica4) { //podaljšujemo vklopljen čas
    delovniCikelj += povecavaDC; 
    frekvenca -= zmanjsavaF;
    zastavica4 = true;
  }
  
  if (digitalRead(7) == HIGH && !zastavica7) { //zmanjšujemo vklopljen čas
    if(delovniCikelj != 1){
      frekvenca += povecavaF;
    }  
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
}
