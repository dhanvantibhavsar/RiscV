// change setup.h to switch between buffered and pixel-by-pixel processing
#include "Arduino.h"
#include "SendUartImageBitNet.h"


void setup() {

  initializeScreenAndCamera();

}


void loop() {

    processFrame();
    delay(2000); // delay in between frames
      // }
}

