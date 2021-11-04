/*
 * トグルボタンでLED点滅
 * ボタンを押すとLEDが点灯、もう一度押すとLEDを消灯します。
 * リモコンやスマホなどの電源ボタンのような動きです。
 * 
 * loop関数でボタンの状態を取得します。 
 * 次の繰り返しの時に前回が押されていて今回は離されていればボタンを操作されたことになります。
 * このタイミングでLEDの点灯・消灯の状態を切り替えます。
 */
 
#define LEDPIN 4      // LEDのピン番号
#define BUTTONPIN 6   // ボタンのピン番号

int ledState = LOW;   // 現在のLEDの状態
int buttonState;      // 今回のボタンの状態
int prevButtonState;  // 前回のボタンの状態

void setup() {
  pinMode(LEDPIN, OUTPUT);
  pinMode(BUTTONPIN, INPUT);

  // 起動時の処理中にボタンの状態を取得しておき、これを前回のボタンの状態にいれておく
  // これでloop関数の最初の実行時に前回のボタンの状態と比較できる
  
  buttonState = digitalRead(BUTTONPIN);
}
 
void loop() {
  // digitalReadで現在のbuttonStateを取得する前に、prevButtonStateに前回のボタンの状態として保存しておく
  prevButtonState = buttonState;

  // 現在のボタンの状態を取得する
  buttonState = digitalRead(BUTTONPIN);

  if (prevButtonState == HIGH && buttonState == LOW) {
    // ボタンの前回の状態が押されていて、今回は離された場合
    ledState = !ledState;             // ボタン状態の変数を変更（HIGHとLOWとを反転させる）
    digitalWrite(LEDPIN, ledState);   // 変数の値にあわせて LED の点灯を変更
  }

  delay(100);
}
