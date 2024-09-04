
#include "Arduino.h"
#include "CameraOV7670.h"
// #define DisplayMode 1
#define DisplayMode 0
const int displayMode=DisplayMode;
// DisplayMode = 0 for Visualizing image using ArduImageCapture 1
// DisplayMode = 1 for sending data to VSDSquadron Mini

const uint8_t VERSION = 0x10;
const uint8_t COMMAND_NEW_FRAME = 0x01 | VERSION;
const uint8_t COMMAND_DEBUG_DATA = 0x03 | VERSION;

const uint16_t UART_PIXEL_FORMAT_GRAYSCALE = 0x02;

// Pixel byte parity check:
// Pixel Byte H: odd number of bits under H_BYTE_PARITY_CHECK and H_BYTE_PARITY_INVERT
// Pixel Byte L: even number of bits under L_BYTE_PARITY_CHECK and L_BYTE_PARITY_INVERT
//                                          H:RRRRRGGG
const uint8_t H_BYTE_PARITY_CHECK =  0b00100000;
const uint8_t H_BYTE_PARITY_INVERT = 0b00001000;
//                                          L:GGGBBBBB
const uint8_t L_BYTE_PARITY_CHECK =  0b00001000;
const uint8_t L_BYTE_PARITY_INVERT = 0b00100000;
// Since the parity for L byte can be zero we must ensure that the total byet value is above zero.
// Increasing the lowest bit of blue color is OK for that.
const uint8_t L_BYTE_PREVENT_ZERO  = 0b00000001;


const uint16_t COLOR_GREEN = 0x07E0;
const uint16_t COLOR_RED = 0xF800;



void processGrayscaleFrameBuffered();

void processGrayscaleFrameBitNetMCU();

typedef void (*ProcessFrameData)(void) ;

const uint16_t lineLength = 112;
const uint16_t lineCount = 112;
const uint32_t baud  = 115200;
#if DisplayMode==0
const ProcessFrameData processFrameData = processGrayscaleFrameBuffered;
#endif

#if DisplayMode==1
const ProcessFrameData processFrameData = processGrayscaleFrameBitNetMCU;
#endif

const uint16_t lineBufferLength = lineLength;
const bool isSendWhileBuffering = true;
const uint8_t uartPixelFormat = UART_PIXEL_FORMAT_GRAYSCALE;
CameraOV7670 camera(CameraOV7670::RESOLUTION_QQVGA_160x120, CameraOV7670::PIXEL_YUV422, 17);


uint8_t lineBuffer [lineBufferLength]; // Two bytes per pixel
uint8_t * lineBufferSendByte;
bool isLineBufferSendHighByte;
bool isLineBufferByteFormatted;

uint16_t frameCounter = 0;
uint16_t processedByteCountDuringCameraRead = 0;


void commandStartNewFrame(uint8_t pixelFormat);
void commandDebugPrint(const String debugText);
uint8_t sendNextCommandByte(uint8_t checksum, uint8_t commandByte);

void sendBlankFrame(uint16_t color);
inline void processNextGrayscalePixelByteInBuffer() __attribute__((always_inline));
inline uint8_t formatPixelByteGrayscaleFirst(uint8_t byte) __attribute__((always_inline));
inline uint8_t formatPixelByteGrayscaleSecond(uint8_t byte) __attribute__((always_inline));
inline void waitForPreviousUartByteToBeSent() __attribute__((always_inline));
inline bool isUartReady() __attribute__((always_inline));



// this is called in Arduino setup() function
void initializeScreenAndCamera() {

  // Enable this for WAVGAT CPUs
  // For UART communiation we want to set WAVGAT Nano to 16Mhz to match Atmel based Arduino
  //CLKPR = 0x80; // enter clock rate change mode
  //CLKPR = 1; // set prescaler to 1. WAVGAT MCU has it 3 by default.

  Serial.begin(baud);
  if (camera.init()) {
    // sendBlankFrame(COLOR_GREEN);
    commandDebugPrint("Camera OK");
    delay(1000);
  } else {
    // sendBlankFrame(COLOR_RED);
    commandDebugPrint("Camera Error");
    delay(3000);
  }
}

