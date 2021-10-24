/*
 * ライトセンサーでLED点滅
 */
 
#define LEDPIN 4      // LEDのピン番号
#define LIGHTPIN A6   // ライトセンサーのピン番号

// LEDを点灯させる下限値 (0～1023)
// 部屋の明るさにあわせて下限値を調整する必要があるかもしれません
// 値を大きくするとセンサーから手を離していてもLEDが点灯したままになるかもしれません
// 値を小さくするとセンサーを手でしっかり覆わないとLEDが点灯しなくなります
const int switchOnMin = 512;  // LED点灯させるライトセンサー値の下限

void setup() {
  pinMode(LEDPIN, OUTPUT);
}

void loop() {
  int lightValue = analogRead(LIGHTPIN);  // ライトセンサーの値を取得

  if (lightValue < switchOnMin) {
    digitalWrite(LEDPIN, HIGH);
  } else {
    digitalWrite(LEDPIN, LOW);
  }

  delay(100);
}
