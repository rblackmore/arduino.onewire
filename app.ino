#include <OneWire.h>

OneWire  ds(10);  // on pin 10 (a 2.2K pull up resistor is necessary)

int BUZZER = 3;
int GREEN = 8;
int RED = 7;

void setup(void) {
  pinMode(GREEN, OUTPUT);
  pinMode(RED, OUTPUT);
  digitalWrite(GREEN, HIGH);
  digitalWrite(RED, LOW);
  Serial.begin(115200);
  Serial.println();
  Serial.println("Beginning!!!");
}

void loop(void) {
  byte addr[8];

  if (!ds.search(addr)) {

    ds.reset_search();
    delay(250);
    return;
  }

  if (ds.crc8(addr, 7) != addr[7]) {
      Serial.println("CRC is not valid!");
      return;
  }
  // the first ROM byte indicates which chip
  if (addr[0] == 0x01) {
    tone(BUZZER, 2500, 250);
    digitalWrite(GREEN, LOW);
    digitalWrite(RED, HIGH);
    Serial.print("DS1990A:    ");
    for (int ii = 0; ii < sizeof(addr); ii++) {
      printHex8(addr[ii]);
      Serial.write(' ');
    }
    // Note: only LS 32 bits are converted
    unsigned long serial = 0;
    for (int ii = 6; ii > 0; ii--) {
      serial <<= 8;
      serial |= (unsigned long) addr[ii];
    }

    Serial.print("\nSerial Num: 0x");
    Serial.print(serial, HEX);
    Serial.print(" (");
    Serial.print(serial, DEC);
    Serial.println(")\n");
    
    // 26 bit card
    int site;
    int cardNo;

    site = addr[1] >> 1;

    cardNo |= addr[2];
    cardNo <<= 8;
    cardNo |= addr[3];    
    cardNo >>= 1; 
    
    Serial.println("26 bit Card");
    Serial.print("Site: ");
    Serial.println(site, DEC);
    Serial.print("CardNo: ");
    Serial.println(cardNo, DEC);


  } else {
    Serial.println("ROM Byte: " + addr[0]);
  }
  delay(1000);
  digitalWrite(GREEN, HIGH);
  digitalWrite(RED, LOW);
 }

 void printHex8 (byte val) {
  if (val < 0x10) {
    Serial.print("0");
  }
  Serial.print(val, HEX);
 }