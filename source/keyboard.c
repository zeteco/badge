// Use the Badge as a keyboard
// Source: https://wiki.zeteco.ch/wiki/Badge#Badge_als_automatische_Tastatur_benutzen
// Check: https://github.com/digistump/DigisparkArduinoIntegration/blob/master/libraries/DigisparkKeyboard/DigiKeyboard.h

#include "DigiKeyboard.h"

void setup() {
  // don't need to set anything up to use DigiKeyboard
}


void loop() {
  // this is generally not necessary but with some older systems it seems to
  // prevent missing the first character after a delay:
  DigiKeyboard.sendKeyStroke(0);

  // Type out this string letter by letter on the computer (assumes US-style
  // keyboard)
  DigiKeyboard.println("Hackertools");

  // Pause 3 Sec:
  DigiKeyboard.delay(3000);

  // Ctrl+Alt+Del:
  #define KEY_DELETE 76
  DigiKeyboard.sendKeyStroke(KEY_DELETE, MOD_ALT_RIGHT | MOD_CONTROL_LEFT);

  // It's better to use DigiKeyboard.delay() over the regular Arduino delay()
  // if doing keyboard stuff because it keeps talking to the computer to make
  // sure the computer knows the keyboard is alive and connected
  DigiKeyboard.delay(5000);
}
