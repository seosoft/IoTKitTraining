/*
 * 環境センサーの値を液晶に表示 2
 * 
 * このスケッチは Grove Beginner Kit 以外に "Grove - LCD RGB Backlight" が必要です 
 *
 * [スケッチ]-[ライブラリをインクルード]-[ライブラリを管理] で以下のライブラリをインストールする必要があります
 * Grove LCD RGB
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
DHT dht(DHTPIN, DHTTYPE);   // 環境センサーを型番を指定

// キャラクターディスプレイ
rgb_lcd lcd;

// OLED (液晶)の初期化
U8X8_SSD1306_128X64_NONAME_HW_I2C u8x8(U8X8_PIN_NONE);

void setup() {
  // キャラクターディスプレイの初期化
  lcd.begin(16, 2);
  lcd.setRGB(64, 64, 64);
  
  // 環境センサーの初期化
  dht.begin();

  // 液晶の初期化
  u8x8.begin();
  u8x8.setFlipMode(1);

  // 表示するフォントの指定
  u8x8.setFont(u8x8_font_chroma48medium8_r);

  pinMode(LEDPIN, OUTPUT);
}

void loop() {
  digitalWrite(LEDPIN, HIGH);  

  float temp = dht.readTemperature();
  float humi = dht.readHumidity();

  // 液晶に表示
  u8x8.setCursor(0, 0);
  u8x8.print("Temp : ");
  u8x8.print(temp);
  u8x8.print("C");
  u8x8.setCursor(0, 1);
  u8x8.print("Humid: ");
  u8x8.print(humi);
  u8x8.print("%");
  
  u8x8.refreshDisplay();

  // キャラクターディスプレイに表示
  lcd.setCursor(0, 0);
  lcd.print("Temp: " + String(temp));
  lcd.setCursor(0, 1);
  lcd.print("Hum : " + String(humi));

  // 0.5秒待ってからLEDを消灯
  delay(500);
  digitalWrite(LEDPIN, LOW);

  // さらに1.5秒待ってから環境センサーの値を再度読み出す
  delay(1500);
}
