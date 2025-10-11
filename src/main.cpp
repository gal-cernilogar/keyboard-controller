#include <Arduino.h>
#include <Keyboard.h>

// CONFIGURATION
const int PIN_X = A1;
const int PIN_Y = A2;
const char LEFT_KEY = 'a';
const char RIGHT_KEY = 'd';
const char UP_KEY = 'w';
const char DOWN_KEY = 's';
const int X_SENSITIVITY = 50; // From 0 to 100
const int Y_SENSITIVITY = 50; // From 0 to 100
const int LOOP_DELAY = 10;
//

const int leftThreshold = int(round(512 - X_SENSITIVITY * 511 / 100));
const int rightThreshold = int(round(512 + X_SENSITIVITY * 511 / 100));
const int upThreshold = int(round(512 + X_SENSITIVITY * 511 / 100));
const int downThreshold = int(round(512 - X_SENSITIVITY * 511 / 100));

int left = LOW;
int right = LOW;
int up = LOW;
int down = LOW;

void setup() {
  Keyboard.begin();
}

void loop() {
  int valueX = analogRead(PIN_X);
  int valueY = analogRead(PIN_Y);

  if (valueX < leftThreshold && left == LOW) {
    Keyboard.press(LEFT_KEY);
    left = HIGH;
  } else if (valueX > leftThreshold && left == HIGH) {
    Keyboard.release(LEFT_KEY);
    left = LOW;
  }

  if (valueX > rightThreshold && right == LOW) {
    Keyboard.press(RIGHT_KEY);
    right = HIGH;
  } else if (valueX < rightThreshold && right == HIGH) {
    Keyboard.release(RIGHT_KEY);
    right = LOW;
  }

  if (valueY > upThreshold && up == LOW) {
    Keyboard.press(UP_KEY);
    up = HIGH;
  } else if (valueY < upThreshold && up == HIGH) {
    Keyboard.release(UP_KEY);
    up = LOW;
  }

  if (valueY < downThreshold && down == LOW) {
    Keyboard.press(DOWN_KEY);
    down = HIGH;
  } else if (valueY > downThreshold && down == HIGH) {
    Keyboard.release(DOWN_KEY);
    down = LOW;
  }

  delay(LOOP_DELAY);
}