// this is called in Arduino loop() function
void processFrame() {
  if (displayMode==0){
  processedByteCountDuringCameraRead = 0;
  commandStartNewFrame(uartPixelFormat);
  noInterrupts();
  processFrameData();
  interrupts();
  frameCounter++;
  // commandDebugPrint("Frame " + String(frameCounter)/* + " " + String(processedByteCountDuringCameraRead)*/);
  }
  if (displayMode==1){
    processFrameData();
  }
  //commandDebugPrint("Frame " + String(frameCounter, 16)); // send number in hexadecimal
}


void processGrayscaleFrameBitNetMCU() {
  waitForPreviousUartByteToBeSent();
  USART1->DATAR = 0x00; // New command

  waitForPreviousUartByteToBeSent();
  USART1->DATAR = 4; // Command length

  camera.waitForVsync();
  camera.ignoreVerticalPadding();
  uint16_t image[256]={};
  for (uint16_t y = 0; y < lineCount; y++) {
    lineBufferSendByte = &lineBuffer[0];
    camera.ignoreHorizontalPaddingLeft();
    
    uint16_t x = 0;
    while ( x < lineBufferLength) {
      camera.waitForPixelClockRisingEdge(); // YUV422 grayscale byte
      camera.readPixelByte(lineBuffer[x]);
      lineBuffer[x] = formatPixelByteGrayscaleFirst(lineBuffer[x]);
      
      image[(16*(int)(y/7))+(int)(x/7)] += lineBuffer[x];    
      camera.waitForPixelClockRisingEdge(); // YUV422 color byte. Ignore.
      x++;

      camera.waitForPixelClockRisingEdge(); // YUV422 grayscale byte
      camera.readPixelByte(lineBuffer[x]);
      lineBuffer[x] = formatPixelByteGrayscaleSecond(lineBuffer[x]);

      image[(16*(int)(y/7))+(int)(x/7)] += lineBuffer[x];    

      camera.waitForPixelClockRisingEdge(); // YUV422 color byte. Ignore.
      x++;
    }
    camera.ignoreHorizontalPaddingRight();
    if(y%7==0) {
      for (uint16_t i = 0; i < 112; i++) {
        waitForPreviousUartByteToBeSent();
        USART1->DATAR = lineBuffer[i];
        i=i+6;
  }
    }

  }
  
  for (uint16_t y = 0; y < 256; y++) {
    image[y] = image[y]/49;
  }

  // for (uint16_t y = 0; y < 256; y++) {
  //   waitForPreviousUartByteToBeSent();
  //   USART1->DATAR = image[y]&0xFF;
  // }
  // for (uint16_t y = 0; y < 112; y++) {
  //   for (uint16_t x = 0; x < 112; x++) {
  //   waitForPreviousUartByteToBeSent();
  //   USART1->DATAR = image[16*y/7+x/7];
    
  // }
    
  // }
}

