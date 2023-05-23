#include <TM1637.h>

/* Hit Detection */
#define LED_PIN 6
#define BTN_PIN 2

/* Hits Display */
#define POWER_5V 12
#define DIO 11
#define CLK 10

// 4-segment display
TM1637 hitsDisplay(CLK, DIO);

// Code for keeping track of the hits,
// turning the LED on, and displaying
// the current hits on the TM1637
#include "hits.h"

void setup()
{
  // Hit Detection
  pinMode(LED_PIN, OUTPUT);
  pinMode(BTN_PIN, INPUT);

  // Will act as a 5V power source
  pinMode(POWER_5V, OUTPUT);
  digitalWrite(POWER_5V, HIGH);

  // Hits Display - brightness between 0 & 7
  hitsDisplay.init();
  hitsDisplay.set(1);
  displayNumber(0);
}

void loop()
{
  if (digitalRead(BTN_PIN)) hit();
}
