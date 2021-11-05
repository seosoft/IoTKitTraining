/*
 * ロータリースイッチ（ボリューム）でLED点滅スピードを変更する
 * ロータリースイッチを左に回すほどLEDは速いペースで点滅します。
 * ロータリースイッチを右に回すほどLEDは遅いペースで点滅します。
 * 
 * ボタンは押す・離すの状態（=デジタル入力）を取得するものでした。
 * ロータリースイッチは左にいっぱいに回した状態から右にいっぱいにまわした状態まで、
 * 値が滑らかに変化する値を取得できます。
 * このような入力をアナログ入力といいます。
 * 
 * ただし実際には今回使用するロータリースイッチは0～1023の整数値を変化します。
 * 例えば100.123のような小数値は取れないため「とびとびの値」ですが人間にとっては滑らかに変化したように見えます。
 * このような値をアナログ入力として扱います。
 */
 
#define LEDPIN 4      // LEDのピン番号
#define ROTARYPIN A0  // ロータリースイッチのピン番号

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
