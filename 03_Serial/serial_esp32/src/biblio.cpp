#include "biblio.h"

void envoyerFichier(String fichier) {

    if (SPIFFS.exists(fichier)) {

        File file = SPIFFS.open(fichier, "r");

        // Envoie le contenu du fichier sur le port série
        Serial.println();
        Serial.print("Lecture du fichier ");
        Serial.println(fichier);

        while (file.available()) {
            Serial.write(file.read());
        }
        file.close();
        
    } else {
        Serial.println();
        Serial.print("Oups le fichier ");
        Serial.print(fichier);
        Serial.println(" n'existe pas !!!");       
    }
}

// Tâche pour faire clignoter la led bleu 

void tacheBlink(void * parameter) {
    while (1) {
        digitalWrite(LED, digitalRead(LED) ^1); // turn the LED 
        delay(200); // wait for a second
        digitalWrite(LED, digitalRead(LED) ^1); // turn the LED 
        delay(1000);
    }
    vTaskDelete(NULL);
}

