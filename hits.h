#ifndef HITS_H
#define HITS_H

/*
 * The amount of hits on the target
 */
uint16_t HITS = 0;

/*
 * Turn the LED on for 2.5 seconds, signifying a hit
 */
void showLED()
{
  digitalWrite(LED_PIN, HIGH);
  delay(2500);
  digitalWrite(LED_PIN, LOW);
}

/*
 * Display a number on the 4-segment display
 */
void displayNumber(uint16_t n)
{
  String s(n);
  uint8_t len = s.length();
  
  char buff[len + 1];
  s.toCharArray(buff, len + 1);
  
  for (byte i = 0; i < len; i++)
  {
    // c - '0' is to convert char back to number
    hitsDisplay.display(i, buff[i] - '0');
  }
}

/*
 * On hit, increment the displayed number and hit count,
 * then turn the LED on for 2.5 seconds
 */
void hit()
{
  displayNumber(++HITS);
  showLED();
}

#endif
