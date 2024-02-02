int perioda = 1000;           // začetna frekvenca      [mS]
double delovniCikelj = 0.005; // začetni delovni cikelj [%]
int multiplikator = 100;     // zaradi problema prevelikih št. je dodan multiplikator

int onTime;             //čas visokega stanja
int offTime; 


void setup() {
  Serial.begin(9600);
}

void loop() {

  onTime = perioda * delovniCikelj;  //simpl matematka za izračun visokega stanja 
  onTime *= multiplikator;
  offTime = perioda - onTime;                //izračun nizkega stanja


  Serial.println(onTime);
  Serial.println(offTime);

  delay(10000);

}
