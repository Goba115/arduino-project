// This example shows various featues of the library for LCD with 16 chars and 2 lines.

#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_PCF8574.h>

LiquidCrystal_PCF8574 lcd(0x27);  // set the LCD address to 0x27 for a 16 chars and 2 line display

byte dotOff[] = { 0b00000, 0b01110, 0b10001, 0b10001,
                  0b10001, 0b01110, 0b00000, 0b00000 };
byte dotOn[] = { 0b00000, 0b01110, 0b11111, 0b11111,
                 0b11111, 0b01110, 0b00000, 0b00000 };

bool stanje = 1;
bool zastavica = 1;
short stikalo = 3;
short rele1 = 10;
int osvezevanje;

void setup() {
  
  Serial.begin(115200);
  Wire.begin();
  Wire.beginTransmission(0x27);
  int error = Wire.endTransmission();

  if (error == 0) {
    lcd.begin(16, 2);  // initialize the lcd

    lcd.createChar(1, dotOff);
    lcd.createChar(2, dotOn);
  }
  pinMode(A2, INPUT);
  pinMode(stikalo, INPUT_PULLUP);
  pinMode(rele1, OUTPUT);

  pinMode(9, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);

  osvezevanje = 100;
  if (digitalRead(9) == LOW){
    osvezevanje = 1000;
    }
  if (digitalRead(8) == LOW){osvezevanje = 500;}
  if (digitalRead(7) == LOW){osvezevanje = 75;}
}



/*
void loop() {
  if (show == 0) {
    lcd.setBacklight(255);
    lcd.home();
    lcd.clear();
    lcd.print("Hello LCD");
    delay(1000);

    lcd.setBacklight(0);
    delay(400);
    lcd.setBacklight(255);

  } else if (show == 1) {
    lcd.clear();
    lcd.print("Cursor On");
    lcd.cursor();

  } else if (show == 2) {
    lcd.clear();
    lcd.print("Cursor Blink");
    lcd.blink();

  } else if (show == 3) {
    lcd.clear();
    lcd.print("Cursor OFF");
    lcd.noBlink();
    lcd.noCursor();

  } else if (show == 4) {
    lcd.clear();
    lcd.print("Display Off");
    lcd.noDisplay();

  } else if (show == 5) {
    lcd.clear();
    lcd.print("Display On");
    lcd.display();

  } else if (show == 7) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("*** first line.");
    lcd.setCursor(0, 1);
    lcd.print("*** second line.");

  } else if (show == 8) {
    lcd.scrollDisplayLeft();
  } else if (show == 9) {
    lcd.scrollDisplayLeft();
  } else if (show == 10) {
    lcd.scrollDisplayLeft();
  } else if (show == 11) {
    lcd.scrollDisplayRight();

  } else if (show == 12) {
    lcd.clear();
    lcd.print("write-");

  } else if (show == 13) {
    lcd.clear();
    lcd.print("custom 1:<\01>");
    lcd.setCursor(0, 1);
    lcd.print("custom 2:<\02>");

  } else {
    lcd.print(show - 13);
  }  // if

  delay(1400);
  show = (show + 1) % 16;
}  // loop()
*/
void loop(){
  if (digitalRead(stikalo) == LOW && zastavica == 1){
    stanje = !stanje;
    zastavica = 0;
  }

  int meri = analogRead(A2);
  lcd.setBacklight(stanje);
  lcd.setCursor(0, 0);
  lcd.print("vrednost");

  lcd.setCursor(2, 1);
  if (meri > 1000){ 
    meri = 1000;
    }
  meri /= 10;
  lcd.print(meri);
  lcd.print("%");

  if (meri >= 50){
    digitalWrite(rele1, HIGH);
  }
  else {digitalWrite(rele1, LOW);}

  delay(osvezevanje);  //zakasnitev za izostrenje stevilk
  lcd.clear();

  if (digitalRead(stikalo) == HIGH && zastavica == 0){ //zastavica
    zastavica = 1;  
  }

}
