/*
 * Arduino上のLED点滅（Lチカ）
 * 
 * マイコンボードで最も基本的な Lチカを体験します
 */

// 起動時の処理
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

// 電源を切るまで繰り返す
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);   // LED点灯
  delay(1000);                       // タイマー
  digitalWrite(LED_BUILTIN, LOW);    // LED消灯
  delay(1000);                       // タイマー
}
