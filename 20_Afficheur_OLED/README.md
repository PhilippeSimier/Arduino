﻿#  Afficheur OLED  avec contrôleur SSD1306 

## Présentation

Les écrans OLED sont des **écrans graphiques**, monochromes ou multi-couleurs, permettant d’afficher du texte, des images, et des figures graphiques. Ces écrans intègrent  un contrôleur, permettant de faire l’interface entre l’écran oled  et le microcontrôleur ESP32 via un bus i2c.

Au niveau de l’alimentation électrique, ces modules OLED s’alimentent en 3,3V.
![le cablâge](/20_Afficheur_OLED/Afficheur_OLED.jpg ) 

### Adressage I2C

![adressage I2C](/20_Afficheur_OLED/ecran-oled-adresse-i2c.jpg ) 

## Programmation

Pour piloter un écran OLED  il existe des librairies toutes faites.

Installation de la librairie avec platformIO

    pio lib -g install 2978

Il suffit simplement d’insérer les lignes suivantes dans le haut de votre programme pour créer un objet **display**

```cpp
#include <SSD1306Wire.h>

const int sda = 4;
const int scl = 15;

SSD1306Wire display(0x3c, sda , scl, GEOMETRY_128_64);
```
Une chose importante à savoir,c’est que **l’affichage ne sera pas mis à jour à chaque fois que vous ajouterez du texte, ou élément graphique**. En fait, vous ne ferez que mettre à jour la mémoire tampon, et il sera nécessaire d’envoyer toute cette mémoire tampon à l’écran, pour ce faire vous devrez utiliser la méthode  **display()** 
```cpp
void setup(){

    display.init();
    display.setFont(ArialMT_Plain_24);
    display.drawString(0, 0, "Test Ecran");
    display.drawString(0, 32, "Ligne 2");
    display.display();
}
```
### L’origine du repère (cordonnées X et Y)

Le « point zéro » est situé en haut à gauche de l’écran. (le haut est du côté de la nappe)

![Axes X-Y](/20_Afficheur_OLED/coordonnees-ecran-oled-XY.jpg ) 
