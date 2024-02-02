long perioda = 1000;      // začetna frekvenca      [mS]
float delovniCikelj = 50; // začetni delovni cikelj [%]
int delitelj = 100;       // delitelj, da zračunamo onTime

long onTime;              //čas visokega stanja
long offTime;             //čas nizkega stanja

int povecavaP = 500;      // povečanje periode
int zmanjsavaP = 500;     // zmanjševanje periode
float povecavaDC = 5;     // povečanje delovnega cikla
float zmanjsavaDC = 5;    // zmanjševanje delovnega cikla

bool zastavica2 = false;  // zastavice so namenjene enkratni ponovitvi kode ob pritisku gumba
bool zastavica4 = false;
bool zastavica7 = false;
bool zastavica8 = false;

void setup() {
  pinMode(2, INPUT);       // povečava periode
  pinMode(4, INPUT);       // povečava delovnega cikla
  pinMode(5, OUTPUT);      // glavni izhod  
  pinMode(7, INPUT);       // pomanjšanje delovnega cikla
  pinMode(8, INPUT);       // pomanjšanje periode

  Serial.begin(9600);
  Serial.println("povezava uspela! ");

}

void loop() {
  
  if (perioda < 500){ //zaščita proti prekoračanju meje najvisje frekvence
    perioda = 500;
  }

  onTime = (perioda * delovniCikelj) / delitelj;  //simpl matematka za izračun visokega stanja
  offTime = perioda - onTime;                     //izračun nizkega stanja


  if(onTime < 1){     // dodatna zaščita za visoko stanje
    onTime = 10;    
  }

  if(offTime < 1){    // dodatna zaščita za nizko stanje
    offTime = 10;    
  }

  if(delovniCikelj >= 95){ //zaščita proti prekoračanju meje najvisje vrednosti delovnega cikla
  delovniCikelj = 95;  
  }

  if(delovniCikelj <= 5){  //zaščita proti prekoračanju meje najvisje vrednosti delovnega cikla
  delovniCikelj = 5;  
  }

  digitalWrite(5, HIGH);          // visoko stanje izhoda
  delayMicroseconds(onTime);      // zakasnitev visokega stanja
  digitalWrite(5, LOW);           // nizko stanje izhoda 
  delayMicroseconds(offTime);     // zakasnitev nizkega stanja


  if (digitalRead(2) == HIGH && !zastavica2){ //podaljšujemo periodo
    perioda += povecavaP;
    zastavica2 = true;

    Serial.println("onTime  [mS]");
    Serial.println(onTime);
    Serial.println("offTime [mS]");
    Serial.println(offTime);
  }
  
  if (digitalRead(8) == HIGH && !zastavica8){  //zmanjšujemo periodo
    perioda -= zmanjsavaP;        
    zastavica8 = true;

    Serial.println("onTime  [mS]");
    Serial.println(onTime);
    Serial.println("offTime [mS]");
    Serial.println(offTime);
  }

  if (digitalRead(4) == HIGH && !zastavica4){ //podaljšujemo delovni cikelj
    delovniCikelj += povecavaDC;       
    zastavica4 = true;

    Serial.println("delovni cikelj [%]");
    Serial.println(delovniCikelj);
  }

  if (digitalRead(7) == HIGH && !zastavica7){ //zmanjšujemo delovni cikelj
    delovniCikelj -= povecavaDC;
    zastavica7 = true;
    
    Serial.println("delovni cikelj [%]");
    Serial.println(delovniCikelj);
  }


class zastavice;  //namenjene, da preverijo, da se je ukaz samo enkrat ponovil
  if (digitalRead(2) == LOW){
    zastavica2 = false;
  }

  if (digitalRead(4) == LOW){ 
    zastavica4 = false;
  }

  if (digitalRead(7) == LOW){ 
    zastavica7 = false;
  }

  if (digitalRead(8) == LOW){ 
    zastavica8 = false;
  }
}
