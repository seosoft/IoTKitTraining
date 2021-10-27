/*
 * トグルボタンでLED点滅
 */
 
#define LEDPIN 4      // LEDのピン番号
#define BUTTONPIN 6   // ボタンのピン番号

int ledState = LOW;   // 現在のLEDの状態
int buttonState;      // ボタンの状態
int prevButtonState;  // 前回スキャンした時のボタンの状態
 
void setup() {
  pinMode(LEDPIN, OUTPUT);
  pinMode(BUTTONPIN, INPUT);

  buttonState = digitalRead(BUTTONPIN);
}
 
void loop() {
  prevButtonState = buttonState;
  buttonState = digitalRead(BUTTONPIN);

  if (prevButtonState == HIGH && buttonState == LOW) {
    // ボタンの前回の状態が押されていて、今回は離された場合
    ledState = !ledState;             // ボタン状態の変数を変更
    digitalWrite(LEDPIN, ledState);   // 変数の値にあわせて LED の点灯を変更
  }

  delay(100);
}
