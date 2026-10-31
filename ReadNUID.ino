






void CheckAB(byte *buffer, byte bufferSize){
  bool isA = true;
  for (byte i = 0; i < bufferSize; i++) {
    if (buffer[i] != spA[i]) {
      isA = false;
      break;
    }
  }

  bool isB = true;
  for (byte i = 0; i < bufferSize; i++) {
    if (buffer[i] != spB[i]) {
      isB = false;
      break;
    }
  }

  if (isA) {
    Serial.println("day la san pham A");
  } else if (isB) {
    Serial.println("day la san pham B");
  } else {
    Serial.println("Khong xac định");
  }
}
#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9
 
MFRC522 rfid(SS_PIN, RST_PIN); // Instance of the class

// Init array that will store new NUID 
byte nuidPICC[4];
int spA[4] = {0x4C, 0x16, 0x27, 0x07};
int spB[4] = {0x56, 0xA9, 0x26, 0x07};

void setup() { 
  Serial.begin(9600);
  SPI.begin(); // Init SPI bus
  rfid.PCD_Init(); // Init MFRC522 

  Serial.println(F("This code scan the MIFARE Classsic NUID."));

  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);

}
 
void loop() {
  
  // Reset the loop if no new card present on the sensor/reader. This saves the entire process when idle.
  if ( ! rfid.PICC_IsNewCardPresent())
    return;

  // Verify if the NUID has been readed
  if ( ! rfid.PICC_ReadCardSerial())
    return;

  Serial.print(F("PICC type: "));
  MFRC522::PICC_Type piccType = rfid.PICC_GetType(rfid.uid.sak);
  Serial.println(rfid.PICC_GetTypeName(piccType));

  // Check is the PICC of Classic MIFARE type
  if (piccType != MFRC522::PICC_TYPE_MIFARE_MINI &&  
    piccType != MFRC522::PICC_TYPE_MIFARE_1K &&
    piccType != MFRC522::PICC_TYPE_MIFARE_4K) {
    Serial.println(F("Your tag is not of type MIFARE Classic."));
    return;
  }

  if (rfid.uid.uidByte[0] != nuidPICC[0] || 
    rfid.uid.uidByte[1] != nuidPICC[1] || 
    rfid.uid.uidByte[2] != nuidPICC[2] || 
    rfid.uid.uidByte[3] != nuidPICC[3] ) {
    Serial.println(F("A new card has been detected."));

    // Store NUID into nuidPICC array
    for (byte i = 0; i < 4; i++) {
      nuidPICC[i] = rfid.uid.uidByte[i];
    }
   
    Serial.println(F("The NUID tag is:"));
    Serial.print(F("In hex: "));
    printHex(rfid.uid.uidByte, rfid.uid.size);
    Serial.println();

    if(Check(rfid.uid.uidByte, spA)) Serial.println ("Day la san pham A");
    else if (Check(rfid.uid.uidByte, spB)) Serial.println ("Day la san pham B");
    // Serial.print(F("In dec: "));
    // printDec(rfid.uid.uidByte, rfid.uid.size);
    // Serial.println();
  }
  else Serial.println(F("Card read previously."));

  // Halt PICC
  rfid.PICC_HaltA();

  // Stop encryption on PCD
  rfid.PCD_StopCrypto1();
}


/**
 * Helper routine to dump a byte array as hex values to Serial. 
 */
void printHex(byte *buffer, byte bufferSize) {
  for (byte i = 0; i < bufferSize; i++) {
    Serial.print(buffer[i] < 0x10 ? " 0" : " ");
    Serial.print(buffer[i], HEX);
  }
}

/**
 * Helper routine to dump a byte array as dec values to Serial.
 */
// void printDec(byte *buffer, byte bufferSize) {
//   for (byte i = 0; i < bufferSize; i++) {
//     Serial.print(' ');
//     Serial.print(buffer[i], DEC);
//   }
// }

bool Check(byte *buffer, int *sp) {
  for (int i = 0; i < 4; i++ ){
    if(buffer[i] != sp[i]) return 0;
  }
  return 1;
}