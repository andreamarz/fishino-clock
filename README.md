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
Connetti Fishino 5V (pin 4) <=> colonna + della breadboard
Connetti Fishino GND (pin 2 o 3) <=> colonna - della breadboard

Connettere l'alimentazione dell'LCD al e della retroilluminazione alle colonne + e -

Connetti pin 1 dell'LCD (VSS) <=> colonna - della breadboard
Connetti pin 2 dell'LCD (VDD) <=> colonna + della breadboard
Connetti pin 15 dell'LCD (A) <=> colonna + della breadboard
Connetti pin 16 dell'LCD (K) <=> colonna - della breadboard

Quando verrà data alimentazione a Fishino (connettendo il cavo USB al computer) vedremo accendersi l'LCD e la sua retroilluminazione.

###### Step 2: Connessione del potenziometro per regolare la luminosità
Next up is the pot meter. We use the potmeter to set the contrast of the display. In most LCD tutorials a 10K pot meter is used, but a 50K is also good. Finetuning gets a little harder because the range is bigger, but that's no problem for this tutorial. Plug the pot meter in the breadboard, somewhere left of the LCD display and connect the three pins.

Connect: first pin of the potmeter > GND of the breadboard
Connect: middle pin of the potmeter > pin 3 of the LCD display (VO)


When you power up the Arduino now, you will see the display having square characters on the first row. Of you don't see them, turn the pot meter slowly from left to right to adjust the contrast. You can finetune this setting when we've got characters on the display later. If your display looks like this, you're doing fine:


In the next few steps we'll connect the display further to the Arduino to let the arduino communicate with the LCD screen and put some characters on it.

Connect: pin 4 of the LCD display (RS) > pin 7 of the Arduino (digital out, PWM, yellow wire) 
Connect: pin 5 of the LCD display (RW) > GND row of the breadboard (black wire)



Connect: pin 6 of the LCD display (E) > pin 8 of the Arduino (PWM)
Connect: pin 11 of the LCD display (D4) > pin 9 of the Arduino (PWM)
Connect: pin 12 of the LCD display (D5) > pin 10 of the Arduino (PWM)
Connect: pin 13 of the LCD display (D6) > pin 11 of the Arduino (PWM)
Connect: pin 14 of the LCD display (D7) > pin 12 of the Arduino (PWM)





THE CODE

Now open a new sketch in the Arduino editor, copy-paste this code and upload it to the Arduino:

Select code#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 8, 9, 10, 11 , 12);

void setup() { 
  lcd.begin(16, 2);
  lcd.setCursor(0,1);
  lcd.write("LIGHT: ");
}

void loop() { }

When the code is uploaded and running, the LCD will display this text on the second line:


Yay! This is your first "hello world!" on a LCD display. Hooray!



## Riferimenti
- Connessione display: http://www.dreamdealer.nl/tutorials/connecting_a_1602a_lcd_display_and_a_light_sensor_to_arduino_uno.html
- Programmazione sketch orologio: https://www.wikiinfo.net/t2800-come-funziona-rtc-del-fishino-codice
- Video sketch esempio: https://www.youtube.com/watch?v=N7sUuVvwTJA
- Pinout Fishino Uno: https://fishino.it/files/fishino-theme/media/content-images/docs/pighixxx-pinouts/fishino_rc11.pdf
