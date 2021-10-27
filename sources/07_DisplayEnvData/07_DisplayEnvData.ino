/*
 * 環境センサーの値を液晶に表示
 * 
 * [スケッチ]-[ライブラリをインクルード]-[ライブラリを管理] で以下のライブラリをインストールする必要があります
 * Grove Temperature and Humidity Sensor
 * U8g2
 */
 
#include <Arduino.h>
#include <DHT.h>
#include <U8x8lib.h>

#define LEDPIN 4    // LEDのピン番号

// 環境センサーの値
#define DHTPIN 3            // 環境センサー（温度、湿度）のピン番号
#define DHTTYPE DHT11       // 環境センサーの型番 
DHT dht(DHTPIN, DHTTYPE);   // 環境センサーを型番を指定

// OLED (液晶)の初期化
U8X8_SSD1306_128X64_NONAME_HW_I2C u8x8(U8X8_PIN_NONE);

void setup() {
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
  
  u8x8.setCursor(0, 0);
  u8x8.print("Temp : ");
  u8x8.print(temp);
  u8x8.print("C");
  u8x8.setCursor(0, 1);
  u8x8.print("Humid: ");
  u8x8.print(humi);
  u8x8.print("%");
  
  u8x8.refreshDisplay();

  // 0.5秒待ってからLEDを消灯
  delay(500);
  digitalWrite(LEDPIN, LOW);

  // さらに1.5秒待ってから環境センサーの値を再度読み出す
  delay(1500);
}
