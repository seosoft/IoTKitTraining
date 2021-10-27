/*
 * 外部ポートのLED点滅（Lチカ）
 */

// LEDデバイスのピン番号
#define LEDPIN 4

// 起動時の処理
void setup() {
  pinMode(LEDPIN, OUTPUT);
}

// 電源を切るまで繰り返す
void loop() {
  digitalWrite(LEDPIN, HIGH);   // LED点灯
  delay(1000);                  // タイマー
  digitalWrite(LEDPIN, LOW);    // LED消灯
  delay(1000);                  // タイマー
}
