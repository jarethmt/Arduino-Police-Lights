#include <FastLED.h>

// How many leds in your strip?
#define NUM_LEDS 30
#define DATA_PIN 2

// Define the array of leds
CRGB leds[NUM_LEDS];

void setup() { 
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);  // GRB ordering is assumed

  //PatternOne(10);
  
}

void loop() { 
  PatternOne(10);
  PatternTwo(10);
  PatternThree(8);
}

void PatternOne(int loopCount){

  if(!loopCount){
    loopCount = 5;
  }
  for(int i = 0; i < loopCount; i++){
    //Pulse Red
    HalfOn(0, CRGB::Red);
    HalfOff(1);
    delay(30);
    TurnOffLeds();
    delay(30);
    HalfOn(0, CRGB::Red);
    delay(30);
    TurnOffLeds();
    delay(30);
    HalfOn(0, CRGB::Red);
    delay(30);
    TurnOffLeds();
    
    delay(100);
    HalfOn(1, CRGB::Blue);
    HalfOff(0);
    delay(30);
    TurnOffLeds();
    delay(30);
    HalfOn(1, CRGB::Blue);
    delay(30);
    TurnOffLeds();
    delay(30);
    HalfOn(1, CRGB::Blue);
    delay(30);
    TurnOffLeds();
    delay(100);
  }
}

void PatternTwo(int loopCount){
  if(!loopCount){
    loopCount = 5;
  }
  for(int i = 0; i < loopCount; i++){
    HalfOn(0, CRGB::Red);
    HalfOn(1, CRGB::Blue);
    StrobeLeds();
    
    HalfOn(1, CRGB::Red);
    HalfOn(0, CRGB::Blue);
    StrobeLeds();
  } 
}


void PatternThree(int loopCount){
  if(!loopCount){
    loopCount = 5;
  }
  for(int i = 0; i < loopCount; i++){
    for(int j = 0; j < NUM_LEDS*2; j++){
      if(j < NUM_LEDS){
        leds[j].setRGB(0, 0, 255);
        leds[j-1].setRGB(20, 20, 20);

        leds[NUM_LEDS - j].setRGB(255, 0, 0);
        leds[NUM_LEDS - j + 1].setRGB(20, 20, 20);
      }
      else{
        int pastAmount = j - NUM_LEDS;
        leds[NUM_LEDS - pastAmount].setRGB(0, 0, 255);
        leds[NUM_LEDS - pastAmount + 1].setRGB(20, 20, 20);

        leds[pastAmount].setRGB(255, 0, 0);
        leds[pastAmount - 1].setRGB(20, 20, 20);
      }
      FastLED.show();
      delay(25);
    }
  } 
}



//Helpers to be used within patterns above

void HalfOn(int half, CRGB color){
  int halfLeds = NUM_LEDS / 2;
  int secondHalfStart = halfLeds;
  if(half == 0){
    for( int i = 0; i < halfLeds; ++i) {
        leds[i] = color;
    }
  }
  if(half == 1){
    for( int j = halfLeds; j < NUM_LEDS; ++j) {
      leds[j] = color;
    }
  }
  FastLED.show();
}
void HalfOff(int half){
  int halfLeds = NUM_LEDS / 2;
  int secondHalfStart = halfLeds;
  if(half == 0){
    for( int i = 0; i < halfLeds; ++i) {
        leds[i] = CRGB::Black;
    }
  }
  if(half == 1){
    for( int j = halfLeds; j < NUM_LEDS; ++j) {
      leds[j] = CRGB::Black;
    }
  }
  FastLED.show();
}
void TurnOnLeds(CRGB color)
{
    
    for( int i = 0; i < NUM_LEDS; ++i) {
        leds[i] = color;
    }
    FastLED.show();
}

void TurnOffLeds(){
  for( int i = 0; i < NUM_LEDS; ++i) {
        leds[i] = CRGB::Black;
    }
    FastLED.show();
}


void StrobeLeds(){
  //create an array to store the backup copy of leds
  CRGB initialColors[NUM_LEDS];
  
  //save current leds array to backup_leds
  memcpy(initialColors, leds, sizeof(leds));
  
  //First set
  for(int i = 0; i < NUM_LEDS; i++){
    if(i % 6 == 0){ 
      leds[i] = CRGB::White;
    }
    FastLED.show();
  }
  delay(30);
  //restore leds from backup_leds
  memcpy(leds, initialColors, sizeof(leds));
  FastLED.show();
  delay(30);


  //Second set
  for(int i = 0; i < NUM_LEDS; i++){
    if((i+3) % 6 == 0){ 
      leds[i] = CRGB::White;
    }
    FastLED.show();
  }
  delay(30);
  //restore leds from backup_leds
  memcpy(leds, initialColors, sizeof(leds));
  FastLED.show();
  delay(30);
  
}
