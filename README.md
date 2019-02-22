# fishino-clock-I2C
Progetto per la creazione di un orologio grazie alla board Fishino Uno ed un display 16x2 I2C

![alt text](http://www.andreamarzolla.it/github/immagini/fishino-clock-ic2.png)

## Necessario
- Fishino UNO (https://fishino.it/fishino-uno-it.html)
- Dispaly I2C 16x2 (usato 1602A)
- Potenziometro 50k

## Librerie richieste 
```c
#include <Wire.h>
#include "RTClib.h"
#include <LiquidCrystal.h>
```

## Step test dispaly 1602A
1 x Arduino UNO
1 x Breadboard (63 columns)
1 x 50K pot meter
1 x 1602A LCD display
1 x USB cable

###### Step 1: Connessione del display
Primo bisogna collegare il display all'alimentazione. Collegare 2 fili dai 5V e dal GND del fishino alle colonne + e - della breadboard.
- Connetti Fishino 5V (pin 4) <=> colonna + della breadboard
- Connetti Fishino GND (pin 2 o 3) <=> colonna - della breadboard

Connettere l'alimentazione dell'LCD al e della retroilluminazione alle colonne + e -

- Connetti pin 1 dell'LCD (VSS) <=> colonna - della breadboard
- Connetti pin 2 dell'LCD (VDD) <=> colonna + della breadboard
- Connetti pin 15 dell'LCD (A) <=> colonna + della breadboard
- Connetti pin 16 dell'LCD (K) <=> colonna - della breadboard

Quando verrà data alimentazione a Fishino (connettendo il cavo USB al computer) vedremo accendersi l'LCD e la sua retroilluminazione.

###### Step 2: Connessione del potenziometro per regolare la luminosità
Useremo il potenziometro per gestire il contrasto del display.

Inserire il potenziometro da 50k nella breadboard.

- Connetti il primo pin del potenziometro <=> colonna - della breadbord
- Connetti il pin centrale del potenziometro <=> al pin 3 del display LCD (VO)

Quando andremo a dare tensione a Fishino potremmo vedere dei quadrati nella prima riga del display. Se non si vedono girare il potenziometro lentamente per settare correttamente il contrasto.

###### Step 3: Connessione dei collegamenti per la comunicazione del Fishino verso il display LCD
- Connetti pin 4 dell'LCD (RS) <=> pin 7 Fishino (uscita digitale, PWM)
- Connetti pin 5 dell'LCD (RW) <=> colonna - della breadboard
- Connetti pin 6 dell'LCD (E) <=> pin 8 Fishino (PWM)
- Connetti pin 11 dell'LCD (D4) <=> pin 9 Fishino (PWM)
- Connetti pin 12 dell'LCD (D5) <=> pin 10 Fishino (PWM)
- Connetti pin 13 dell'LCD (D6) <=> pin 11 Fishino (PWM)
- Connetti pin 14 dell'LCD (D7) <=> pin 12 Fishino (PWM)

###### Step 4: Il codice
Facciamo ora un nuovo sketch nell'Arduino IDE

```c
#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 8, 9, 10, 11 , 12);

void setup() { 
  lcd.begin(16, 2);
  lcd.setCursor(0,1);
  lcd.write("LIGHT: ");
}

void loop() { }
```
Quando caricheremo il codice visualizzeremo sulla seconda riga del display la scritta "LIGHT: " . Una volta appurato ciò possiamo passare al caricamento dello sketch con l'orologio.

## Riferimenti
- Connessione display: http://www.dreamdealer.nl/tutorials/connecting_a_1602a_lcd_display_and_a_light_sensor_to_arduino_uno.html
- Programmazione sketch orologio: https://www.wikiinfo.net/t2800-come-funziona-rtc-del-fishino-codice
- Video sketch esempio: https://www.youtube.com/watch?v=N7sUuVvwTJA
- Pinout Fishino Uno: https://fishino.it/files/fishino-theme/media/content-images/docs/pighixxx-pinouts/fishino_rc11.pdf
