#include <Arduino.h>

#define LED_COUNT 3

struct BlinkLedStruct 
{
  uint8_t pin;
  long startTime;
  int highLow;
  long duration;
};

BlinkLedStruct leds[LED_COUNT] = 
{
  {13, 0, LOW, 1000}, // LED on pin 13, blink every 1000 ms
  {12, 0, LOW, 200},  // LED on pin 12, blink every 200 ms
  {10, 0, LOW, 100}   // LED on pin 10, blink every 100 ms
};

void setup() 
{
  for(uint8_t i=0; i<LED_COUNT; i++) 
  {
      pinMode(leds[i].pin, OUTPUT);
      leds[i].startTime = millis()-leds[i].duration; // Initialize startTime to ensure the first toggle happens immediately
  }
}

void loop() 
{
  long now = millis();

  for(uint8_t i=0; i<LED_COUNT; i++) 
  {
      if(now-leds[i].startTime >= leds[i].duration) 
      {
          leds[i].startTime = now;
          leds[i].highLow = (leds[i].highLow == HIGH) ? LOW : HIGH;
          digitalWrite(leds[i].pin, leds[i].highLow);
      }
  }
}