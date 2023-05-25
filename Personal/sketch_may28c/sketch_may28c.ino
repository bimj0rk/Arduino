#include <MeMCore.h>
MeIR ir;
#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel pix(2, 13, NEO_GRB + NEO_KHZ800);
void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  ir.begin();
  pix.begin();
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  if (ir.decode()) {
    uint32_t value = (ir.value >> 16) & 0xFF;
    Serial.print("0x");
    Serial.println(value, HEX);
    
    if (value == 0xC) {
      pix.setPixelColor(0, pix.Color(0, 51, 102));
      pix.setPixelColor(1, pix.Color(0, 51, 102));
      pix.show();
    }
   
    if (value == 0x18) {
      pix.setPixelColor(0, pix.Color(0, 99, 49));
      pix.setPixelColor(1, pix.Color(0, 99, 49));
      pix.show();
    }
  }
}
