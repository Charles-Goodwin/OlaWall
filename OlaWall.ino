//#define FASTLED_ESP32_I2S TRUE
#include <FastLED.h>

#define NUM_STRIPS 10
#define NUM_LEDS_PER_STRIP  480 
#define NUM_LEDS NUM_LEDS_PER_STRIP * NUM_STRIPS

#define BRIGHTNESS  255
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB

CRGB leds[NUM_LEDS];
const int pins[] = {4,13,14,15,16,17,18,19,21,22,23};

#include "pacifica.h"
void setup() {
  
  #if defined(FASTLED_ESP32_I2S)
    FastLED.addLeds<LED_TYPE, 4, COLOR_ORDER>(leds, 0, NUM_LEDS_PER_STRIP).setCorrection( TypicalLEDStrip );
    FastLED.addLeds<LED_TYPE, 13, COLOR_ORDER>(leds, NUM_LEDS_PER_STRIP, NUM_LEDS_PER_STRIP).setCorrection( TypicalLEDStrip );
    FastLED.addLeds<LED_TYPE, 14, COLOR_ORDER>(leds, 2* NUM_LEDS_PER_STRIP, NUM_LEDS_PER_STRIP).setCorrection( TypicalLEDStrip );
    FastLED.addLeds<LED_TYPE, 15, COLOR_ORDER>(leds, 3* NUM_LEDS_PER_STRIP, NUM_LEDS_PER_STRIP).setCorrection( TypicalLEDStrip );
    FastLED.addLeds<LED_TYPE, 16, COLOR_ORDER>(leds, 4* NUM_LEDS_PER_STRIP, NUM_LEDS_PER_STRIP).setCorrection( TypicalLEDStrip );
    FastLED.addLeds<LED_TYPE, 17, COLOR_ORDER>(leds, 5* NUM_LEDS_PER_STRIP, NUM_LEDS_PER_STRIP).setCorrection( TypicalLEDStrip );
    FastLED.addLeds<LED_TYPE, 18, COLOR_ORDER>(leds, 6* NUM_LEDS_PER_STRIP, NUM_LEDS_PER_STRIP).setCorrection( TypicalLEDStrip );
    FastLED.addLeds<LED_TYPE, 19, COLOR_ORDER>(leds, 7* NUM_LEDS_PER_STRIP, NUM_LEDS_PER_STRIP).setCorrection( TypicalLEDStrip );
    FastLED.addLeds<LED_TYPE, 21, COLOR_ORDER>(leds, 8* NUM_LEDS_PER_STRIP, NUM_LEDS_PER_STRIP).setCorrection( TypicalLEDStrip );
    FastLED.addLeds<LED_TYPE, 23, COLOR_ORDER>(leds, 9* NUM_LEDS_PER_STRIP, NUM_LEDS_PER_STRIP).setCorrection( TypicalLEDStrip );
  #else 
    FastLED.addLeds<LED_TYPE, 4, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  #endif
  
  FastLED.setBrightness( BRIGHTNESS );
  Serial.begin(115200);
}

void loop() {
  static uint8_t frames = 0;
  frames++;
  EVERY_N_MILLISECONDS(1000){
    #if defined(FASTLED_ESP32_I2S)
      Serial.print("i2S Frames per second: ");
    #else
      Serial.print("RMT (default) Frames per second: ");
    #endif
    Serial.println(frames);
    frames = 0;
  }
  pacifica_loop;
  FastLED.show();
}
