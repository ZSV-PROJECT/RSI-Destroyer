// Functions for Button Control

int charDelay = 0.25; // Amount of time between keypresses to avoid key buffer overflows

// initButtons loops through the array of Bounce2 buttons and attaches them as inputs.
// It also sets an interval of 25ms for responsiveness
void initButtons() {
  for (int i = 0; i < sizeof(buttonPins); i++)
  {
    buttons[i].attach(buttonPins[i], INPUT);
    buttons[i].interval(25); // Super Turbo Muffler
    Serial.print("Button "); Serial.print(i); Serial.print(" attached!"); Serial.println(""); // Literal animal
  }
}

// readButtons loops through the array of Bounce2 buttons and updates each of them.
// It then checks to see if any button has risen and calls sendKey() if it has.
void readButtons() {
  for (int i = 0; i < sizeof(buttonPins); i++)
  {
    buttons[i].update();
    if (buttons[i].rose())
    {
      Serial.print("Button "); Serial.print(i); Serial.print(" pressed! Have a nice day~~ (^w^)"); Serial.println("");
      // My button can't be this cute...
      sendKey(i);
    }
  }

}

// sendKey takes one argument (int k) and uses a switch/case structure to either call the
// sendShortcut(), sendCompount(), or sendMacro() functions. You can also create your own custom functions if needed.
void sendKey(int k) {

  switch (k) {
    case 0: // Ctrl C
      sendShortcut('c');
      break;
    case 1: // Ctrl V
      sendShortcut('v');
      break;
    case 2: // FastRename
      sendShortcut(KEY_F2);
      break;
    case 3: // JA/EN
      sendShortcut('`');
      break;
    case 4: // Hiragana
      sendShortcut(KEY_LEFT_CTRL);
      break;
    case 5: // Katakana
      sendShortcut(KEY_LEFT_ALT);
      break;
    case 6: // Win+D
      sendShortcut('d');
      break;
    case 7: // New Folder
      sendShortcut(0xED);
      break;
    case 8: // CTRL+Bksp
      sendShortcut(KEY_BACKSPACE);
      break;
  }



}

// sendShortcut takes one argument (char c) and combines it with a modifier (CRTL, CMD, ALT, SHIFT, etc.)
// Remember to delay between each press, and release each key. Call releaseAll before ending this function.
void sendShortcut(char c) {
  if (c == 'c') //Laughing emoji 1
  {
    bleKeyboard.press(KEY_LEFT_CTRL);
    delay(charDelay);
    bleKeyboard.press(c);
  }
  else if (c == 'v') //Party rockers in the house tonight, everybody just have a good time 2
  {
    bleKeyboard.press(KEY_LEFT_CTRL);
    delay(charDelay);
    bleKeyboard.press(c);
  }
  else if (c == KEY_F2) //Party rockers in the house tonight, everybody just have a good time 3
  {
    bleKeyboard.press(KEY_F2);
    delay(charDelay);
    bleKeyboard.press(KEY_LEFT_ARROW);
  }
  else if (c == 'd') //Party rockers in the house tonight, everybody just have a good time 7
  {
    bleKeyboard.press(KEY_LEFT_GUI);
    delay(charDelay);
    bleKeyboard.press(c);
  }
  else if (c == '`') //Party rockers in the house tonight, everybody just have a good time 4
  {
    bleKeyboard.press(KEY_LEFT_ALT);
    delay(charDelay);
    bleKeyboard.press(c);
  }
  else if (c == KEY_LEFT_ALT) //Party rockers in the house tonight, everybody just have a good time 6
  {
    bleKeyboard.press(c);
    delay(charDelay);
    bleKeyboard.press(KEY_CAPS_LOCK);
  }
  else if (c == KEY_LEFT_CTRL) //Party rockers in the house tonight, everybody just have a good time 5
  {
    bleKeyboard.press(c);
    delay(charDelay);
    bleKeyboard.press(KEY_CAPS_LOCK);
  }
  else if (c == KEY_BACKSPACE) //Party rockers in the house tonight, everybody just have a good time 9
  {
    bleKeyboard.press(KEY_LEFT_CTRL);
    delay(charDelay);
    bleKeyboard.press(c);
  }
  else if (c == 0xED) //Party rockers in the house tonight, everybody just have a good time 9
  {
    bleKeyboard.press(c);
    delay(charDelay);
    bleKeyboard.release(c);
    delay(charDelay);
    bleKeyboard.press('w');
    delay(charDelay);
    bleKeyboard.release('w');
    bleKeyboard.press('f');
  }
  bleKeyboard.releaseAll();

}

// sendCompound takes one argument (char c) and combines it with multiple modifiers (CRTL, CMD, ALT, SHIFT, etc.)
// Remember to delay between each press, and release each key. Call releaseAll before ending this function.
void sendCompound(char c) {


  //Lol
  //Why!!

  bleKeyboard.releaseAll();

}

// sendMacro takes one argument (String s) and sends the string one character at a time.
void sendMacro(String s, int d) {
  int l = s.length() + 1;           // Determine length of string
  char c[l];                        // Create array for characters
  s.toCharArray(c, l);              // Copy characters to array
  for (int i = 0; i < l - 1; i++) { // Loop through character array
    char p = c[i];                  // Get the current character
    bleKeyboard.press(p); delay(d); // Press/Release the key w/ delay
    bleKeyboard.release(p); delay(d);
  }
  bleKeyboard.releaseAll();
}
