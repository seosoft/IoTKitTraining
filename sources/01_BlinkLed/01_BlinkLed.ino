/*
 * Arduinoボード上のLED点滅（Lチカ）
 * デジタル出力および組み込み開発の基本を理解します。
 * 
 * マイコンボードで最も基本的な Lチカを体験します。
 * ボード上のLEDが接続されたピンの電圧を1秒間隔でオン・オフします。
 * つまりLEDが１秒ごとに点いたり消えたりします。
 */

// setup : 起動時の処理
// Arduinoでは起動時の処理はsetup関数に記述します。
//
// ここではLED_BUILDIN(=13番ピン)は OUTPUT (=デジタル出力)として使用することを設定しています。

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}


// loop : 電源を切るまで繰り返す
// Arduinoは電源を切るまでloop関数を繰り返し実行します。
// ここではLEDを接続したピンに電圧をかけること（＝LEDが点灯）と電圧を切ること（＝LEDが消灯）を１秒間隔で繰り返します。
//
// digitalWrite関数は指定のピンにかける電圧をかけるか切るかを命令します。
// delay関数は指定の時間（単位はミリ秒＝0.001秒）だけ処理を中断して、指定時間がたったら次の行を処理します。

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);   // LED点灯
  delay(1000);                       // 次の処理まで1秒（=1000ミリ秒）待つ
  digitalWrite(LED_BUILTIN, LOW);    // LED消灯
  delay(1000);                       // 1秒待つ
}
