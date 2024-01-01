int frekvenca = 1;     // začetna frekvenca
int delovniCikelj = 1; // začetni delovni cikelj
int povecavaF = 1;     // povečanje frekvence
int povecavaDC = 1;    // povečanje delovnega cikla
int zmanjsavaF = 1;    // zmanjševanje frekvence
int zmanjsavaDC = 1;   // zmanjševanje delovnega cikla

bool pin2Flag = false;
bool pin4Flag = false;

void setup() {
  pinMode(5, OUTPUT); // glavni izhod
  pinMode(2, INPUT);  // povečava frekvence
  pinMode(4, INPUT);  // povečava delovnega cikla
  pinMode(7, INPUT);  // pomanjšanje delovnega cikla
  pinMode(8, INPUT);  // pomanjšanje frekvence

  digitalWrite(5, LOW);
}

void loop() {
  digitalWrite(5, HIGH);
  delay(delovniCikelj);
  digitalWrite(5, LOW);
  delay(frekvenca);

  if (digitalRead(2) == HIGH && !pin2Flag) {
    frekvenca = frekvenca + povecavaF;
    pin2Flag = true; // Set the flag to true to indicate the increment has been performed
  }

  if (digitalRead(4) == HIGH && !pin4Flag) {
    delovniCikelj = delovniCikelj + povecavaDC;
    pin4Flag = true; // Set the flag to true to indicate the increment has been performed
  }

  if (digitalRead(8) == HIGH) {
    // Decrease frequency by 1 ms, but ensure it doesn't go below 1
    frekvenca = max(1, frekvenca - zmanjsavaF);
  }

  if (digitalRead(7) == HIGH) {
    // Decrease duty cycle by 1 ms, but ensure it doesn't go below 1
    delovniCikelj = max(1, delovniCikelj - zmanjsavaDC);
  }

  // Reset the flags when the corresponding pins are no longer HIGH
  if (digitalRead(2) == LOW) {
    pin2Flag = false;
  }

  if (digitalRead(4) == LOW) {
    pin4Flag = false;
  }
}
