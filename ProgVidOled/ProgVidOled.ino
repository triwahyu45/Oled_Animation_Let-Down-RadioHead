#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "VideoFrame.h" 

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);


unsigned long previousMillis = 0;
int currentFrame = 0;

void setup() {
  Serial.begin(115200);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.println(F("OLED gagal terhubung."));
    for(;;); 
  }

  Wire.setClock(800000); 

  display.clearDisplay();
  display.display();
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= FRAME_DELAY) {
    
    previousMillis = currentMillis;

    display.clearDisplay();
    display.drawBitmap(0, 0, video_frames[currentFrame], SCREEN_WIDTH, SCREEN_HEIGHT, WHITE);
    display.display();

    currentFrame++;

    if (currentFrame >= TOTAL_FRAMES) {
      currentFrame = 0;
    }
  }
}