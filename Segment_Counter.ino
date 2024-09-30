//Left Segment pins
#define LSa 2
#define LSb 3
#define LSc 4
#define LSd 5
#define LSe 6
#define LSf 7
#define LSg 8


//Right Segment pins
#define RSa 9
#define RSb 10
#define RSc A1
#define RSd A2
#define RSe A3
#define RSf A5
#define RSg A4

//arrays for segments pins
uint8_t LSPins[7] = {LSa,LSb,LSc,LSd,LSe,LSf,LSg}; //Left segment 
uint8_t RSPins[7] = {RSa,RSb,RSc,RSd,RSe,RSf,RSg}; //Right segment

uint8_t SegmentValues[10] = {0x40, 0x79, 0x24, 0x30, 0x19, 0x12, 0x02, 0xF8, 0x00, 0x10}; //values for segment common anode

void SegmentWrite(uint8_t segment_pins[] , int number){
  for(int i = 0 ; i <= 7 ; i++)
  {
    digitalWrite(segment_pins[i],(SegmentValues[number]>>i)&0x01);
  }
}

void SegmentInit(uint8_t SegmentPins[]){
  for(int i = 0 ; i < 8 ; i++)
  {
    pinMode(SegmentPins[i],OUTPUT);
  }
}

void NumberWrite(int number){
  int ones = number%10;
  int tens = number/10;
  SegmentWrite(LSPins, tens);
  SegmentWrite(RSPins, ones);  
}


void setup() {
  SegmentInit(LSPins);
  SegmentInit(RSPins);
}

void loop() {
  
  for(int value = 0 ; value <= 99 ; value++)
  {
    NumberWrite(value);
    delay(100);
  }
  
}
