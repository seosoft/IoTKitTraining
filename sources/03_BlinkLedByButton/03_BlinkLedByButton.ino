/*
 * ボタンに連動してLED点灯
 * ボタンを押している間だけLEDを点灯して、ボタンを離すとLEDを消灯します。
 * 
 * ボタンは押している、離しているをマイコンボードに入力するものです。
 * つまりオン・オフを入力するものなのでデジタル入力です。
 */
 
#define LEDPIN 4      // LEDのピン番号
#define BUTTONPIN 6   // ボタンのピン番号

// 起動時の処理
// 4番ピンにLEDが接続されていることを指定します。
// 6番ピンにボタンが接続されていることを指定します。

void setup() {
  pinMode(LEDPIN, OUTPUT);
  pinMode(BUTTONPIN, INPUT);
}

// 電源を切るまで繰り返す
//
// digitalRead関数は指定のピンの状態を取得します。
 
void loop() {
  int buttonState = digitalRead(BUTTONPIN);   // ボタンの状態を取得

  // ボタンが押されていればbuttonStateはHIGH、離されていればLOWです。
  // ボタンの状態がHIGHであるかを判断するためには、if分を使います。
  // 値が同じであることを判断するには演算子 "=="（イコール2個）を使用します。、
  if (buttonState == HIGH) {
    digitalWrite(LEDPIN, HIGH);
  } else {
    digitalWrite(LEDPIN, LOW);
  }

  // 上の if/else は次の1行で書くこともできます
  // digitalWrite(LEDPIN, buttonState);

  delay(100);
}
