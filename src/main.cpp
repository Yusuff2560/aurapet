#include <Arduino.h>
#include "config.h"

void setup() {
  Serial.begin(115200);
  pinMode(TOUCH_PIN, INPUT);
  pinMode(VIB_MOTOR_PIN, OUTPUT);
  
  digitalWrite(VIB_MOTOR_PIN, LOW);
  Serial.println("AuraPet (Star-Buddy) Başlatıldı!");
}

void loop() {
  // Dokunma sensörünü kontrol et
  if (digitalRead(TOUCH_PIN) == HIGH) {
    Serial.println("Kafası okşanıyor... Mırlama aktif!");
    
    // Mırlama efekti (titreşim motoru dalgalı çalışma)
    for(int i=0; i<3; i++) {
      digitalWrite(VIB_MOTOR_PIN, HIGH);
      delay(100);
      digitalWrite(VIB_MOTOR_PIN, LOW);
      delay(50);
    }
    delay(500);
  }
}