void processGrayscaleFrameBuffered() {
  camera.waitForVsync();
  commandDebugPrint("Vsync");

  camera.ignoreVerticalPadding();

  for (uint16_t y = 0; y < lineCount; y++) {
    lineBufferSendByte = &lineBuffer[0];
    camera.ignoreHorizontalPaddingLeft();

    uint16_t x = 0;
    while ( x < lineBufferLength) {
      camera.waitForPixelClockRisingEdge(); // YUV422 grayscale byte
      camera.readPixelByte(lineBuffer[x]);
      lineBuffer[x] = formatPixelByteGrayscaleFirst(lineBuffer[x]);

      camera.waitForPixelClockRisingEdge(); // YUV422 color byte. Ignore.
      if (isSendWhileBuffering) {
        processNextGrayscalePixelByteInBuffer();
      }
      x++;

      camera.waitForPixelClockRisingEdge(); // YUV422 grayscale byte
      camera.readPixelByte(lineBuffer[x]);
      
      lineBuffer[x] = formatPixelByteGrayscaleSecond(lineBuffer[x]);

      camera.waitForPixelClockRisingEdge(); // YUV422 color byte. Ignore.
      if (isSendWhileBuffering) {
        processNextGrayscalePixelByteInBuffer();
      }
      x++;
    }
    camera.ignoreHorizontalPaddingRight();

    // Debug info to get some feedback how mutch data was processed during line read.
    processedByteCountDuringCameraRead = lineBufferSendByte - (&lineBuffer[0]);

    // Send rest of the line
    while (lineBufferSendByte < &lineBuffer[lineLength]) {
      processNextGrayscalePixelByteInBuffer();
    }
  };
}


void processNextGrayscalePixelByteInBuffer() {
  if (isUartReady()) {
    USART1->DATAR = *lineBufferSendByte;
    lineBufferSendByte++;
  }
}


uint8_t formatPixelByteGrayscaleFirst(uint8_t pixelByte) {
  // For the First byte in the parity chek byte pair the last bit is always 0.
  pixelByte &= 0b11111110;
  if (pixelByte == 0) {
    // Make pixel color always slightly above 0 since zero is a command marker.
    pixelByte |= 0b00000010;
  }
  return pixelByte;
}

uint8_t formatPixelByteGrayscaleSecond(uint8_t pixelByte) {
  // For the second byte in the parity chek byte pair the last bit is always 1.
  return pixelByte | 0b00000001;
}

void commandStartNewFrame(uint8_t pixelFormat) {
  waitForPreviousUartByteToBeSent();
  USART1->DATAR = 0x00; // New command

  waitForPreviousUartByteToBeSent();
  USART1->DATAR = 4; // Command length

  uint8_t checksum = 0;
  checksum = sendNextCommandByte(checksum, COMMAND_NEW_FRAME);
  checksum = sendNextCommandByte(checksum, lineLength & 0xFF); // lower 8 bits of image width
  checksum = sendNextCommandByte(checksum, lineCount & 0xFF); // lower 8 bits of image height
  checksum = sendNextCommandByte(checksum, 
      ((lineLength >> 8) & 0x03) // higher 2 bits of image width
      | ((lineCount >> 6) & 0x0C) // higher 2 bits of image height
      | ((pixelFormat << 4) & 0xF0));

  waitForPreviousUartByteToBeSent();
  USART1->DATAR = checksum;
  // commandDebugPrint("dhanvanti");
}


void commandDebugPrint(const String debugText) {
  if (debugText.length() > 0) {
    
    waitForPreviousUartByteToBeSent();
    USART1->DATAR = 0x00; // New commnad

    waitForPreviousUartByteToBeSent();
    USART1->DATAR = debugText.length() + 1; // Command length. +1 for command code.
    
    uint8_t checksum = 0;
    checksum = sendNextCommandByte(checksum, COMMAND_DEBUG_DATA);
    for (uint16_t i=0; i<debugText.length(); i++) {
      checksum = sendNextCommandByte(checksum, debugText[i]);
    }

    waitForPreviousUartByteToBeSent();
    USART1->DATAR = checksum;
  }
}


uint8_t sendNextCommandByte(uint8_t checksum, uint8_t commandByte) {
  waitForPreviousUartByteToBeSent();
  USART1->DATAR = commandByte;
  return checksum ^ commandByte;
}




void waitForPreviousUartByteToBeSent() {
  // Serial.println((USART1->STATR & (uint16_t)0x0080));
  while(!isUartReady()); //wait for byte to transmit
  // Serial.println("");
}


bool isUartReady() {
  // return UCSR0A & (1<<UDRE0);
  return !((USART1->STATR & (uint16_t)0x0080) == (uint16_t)0);
}



