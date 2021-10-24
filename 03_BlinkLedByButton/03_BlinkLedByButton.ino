/*
 * ボタンに連動してLED点灯
 */
 
#define LEDPIN 4      // LEDのピン番号
#define BUTTONPIN 6   // ボタンのピン番号

void setup() {
  pinMode(LEDPIN, OUTPUT);
  pinMode(BUTTONPIN, INPUT);
}
 
void loop() {
  int buttonState = digitalRead(BUTTONPIN);   // ボタンの状態を取得

  if (buttonState == HIGH) {
    digitalWrite(LEDPIN, HIGH);
  } else {
    digitalWrite(LEDPIN, LOW);
  }

  // 慣れてくれば if/else の代わりに1行で書くこともできます
  // digitalWrite(LEDPIN, buttonState);

  delay(100);
}
