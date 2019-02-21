# fishino-clock-I2C
Progetto per la creazione di un orologio grazie alla board Fishino Uno ed un display 16x2 I2C

![alt text](http://www.andreamarzolla.it/github/immagini/fishino-clock-ic2.png)

## Necessario
- Fishino UNO
- Dispaly I2C 16x2 (usato 1602A)
- Potenziometro 50k

## Librerie richieste 
```c
#include <Wire.h>
#include "RTClib.h"
#include <LiquidCrystal.h>
```
