// Morse-decodeerder
// (C) 2016 Demented hacker
#include <Wire.h>
#include <LiquidCrystal_I2C.h> // https://bitbucket.org/fmalpartida/new-liquidcrystal/downloads ==> LiquidCrystal_V1.2.1.zip

// Verbind een tactile schakelaar (of seinsleutel) tussen pen 7 van de Arduino en GND.
// En sluit een buzzer aan tussen Arduino pen 8 en GND.
// Dan kun je met de schakelaar seinen. Bekijk de gedecodeerde Morse-code in de serial monitor.

#define SLEUTEL 7  // Seinsleutel van pen 7 naar GND
#define BUZZER 8   // Buzzer van pen 8 naar GND

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

void setup() {
  pinMode(SLEUTEL, INPUT_PULLUP);
  pinMode(BUZZER, OUTPUT);
  Serial.begin(115200);
  lcd.begin(20, 4);
  lcd.backlight();     
}

float StreepDuur = 200.0;
boolean PrevS = false;
long tStartTeken, tStartPauze;
boolean S;
String kar = "";
void loop() {
  S = !digitalRead(SLEUTEL);

  if (S) {
    if (S != PrevS) {
      tStartTeken = millis();
      DecodeerPauze(tStartPauze);
    }
    digitalWrite(BUZZER, HIGH);
  }
  else {
    if (S != PrevS) {
      tStartPauze = millis();
      Decodeer(tStartTeken);
    }
    digitalWrite(BUZZER, LOW);
  }

  if (abs(millis() - tStartPauze) > StreepDuur * 10) {
    DecodeerPauze(tStartPauze);
  }

  PrevS = S;
}

void Decodeer(long starttijd) {
  char teken = '?';
  long tijd = abs(millis() - starttijd); // Tijdsduur van het geseinde teken (een punt of een streep)
  float PuntDuur = StreepDuur / 3.0;

  if (tijd <= 2) return; // Denderonderdrukking

  if (tijd <= PuntDuur) teken = '.';
  else if (tijd > StreepDuur) teken = '-';
  else if ((tijd > (StreepDuur + PuntDuur) / 1.9) && tijd <= StreepDuur) teken = '-';
  else teken = '.';

  if (teken == '-') {
    if (tijd > StreepDuur) StreepDuur++;
    if (tijd < StreepDuur) StreepDuur--;
  }
  else if (teken == '.') {
    if (tijd > StreepDuur / 3.0) StreepDuur++;
    if (tijd < StreepDuur / 3.0) StreepDuur--;
  }
  kar += teken;
  //Serial.println(teken);
}

void DecodeerPauze(long starttijd) {
  if (kar == "") return;

  char teken = '?';
  long tijd = abs(millis() - starttijd);
  if (tijd > StreepDuur - StreepDuur / 40) {
    DecodeerKar();
    //Serial.print();
  }
  if (tijd > StreepDuur * 2) {
    DecodeerKar();
    Print(" "); Serial.print(" ");
  }
  //else DecodeerKar();
  //Serial.println(teken);
}

void DecodeerKar() {
  static String letters[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-",
    ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "E"
  };
  int i = 0;
  while (letters[i] != "E") {
    if (letters[i] == kar) {
      Print((char)('A' + i));
      Serial.print((char)('A' + i));
      break;
    }
    i++;
  }
  if (letters[i] == "E") {
    Print(kar);
    Serial.print(kar);
  }
  kar = "";
}

int y = 0, x = 0;
void Print(String &s) {
  for (int i = 0; i < s.length(); i++) {
    upd(); lcd.print(s[i]);
  }
}
void Print(char s) {
  upd();
  lcd.print(s);
}
void Print(char *s) {
  for (int i = 0; i < strlen(s); i++) {
    upd();
    lcd.print(s[i]);
  }
}

void upd() {
  lcd.setCursor(x, y);
  x++; if (x >= 20) {
    x = 0;
    y++;
  }
  if (y >= 4) {
    lcd.clear();
    x=y = 0;    
  }
}

