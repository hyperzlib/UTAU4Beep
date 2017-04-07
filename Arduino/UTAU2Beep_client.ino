int Tone = 0, Length = 0, i = 0;
char t;
int tonepin = 8;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(tonepin, OUTPUT);
}

void loop() {
  Tone = 0;
  Length = 0;
  i = 0;
  while (Serial.available()) {
    t = Serial.read();
    if (t == ',') {
      i = 1;
      continue;
    }
    switch (i) {
      case 0:
        Tone = (Tone * 10) + (t - '0');
        break;
      case 1:
        Length = (Length * 10) + (t - '0');
        break;
    }
  }
  tone(tonepin, Tone);
  delay(Length);
  noTone(tonepin);
  Serial.print(Tone);
  Serial.print(",");
  Serial.print(Length);
  Serial.print("\n");
  while (!Serial.available()) {
    delay(100);
  }
}

