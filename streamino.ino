/*************************************************************************
   StreamPad v2.1 - http://mad-design.net - Jan 2020

   This is free and unencumbered software released into the public domain.

  Anyone is free to copy, modify, publish, use, compile, sell, or
  distribute this software, either in source code form or as a compiled
  binary, for any purpose, commercial or non-commercial, and by any
  means.

  In jurisdictions that recognize copyright laws, the author or authors
  of this software dedicate any and all copyright interest in the
  software to the public domain. We make this dedication for the benefit
  of the public at large and to the detriment of our heirs and
  successors. We intend this dedication to be an overt act of
  relinquishment in perpetuity of all present and future rights to this
  software under copyright law.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
  IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
  OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
  ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
  OTHER DEALINGS IN THE SOFTWARE.

  For more information, please refer to <https://unlicense.org>
*****************************************************************************/

#include "Keyboard.h"
//buttons setup
const int buttonPin[] = {2, 3, 4, 5, 6, 7, 8, 9, 10};
int pinCount = 9;
int buttonState[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
int prevButtonState[] = {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH};
long lastDebounceTime[] =  {0, 0, 0, 0, 0, 0, 0, 0, 0};
const int shiftButton = 11;
int shiftButtonState = HIGH;
int shiftPressed = 0;
long debounceDelay = 50;
char bSlash = 96;
char iAcc = 61;
char ctrlKey = KEY_LEFT_CTRL;
char altKey = KEY_LEFT_ALT;
char shiftKey = KEY_LEFT_SHIFT;
char winKey = KEY_LEFT_GUI;
char f1 = KEY_F1;
char f2 = KEY_F2;
char f3 = KEY_F3;
char f4 = KEY_F4;
char f5 = KEY_F5;
char f6 = KEY_F6;
char f7 = KEY_F7;
char f8 = KEY_F8;
char f9 = KEY_F9;
int keyDelay = 100;

void setup() {
  Serial.begin(9600);
  for (int thisPin = pinCount - 1; thisPin >= 0; thisPin--) {
    pinMode(buttonPin[thisPin], INPUT_PULLUP);
    digitalWrite(buttonPin[thisPin], HIGH);
  }
  pinMode(shiftButton, INPUT_PULLUP);
  digitalWrite(shiftButton, HIGH);

  Keyboard.end();
  Keyboard.begin();
}

int outputAction(int currentButton) {
  if (currentButton == 0) {
    Keyboard.press(ctrlKey);
    Keyboard.press(altKey);
    Keyboard.press(shiftKey);
    Keyboard.press(f2);
    Serial.println("C A S F2");
    delay(keyDelay);
    Keyboard.releaseAll();
  }

  if (currentButton == 1) {
    Keyboard.press(ctrlKey);
    Keyboard.press(altKey);
    Keyboard.press(iAcc);
    Serial.println("C A ì");
    delay(keyDelay);
    Keyboard.releaseAll();
  }


  if (currentButton == 2) { //scena 1
    Keyboard.press(winKey);
    Keyboard.press(f5);
    Serial.println("W F5");
    delay(keyDelay);
    Keyboard.releaseAll();
  }

  if (currentButton == 3) {
    Keyboard.press(winKey);
    Keyboard.press(f6); // brb
    Serial.println("W F6");
    delay(keyDelay);
    Keyboard.releaseAll();
  }

  if (currentButton == 4) {
    Keyboard.press(winKey);
    Keyboard.press(f7);
    Serial.println("W F7");
    delay(keyDelay);
    Keyboard.releaseAll();
  }

  if (currentButton == 5) {
    Keyboard.press(winKey);
    Keyboard.press(f8); // thx
    Serial.println("W F9");
    delay(keyDelay);
    Keyboard.releaseAll();
  }

  if ((shiftPressed == 1) && (currentButton == 6)) {
    Keyboard.press(winKey);
    Keyboard.press(f3);
    Serial.println("W F3");
    delay(keyDelay);
    Keyboard.releaseAll();
    shiftPressed = 0;
  }
  else if ((shiftPressed == 0) && (currentButton == 6)) {
    Keyboard.press(winKey);
    Keyboard.press(f9);
    Serial.println("W F9");
    delay(keyDelay);
    Keyboard.releaseAll();
  }
  // g2
  if ((shiftPressed == 1) && (currentButton == 7)) {
    Keyboard.press(winKey);
    Keyboard.press(f4);
    Serial.println("W F4");
    delay(keyDelay);
    Keyboard.releaseAll();
    shiftPressed = 0;
  }
  else if ((shiftPressed == 0) && (currentButton == 7)) {
    Keyboard.press(altKey);
    Keyboard.press(iAcc);
    Serial.println("A iAcc");
    delay(keyDelay);
    Keyboard.releaseAll();
  }
  // g3
  if ((shiftPressed == 1) && (currentButton == 8)) {
    Keyboard.press(ctrlKey);
    Keyboard.press(shiftKey);
    Keyboard.press(f3);
    Serial.println("C S F3");
    delay(keyDelay);
    Keyboard.releaseAll();
    shiftPressed = 0;
  }
  else if ((shiftPressed == 0) && (currentButton == 8)) {
    Keyboard.press(ctrlKey);
    Keyboard.press(iAcc);
    Serial.println("C iAcc");
    delay(keyDelay);
    Keyboard.releaseAll();
  }
  Keyboard.releaseAll();
}

void loop() {

  shiftButtonState = digitalRead(shiftButton);
  if (shiftButtonState != HIGH) {
    shiftPressed = 1;
  }

  for (int thisPin = pinCount - 1; thisPin >= 0; thisPin--) {
    buttonState[thisPin] = digitalRead(buttonPin[thisPin]);

    if ((buttonState[thisPin] != prevButtonState[thisPin]) && (buttonState[thisPin] == HIGH)) {
      if ((millis() - lastDebounceTime[thisPin]) > debounceDelay) {
        outputAction(thisPin);
        lastDebounceTime[thisPin] = millis();
      }
    }
    prevButtonState[thisPin] = buttonState[thisPin];
  }
}
