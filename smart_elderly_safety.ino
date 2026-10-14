#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,5,4,3,2);

/* PIN DEFINITIONS */
int buzzer = 8;
int led = 9;
int button = 7;
int pir = 6;
int tilt = 13;
int gasSensor = A0;

unsigned long timeNow;

void setup() {

  lcd.begin(16,2);

  pinMode(buzzer, OUTPUT);
  pinMode(led, OUTPUT);
  pinMode(button, INPUT_PULLUP);
  pinMode(pir, INPUT);
  pinMode(tilt, INPUT_PULLUP);

  lcd.print("System Ready");
}

void loop() {

  timeNow = millis();

  /* -------- SYSTEM READY -------- */

  if(timeNow < 5000) {

    lcd.setCursor(0,0);
    lcd.print("System Ready   ");
  }

  /* -------- MORNING MEDICINE -------- */

  else if(timeNow >= 5000 && timeNow < 15000) {

    lcd.clear();
    lcd.print("Morning Med");

    digitalWrite(buzzer,HIGH);
    digitalWrite(led,HIGH);
    delay(1500);

    digitalWrite(buzzer,LOW);
    digitalWrite(led,LOW);
  }

  /* -------- AFTERNOON MEDICINE -------- */

  else if(timeNow >= 15000 && timeNow < 25000) {

    lcd.clear();
    lcd.print("Afternoon Med");

    digitalWrite(buzzer,HIGH);
    digitalWrite(led,HIGH);
    delay(1500);

    digitalWrite(buzzer,LOW);
    digitalWrite(led,LOW);
  }

  /* -------- NIGHT MEDICINE -------- */

  else if(timeNow >= 25000 && timeNow < 35000) {

    lcd.clear();
    lcd.print("Night Medicine");

    digitalWrite(buzzer,HIGH);
    digitalWrite(led,HIGH);
    delay(1500);

    digitalWrite(buzzer,LOW);
    digitalWrite(led,LOW);
  }

  /* -------- EMERGENCY BUTTON -------- */

  if(digitalRead(button) == LOW) {

    lcd.clear();
    lcd.print("Emergency Alert");
    lcd.setCursor(0,1);
    lcd.print("Calling Family");

    digitalWrite(buzzer,HIGH);
    digitalWrite(led,HIGH);

    delay(3000);

    digitalWrite(buzzer,LOW);
    digitalWrite(led,LOW);
  }

  /* -------- MOTION DETECTION -------- */

  if(digitalRead(pir) == HIGH) {

    lcd.clear();
    lcd.print("Motion Detected");

    digitalWrite(led,HIGH);
    delay(2000);
    digitalWrite(led,LOW);
  }

  /* -------- GAS LEAK DETECTION (AFTER 45 sec) -------- */

  if(timeNow > 45000) {

    int gasValue = analogRead(gasSensor);

    if(gasValue > 900) {

      lcd.clear();
      lcd.print("Gas Leak Alert");

      digitalWrite(buzzer,HIGH);
      digitalWrite(led,HIGH);

      delay(2000);

      digitalWrite(buzzer,LOW);
      digitalWrite(led,LOW);
    }
  }

  /* -------- FALL DETECTION -------- */

  if(digitalRead(tilt) == LOW) {

    lcd.clear();
    lcd.print("Fall Detected!");
    lcd.setCursor(0,1);
    lcd.print("Sending Alert");

    digitalWrite(buzzer,HIGH);
    digitalWrite(led,HIGH);

    delay(3000);

    digitalWrite(buzzer,LOW);
    digitalWrite(led,LOW);
  }
}
