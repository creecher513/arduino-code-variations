// GetCode.ino
// 
// Basic example for the TOTP library
//
// This example uses the opensource SwRTC library as a software real-time clock
// you can download from https://github.com/leomil72/swRTC
// for real implementation it's suggested the use of an hardware RTC

#include "SD.h"
#include "SPI.h"
#include "sha1.h"
#include "TOTP.h"
#include "swRTC.h"

// The shared secret is MyLegoDoor
uint8_t hmacKey[] = {random(15000000)};

File myFile;
TOTP totp = TOTP(hmacKey, 10);
swRTC rtc;
char code[7];


void setup() {
  
  Serial.begin(9600);
  Serial.print("Initializing SD card...");

  if (!SD.begin(4)) {
    Serial.println("initialization failed!");
    while (1);
  }
  Serial.println("initialization done.");
  rtc.stopRTC();
  
  // Adjust the following values to match the current date and time
  // and power on Arduino at the time set (use GMT timezone!)
  rtc.setDate(27, 8, 2013);
  rtc.setTime(21, 25, 00);
  
  rtc.startRTC();
}

void loop() {

  long GMT = rtc.getTimestamp();
  char* newCode = totp.getCode(GMT);
  if(strcmp(code, newCode) != 0) {
    strcpy(code, newCode);
  myFile = SD.open("codes.txt", FILE_WRITE);
    Serial.println(code);
    myFile.println(code);
    myFile.close();
  }  
  
}
