/*
 * 外部ポートのLED点滅（Lチカ）
 * 外部ポートのLEDはマイコンボード上のLEDと同じように操作できることを理解します。
 * 
 * 違いはLEDが接続されたピン番号の指定だけです。
 */

// LEDデバイスのピン番号
#define LEDPIN 4

// 起動時の処理
// 4番ピンにLEDが接続されていることを指定します。

void setup() {
  pinMode(LEDPIN, OUTPUT);
}

// 電源を切るまで繰り返す

void loop() {
  digitalWrite(LEDPIN, HIGH);   // LED点灯
  delay(1000);                  // 1秒待つ
  digitalWrite(LEDPIN, LOW);    // LED消灯
  delay(1000);                  // 1秒待つ
}
