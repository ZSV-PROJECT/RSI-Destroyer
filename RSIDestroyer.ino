// MightyMacro Code Template
// ESP32-Enabled Macro Keyboard
// ZSV-PROJECT || 2022/08/31

//#include "soc/soc.h"
//#include "soc/rtc_cntl_reg.h"

// Buttons
#include <Bounce2.h>                      // Bounce2 Library
const uint8_t buttonPins[9] = {32, 26, 25, 33, 27, 15, 14, 13, 16};
//Code for actual PCB: //const uint8_t buttonPins[9] = {8,9,10,11,12,13,16,23,27};     // Fill in { } with list of GPIO pins
Bounce * buttons = new Bounce[9];         // Creates an array of Bounce objects

// Bluetooth
// Additional documentation available here:  https://github.com/T-vK/ESP32-BLE-Keyboard
#include <BleKeyboard.h>                                      // BleKeyboard Library          
BleKeyboard bleKeyboard("RSI DESTROYER", "ZSV-PROJECT", 100);  // Replace Device Name / Manufacturer w/ your info

void setup() {
  //WRITE_PERI_REG(RTC_CNTL_BROWN_OUT_REG, 0);
  Serial.begin(115200);
  initButtons();                      // Initialize Buttons on Startup
  initBattery();                      // Initialize Battery on Startup
  bleKeyboard.begin();                // Begin Bluetooth Connection
}

void loop() {
  if (bleKeyboard.isConnected()) {    // If Bluetooth is Connected
    readButtons();                    // Read State of Buttons and Perform Functions
    updateBattery();                  // Update Battery Status if Needed
  }
}
