/*
 * 環境センサーの値をディスプレイに表示
 * 環境センサー（温度、湿度）の値を約2秒感覚で取得してディスプレイに表示します。
 * 
 * マイコンボードで実行を始めたら環境センサーに指で軽く触れてみてください。
 * （強く押す必要はありません。表面に触れる程度にします）
 * 特に湿度は比較的簡単に変化するはずです。
 * 室温や体温によりますが温度の変化も確認できます。
 * 
 * 環境センサー、ディスプレイ（液晶画面）とも、マイコンボードの通信規格であるI2Cで通信します。
 * デジタル入出力、アナログ入出力よりも柔軟で、送受信できるデータの形式は複雑なものにできます。
 * I2Cではピン番号ではなく、デバイスごとの型番やIDを指定して利用可能にします。
 * 
 * なお今回使用するディスプレイは非常に小型なので文字が小さく見づらいかもしれません。
 * 非常に安価なデバイスなので今回はこれを使います。
 * 
 * [スケッチ]-[ライブラリをインクルード]-[ライブラリを管理] で以下のライブラリをインストールする必要があります
 * - Grove Temperature and Humidity Sensor
 * - U8g2
 * 
 */
 
#include <Arduino.h>
#include <DHT.h>
#include <U8x8lib.h>

#define LEDPIN 4    // LEDのピン番号

// 環境センサーの値
#define DHTPIN 3            // 環境センサー（温度、湿度）のピン番号
#define DHTTYPE DHT11       // 環境センサーの型番 

// 環境センサーの型番を指定
DHT dht(DHTPIN, DHTTYPE);

// OLED (液晶)の初期化
U8X8_SSD1306_128X64_NONAME_HW_I2C u8x8(U8X8_PIN_NONE);

void setup() {
  // ディスプレイの初期化
  u8x8.begin();
  u8x8.setFlipMode(1);

  // ディスプレイ表示に使用するフォントの指定
  u8x8.setFont(u8x8_font_chroma48medium8_r);

  // 環境センサーの初期化
  dht.begin();

  // 環境データを定期的に測定していることを確認するためにLEDを点滅させる
  pinMode(LEDPIN, OUTPUT);
}

void loop() {
  // 環境データの測定を始めるのを人間が確認できるようにLEDを点灯
  digitalWrite(LEDPIN, HIGH);  

  // 環境センサーから温度、湿度を取得
  float temp = dht.readTemperature();
  float humi = dht.readHumidity();

  // ディスプレイに環境データを表示
  u8x8.setCursor(0, 0);
  u8x8.print("Temp : ");
  u8x8.print(temp);
  u8x8.print("C");
  u8x8.setCursor(0, 1);
  u8x8.print("Humid: ");
  u8x8.print(humi);
  u8x8.print("%");
  
  u8x8.refreshDisplay();

  // 0.5秒待ってからLEDを消灯することで測定が終わったことが分かるようにする
  delay(500);
  digitalWrite(LEDPIN, LOW);

  // さらに1.5秒待ってから環境センサーの値を再度読み出す
  delay(1500);
}
