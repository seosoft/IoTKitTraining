# Arduino で組み込み開発

> このコンテンツは Markdown ファイル、および Arduino で動作するスケッチファイルで構成されています。  
>
> 説明は Markdown ファイル (拡張子 .md) に書いてありますが、 Markdown が読みづらい環境で利用している場合は、同じ内容を pdf フォルダーにもおいてあります。そちらを参照してください。

演習を通して **組み込み開発の基本** を学習します。

開発の手順とあわせて、組み込み開発に必要なデジタルデータ・アナログデータの基本とセンサーなどの入出力部品の扱い方を理解します。

この体験学習では次の内容を扱います。

- 組み込み開発の基本
- データの種類と入出力部品
- 主なマイコンボードとArduino / Arduino互換ボード
- 組み込み開発の演習

---

この演習は以下の構成です。上から順番に進めてください。  

1. [演習の環境構築](./0_Setup.md)
2. [Arduino IDE の操作](./1_ArduinoIde.md)
3. [組み込み開発の演習](./2_Lessons.md)

> 集合形式の演習などの場合には、すでに環境構築が完了していることがあります。  
> その場合は、講師やスタッフの指示に従ってください。

---

組み込み開発の勉強やプロトタイプ開発ではマイコンボード Arduino を使うことがよくあります。  
今回の演習では Arduino 互換機である [**Grove Beginner Kit for Arduino**](https://jp.seeedstudio.com/Grove-Beginner-Kit-for-Arduino-p-4549.html) を使用します。 

<img src="https://files.seeedstudio.com/wiki/Grove-Beginner-Kit-For-Arduino/img/Parts.jpg" />

**Arduino 互換ボード** と **10個のデバイス** が接続済みなので、配線を気にせずにすぐに組み込み開発を始めることができます。

Grove Beginner Kit は [**こちらのサイト**](https://www.switch-science.com/catalog/6361/) などのいくつかの通信販売サイトで購入できます。

> Arduino やその他の互換ボードとデバイスと使用して、このコンテンツの演習を実施することもできます。  
> ただし Grove Beginner Kit 以外のボードやデバイスを使う場合のインストール手順や結線方法などは、このコンテンツでは扱いません。各自で適切な手順で行ってください。