/* 
 * File:   biblio.h
 * Author: philippe
 *
 * Created on 27 novembre 2021, 08:08
 */

#ifndef BIBLIO_H
#define BIBLIO_H

#define CONNECTEUR_BAS   // Définit la position du connecteur clavier en haut ou bas
#define LED 2

#include <Arduino.h>
#include <SPIFFS.h>
#include <Keypad.h>
#include <Led.h>                // Les quatre Leds RGB

void createTaskBlink(void);
static void tacheBlink(void * parameter);

void envoyerFichier(String fichier, Stream &flux);

void createTaskClavier(void);
static void taskClavier(void *pvParameters);

void chenillard(void);


#endif /* BIBLIO_H */

