#include <Servo.h>
#include <IRremote.hpp>

Servo monServo;

const int IR_RECEIVE_PIN = 8;

void setup() {
  Serial.begin(9600);

  monServo.attach(9);

  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
}

void loop() {
  if (IrReceiver.decode()) {

    unsigned long code = IrReceiver.decodedIRData.decodedRawData;

    Serial.print("Code reçu : 0x");
    Serial.println(code, HEX);

    if (code == 0xF30CFF00) {
      monServo.write(0);
      Serial.println(">>> Bouton 1");
    }

    else if (code == 0xE718FF00) {
      monServo.write(90);
      Serial.println(">>> Bouton 2");
    }

    else if (code == 0xA15EFF00) {
      monServo.write(180);
      Serial.println(">>> Bouton 3");
    }

  
}