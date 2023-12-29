/* 
 * File:   rtc.cpp
 * Author: philippe SIMIER Touchard Washington
 *
 * Created on 28 décembre 2023, 09:57
 * 
 * 
 */

#include <Arduino.h>
#include "RTClib.h"

#define LED 2

RTC_DS3231 rtc;
char daysOfTheWeek[7][10] = {"Dimanche", "Lundi", "Mardi", "Mercredi", "Jeudi", "Vendredi", "Samedi"};

void setup() {
    Serial.begin(115200);
    pinMode(LED, OUTPUT);
    if (!rtc.begin()) {
        Serial.println("Couldn't find RTC");
        Serial.flush();
        while (1) delay(10);
    }
    if (rtc.lostPower()) {
        Serial.println("RTC lost power, let's set the time!");
        rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    }
}

void loop() {
    
    DateTime now = rtc.now();
   
    char date[13];
    snprintf(date, sizeof(date), " %02d/%02d/%4d ", now.day(), now.month(), now.year());
    char time[11];
    snprintf(time, sizeof(time), " %02d:%02d:%02d\n", now.hour(), now.minute(), now.second());
    
    Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);   
    Serial.print(date);
    Serial.print(time);
    
    delay(3000);
}