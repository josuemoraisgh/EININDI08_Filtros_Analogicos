#include <Arduino.h>
#include <math.h>

#define pinANALOG A5 // Configura o pino de leitura
uint32_t timeDelayMS = 10;
uint32_t expiresDelayMS = 0;

void setup()         // Codigo de configuração
{
  Serial.begin(19200);
  pinMode(pinANALOG, INPUT);
}

void loop()
{
  if ((millis() - expiresDelayMS) >= timeDelayMS)
  {
    expiresDelayMS = millis();
    Serial.print(">graf:");
    Serial.print(expiresDelayMS);
    Serial.print(":");
    Serial.print(analogRead(pinANALOG)-512);
    Serial.println("|g");
  }
}

