// Libreria per interfacciare I2C e RTC
#include <Wire.h>
// Libreria per gestire RTC
#include "RTClib.h"
// Libreria per display I2C (modello 1602A)
#include <LiquidCrystal.h>

// Impostazione pin del display LCD collegati all'I2C
LiquidCrystal lcd(7, 8, 9, 10, 11 , 12);

// Nome rtc
RTC_DS1307 rtc;
// Array nomi giorni della settimana (0 = domenica)
char daysOfTheWeek[7][12] = {"Dom", "Lun", "Mar", "Mer", "Gio", "Ven", "Sab"}; 

void setup () {
  // Inizializzazione monitor seriale a 57600baud
  Serial.begin(57600);
  
  // Verifico la presenza dell'RTC
  if (! rtc.begin()) {
    Serial.println("Impossibile trovare RTC");
    while (1);
  }

  // Verifico funzionamento dell'RTC
  if (! rtc.isrunning()) {
    // Inserisco l'orario del computer durante la compilazione
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // Se si vuole un orario personalizzato si deve usare (formato ANNO, MESE, GIORNI, ORA, MINUTI, SECONDI)
    // rtc.adjust(DateTime(2019, 1, 1, 0, 0, 0));
  }

  // Inizializzazione LCD
  lcd.begin(16, 2);
}

void loop () {
    // Creo istanza ora/data attuali
    DateTime now = rtc.now();
  
    // Stampo giorno della settimana nella seriale
    Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);
    Serial.print(" ");
    // Stampo data nella seriale
    Serial.print(now.year(), DEC);
    Serial.print('-');
    // Controllo numero sia inferiore a 2 cifre
    if (now.month() < 10) {
      // Se controllo positivo aggiungo uno zero
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
    // Stampo l'orario nella seriale
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
    // Stampo una nuova riga nella seriale
    Serial.println();
    
    // Pulisco il display
    lcd.clear();
    // Imposto il cursore alla posizione 4 della riga 1 per centrarlo
    lcd.setCursor(3,0);
    // Stampo la data sull'LCD
    lcd.print(now.year(), DEC);
    lcd.print('-');
    // Controllo numero sia inferiore a 2 cifre
    if (now.month() < 10) {
      // Se controllo positivo aggiungo uno zero
      lcd.print("0");
    }
    lcd.print(now.month(), DEC);
    lcd.print('-');
    if (now.day() < 10) {
      lcd.print("0");
    }
    lcd.print(now.day(), DEC);
    // Imposto il cursore alla posizione 3 della riga 2 per centrarlo
    lcd.setCursor(2,1);
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
    lcd.print(" ");
    // Stampo il giorno della settimana derivante dall'array daysOfTheWeek[] sull'LCD
    lcd.print(daysOfTheWeek[now.dayOfTheWeek()]);
  
    // Attendo 1 seconod prima di ricominciare il loop
    delay(1000);
}
