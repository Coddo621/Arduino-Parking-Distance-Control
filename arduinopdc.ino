#include <LiquidCrystal_I2C.h>
int trigPin = 9;
int echoPin = 10;
int distance;

LiquidCrystal_I2C lcd(0x27, 20, 4);

byte frame1[8] = {
  0b11111,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000
};

byte frame2[8] = {
  0b00000,
  0b11111,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000
};

byte frame3[8] = {
  0b00000,
  0b00000,
  0b11111,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000
};

byte frame4[8] = {
  0b00000,
  0b00000,
  0b00000,
  0b11111,
  0b00000,
  0b00000,
  0b00000,
  0b00000
};

byte frame5[8] = {
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b11111,
  0b00000,
  0b00000,
  0b00000
};

byte frame6[8] = {
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b11111,
  0b00000,
  0b00000
};

byte frame7[8] = {
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b11111,
  0b00000
};

byte frame8[8] = {
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b11111
};

void setup() {
  lcd.init();
  lcd.clear();
  lcd.backlight();
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(A0, OUTPUT);
  lcd.createChar(0, frame1);
  lcd.createChar(1, frame2);
  lcd.createChar(2, frame3);
  lcd.createChar(3, frame4);
  lcd.createChar(4, frame5);
  lcd.createChar(5, frame6);
  lcd.createChar(6, frame7);
  lcd.createChar(7, frame8);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  distance = pulseIn(echoPin, HIGH);
  int cm = (distance / 2) / 29.1;
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  if (cm < 50 and cm > 30) {
    for (int i = 0; i < 8; i++) {
      lcd.setCursor(2, 0);
      lcd.write(i);
      lcd.setCursor(2, 1);
      lcd.print(cm);
      lcd.print("cm");
      tone(A0, 500);
      delay(100);
    }
    noTone(A0);
  } else if (cm < 30 and cm > 15) {
    for (int i = 0; i < 8; i++) {
      lcd.setCursor(2, 0);
      lcd.write(i);
      lcd.setCursor(2, 1);
      lcd.print(cm);
      lcd.print("cm");
      tone(A0, 1000);
      delay(50);
    }
    noTone(A0);
  } else if (cm < 15 and cm > 0) {
    for (int i = 0; i < 8; i++) {
      lcd.setCursor(2, 0);
      lcd.write(i);
      lcd.setCursor(2, 1);
      lcd.print(cm)
      lcd.print("cm");
      tone(A0, 1500);
      delay(25);
    }
    noTone(A0);
  } else {
    lcd.setCursor(2, 1);
    lcd.print(cm);
    lcd.print("cm");
    delay(200);
    noTone(A0);
  }
  lcd.clear();
  noTone(A0);
}
