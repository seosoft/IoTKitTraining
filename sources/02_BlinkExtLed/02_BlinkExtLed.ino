/*
 * 外部ポートのLED点滅（Lチカ）
 * 外部ポートのLEDであってもマイコンボード上のLEDと同じように操作できることを理解します。
 * 
 * 接続されたLEDがマイコンボード上にあっても外部にあっても同じコードで（ただしピン番号だけは変えて）点滅できることを体験します。
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
