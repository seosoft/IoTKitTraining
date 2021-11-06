/*
 * ライトセンサーでLED点滅
 * ライトセンサーを手で覆ってLEDを点灯させたり、手を放してLEDを消灯させたりします。
 * 
 * ロータリースイッチと同じで、ライトセンサーもアナログ入力デバイスです。
 */
 
#define LEDPIN 4      // LEDのピン番号
#define LIGHTPIN A6   // ライトセンサーのピン番号

// LEDを点灯させる下限値 (0～1023)
// 部屋の明るさにあわせて下限値を調整する必要があるかもしれません。
// ライトセンサーを手で覆ってもLEDが点灯しない場合は値を大きくしてみます。
// ライトセンサーから手を放してもLEDが消灯しない場合は値を小さくしてみます。

const int switchOnMin = 256;  // LED点灯させるライトセンサー値の上限値

void setup() {
  pinMode(LEDPIN, OUTPUT);
}

void loop() {
  int lightValue = analogRead(LIGHTPIN);  // ライトセンサーの値を取得

  // ライトセンサーの値が指定した下限値よりも小さい場合はLEDを点灯
  // そうでない場合はLEDを消灯
  if (lightValue < switchOnMin) {
    digitalWrite(LEDPIN, HIGH);
  } else {
    digitalWrite(LEDPIN, LOW);
  }

  delay(100);
}
