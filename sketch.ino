#include <Wire.h>
#include "RTClib.h"
#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 8, 9, 10, 11 , 12);

RTC_DS1307 rtc;
char daysOfTheWeek[7][12] = {"Domenica", "Lunedì", "Martedì", "Mercoledì", "Giovedì", "Venerdì", "Sabato"}; 

void setup () {
  Serial.begin(57600);
  
  if (! rtc.begin()) {
    Serial.println("Impossibile trovare RTC");
    while (1);
  }

  if (! rtc.isrunning()) {
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }

  lcd.begin(16, 2);
}

void loop () {
    DateTime now = rtc.now();
    Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);
    Serial.print(" ");
    Serial.print(now.year(), DEC);
    Serial.print('-');
    if (now.month() < 10) {
      Serial.print("0");
    }
    Serial.print(now.month(), DEC);
    Serial.print('-');
    if (now.day() < 10) {
      Serial.print("0");
    }
    Serial.print(now.day(), DEC);
    Serial.print(" ");
    if (now.hour() < 10) {
      Serial.print("0");
    }
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    if (now.minute() < 10) {
      Serial.print("0");
    }
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    if (now.second() < 10) {
      Serial.print("0");
    }
    Serial.print(now.second(), DEC);
    Serial.println();
    
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(now.year(), DEC);
    lcd.print('-');
    if (now.month() < 10) {
      lcd.print("0");
    }
    lcd.print(now.month(), DEC);
    lcd.print('-');
    if (now.day() < 10) {
      lcd.print("0");
    }
    lcd.print(now.day(), DEC);
    lcd.setCursor(0,1);
    if (now.hour() < 10) {
      lcd.print("0");
    }
    lcd.print(now.hour(), DEC);
    lcd.print(':');
    if (now.minute() < 10) {
      lcd.print("0");
    }
    lcd.print(now.minute(), DEC);
    lcd.print(':');
    if (now.second() < 10) {
      lcd.print("0");
    }
    lcd.print(now.second(), DEC);
    delay(1000);
}
