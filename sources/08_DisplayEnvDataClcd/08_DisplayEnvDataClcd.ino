/*
 * 環境センサーの値を外部のディスプレイに表示
 * 
 * 環境センサーの値をディスプレイに表示するものですが、環境データを外部のディスプレイにも表示します。
 * 表示する先が異なりますが、動作はひとつ前の「環境センサーの値をディスプレイに表示」とほとんど同じです。
 * 
 * ここで使用するのはキャラクターディスプレイ（LCD）です。
 * ドット（画面上の点）が粗く古くから使われているディスプレイですが、
 * 表示量が少ない場合には見やすく扱いも簡単なデバイスです。
 * 
 * Grove Beginner Kit にはキャラクターディスプレイは載っていません。
 * このスケッチを実行するには別途 Grove - LCD RGB Backlight (https://www.switch-science.com/catalog/1629/) が必要です。
 * 
 * また [スケッチ]-[ライブラリをインクルード]-[ライブラリを管理] で以下のライブラリをインストールする必要があります
 * - Grove LCD RGB
 * 
 */

#include <Arduino.h>
#include <DHT.h>
#include <U8x8lib.h>
#include <math.h>
#include <Wire.h>
#include "rgb_lcd.h"

// LEDのピン番号
#define LEDPIN 4

// 環境センサーの値
#define DHTPIN 3            // 環境センサー（温度、湿度）のピン番号
#define DHTTYPE DHT11       // 環境センサーの型番 

// 環境センサーの型番を指定
DHT dht(DHTPIN, DHTTYPE);

// キャラクターディスプレイ
rgb_lcd lcd;

// OLED (液晶)の初期化
U8X8_SSD1306_128X64_NONAME_HW_I2C u8x8(U8X8_PIN_NONE);

void setup() {
  // キャラクターディスプレイの初期化
  lcd.begin(16, 2);         // 16桁*2行表示に設定
  lcd.setRGB(64, 64, 64);   // 背景の照明を暗いグレーに設定

  // ディスプレイの初期化
  u8x8.begin();
  u8x8.setFlipMode(1);

  // ディスプレイ表示に使用するフォントの指定
  u8x8.setFont(u8x8_font_chroma48medium8_r);
  
  // 環境センサーの初期化
  dht.begin();

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

  // 外部のキャラクターディスプレイに環境データを表示
  lcd.setCursor(0, 0);
  lcd.print("Temp : " + String(temp) + "C");
  lcd.setCursor(0, 1);
  lcd.print("Humid: " + String(humi) + "%");

  // 0.5秒待ってからLEDを消灯することで測定が終わったことが分かるようにする
  delay(500);
  digitalWrite(LEDPIN, LOW);

  // さらに1.5秒待ってから環境センサーの値を再度読み出す
  delay(1500);
}
