#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

int potPin = A0;
int motorPin = 3; 

int potVal = 0;
int pwmVal = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(motorPin, OUTPUT);
  
  Serial.begin (9600);

  // OLED initialization
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED failed");
    while(true);
  }

  display.clearDisplay();
  display.display();

}

void loop() {
  // read potentiometer
  potVal = analogRead(potPin);

  // convert 0-1023 into 0-255 for PWM
  pwmVal = map(potVal, 0, 1023, 0, 255);

  // send PWM to motor
  analogWrite(motorPin, pwmVal);

  // print to serial monitor
  Serial.print("Potentiometer: ");
  Serial.print(potVal);

  Serial.print("  PWM: ");
  Serial.println(pwmVal);

  // OLED Display
  display.clearDisplay();

  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);

  display.setCursor(0,0);
  display.print("Pot:");

  display.setCursor(0,20);
  display.print(potVal);
  
  display.setCursor(0,45);
  display.print("PWM:");
  display.print(pwmVal);

  display.display();

  delay(50);
  





}
