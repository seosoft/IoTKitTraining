/*
 * トグルボタンでLED点滅
 */
 
#define LEDPIN 4      // LEDのピン番号
#define ROTARYPIN A0  // ロータリースイッチのピン番号

const int switchOnMin = 512;  // LED点灯させるロータリースイッチのアナログ値の上限

void setup() {
  pinMode(LEDPIN, OUTPUT);
  pinMode(ROTARYPIN, INPUT);
}

void loop() {
  int rotaryValue = analogRead(ROTARYPIN);    // ロータリースイッチの値を取得

  // ロータリースイッチの値でLED点滅の間隔を指定
  digitalWrite(LEDPIN, HIGH);
  delay(rotaryValue);
  digitalWrite(LEDPIN, LOW);
  delay(rotaryValue);
}
