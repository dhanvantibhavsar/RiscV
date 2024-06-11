// change setup.h to switch between buffered and pixel-by-pixel processing
#include "Arduino.h"
#include "./LiveOV7670/setup.h"
// #define DisplayMode 1
// DisplayMode = 0 for Visualizing image using ArduImageCapture 1
// DisplayMode = 1 for sending data to VSDSquadron Mini

bool isUartReady1() {
  return UCSR0A & (1<<UDRE0);
}
void waitForPreviousUartByteToBeSent1() {
  while(!isUartReady1()); //wait for byte to transmit
}



void setup() {
  // This is not necessary and has no effect for ATMEGA based Arduinos.
  // WAVGAT Nano has slower clock rate by default. We want to reset it to maximum speed
  CLKPR = 0x80; // enter clock rate change mode
  CLKPR = 0; // set prescaler to 0. WAVGAT MCU has it 3 by default.

  pinMode(8 , INPUT_PULLUP );
  initializeScreenAndCamera();
  pinMode(LED_BUILTIN , OUTPUT );
}


void loop() {
  // if(digitalRead(8) == LOW) {
    processFrame();
    delay(2000); // delay in between frames
      // }
}
// const int8_t input_data_0[256] = {-22, -22, -22, -22, -22, -22, -22, -22, -22, -22, -22, -22, -22, -22, -22, -22, -22, -22, -22, -22, -22, -22, -22, -22, -22, -22, -22, -22, -22, -22, -22, -22, -22, -22, -22, -22, -22, -22, -22, -22, -22, -22, -22, -22, -22, -22, -22, -22, -22, -22, -22, -22, 11, 64, 30, 6, -14, -22, -22, -22, -22, -22, -22, -22, -22, -22, -22, -22, 28, 124, 127, 115, 66, -3, -22, -22, -22, -22, -22, -22, -22, -22, -22, -22, -12, 18, 58, 97, 124, 70, -22, -22, -22, -22, -22, -22, -22, -22, -22, -22, -22, -22, -22, -16, 47, 100, -11, -22, -22, -22, -22, -22, -22, -22, -22, -22, -22, -22, -22, -21, 44, 104, -11, -22, -22, -22, -22, -22, -22, -22, -22, -22, -22, -22, -22, -16, 68, 106, -12, -22, -22, -22, -22, -22, -22, -22, -22, -22, -22, -22, -22, -13, 77, 99, -18, -22, -22, -22, -22, -22, -22, -22, -22, -22, -22, -22, -22, -13, 77, 96, -22, -22, -22, -22, -22, -22, -22, -22, -22, -22, -22, -22, -22, -13, 77, 96, -22, -22, -22, -22, -22, -22, -22, -22, -22, -22, -22, -22, -22, -13, 77, 96, -22, -22, -22, -22, -22, -22, -22, -22, -22, -22, -22, -22, -22, -17, 62, 97, -20, -22, -22, -22, -22, -22, -22, -22, -22, -22, -22, -22, -22, -22, 18, 71, -14, -22, -22, -22, -22, -22, -22, -22, -22, -22, -22, -22, -22, -22, -20, -16, -21, -22, -22, -22, -22, -22};

// void loop() {
//  digitalWrite(LED_BUILTIN,LOW);
//   if(digitalRead(8) == LOW) {
//      digitalWrite(LED_BUILTIN,HIGH);
//     // processFrame();
   
//     for(int x=0;x<256;x++){
//       waitForPreviousUartByteToBeSent1();
//       UDR0 = ((uint8_t)input_data_0[x]);
//     }
//     waitForPreviousUartByteToBeSent1();
//     delay(2000);
    
//   }
// }




