# Arduino IDE の操作

演習を進める上で必要となる、Arduino IDE の操作を覚えます。

---

## 1. Arduino IDE の起動

Grove Beginner Kit を PC に接続して Arduino IDE を起動します。

はじめて Arduino IDE を起動した場合は、空のスケッチが開きます。  
以前、別のスケッチを編集していた場合は、そのスケッチが開くはずです。

> Arduino ではプログラムのソースコードのことを **スケッチ** と呼びます。

<img src="./images/1_launch_ide.jpg" width="540px" />

---

## 2. スケッチを開く

このコンテンツには動作確認済みの複数のスケッチがあらかじめ用意されています。

演習で使うスケッチを開くには二通りの操作方法があります。

- メニューの [ファイル]-[開く] を選択
- ツールバーの [開く] を選択

<img src="./images/1_open_sketch.jpg" width="360px" />
<img src="./images/1_open_sketch2.jpg" width="360px" />

ダイアログ（ファイル選択ウィンドウ）が開いたら、ここでは "**01_BlinkLed.ino**" を選択して開いてみます。

<img src="./images/1_select_sketch.jpg" width="540px" />

これで演習で使用するスケッチが開きます。

---

## 3. 新規のスケッチ作成と編集したスケッチの保存

新規のスケッチを開いて編集を始めるには、

- [ファイル]-[新規ファイル]
- ツールバーの [新規ファイル]

で操作します。

<img src="./images/1_new_sketch.jpg" width="360px" />
<img src="./images/1_new_sketch2.jpg" width="360px" />

編集したスケッチを保存するには、

- [ファイル]-[新規ファイル]
- ツールバーの [新規ファイル]

で操作します。

<img src="./images/1_save_sketch.jpg" width="360px" />
<img src="./images/1_save_sketch2.jpg" width="360px" />

ダイアログが開いたら、スケッチの内容を表す名前を決めて保存します。

<img src="./images/1_savedialog_sketch.jpg" width="540px" />

---

## 3. スケッチをマイコンボードに書き込む

スケッチをマイコンボードに書き込むと、自動的にボード上で動作が始まります。

スケッチを書き込むには、ツールバーの [マイコンボードに書き込む] を選択します。

<img src="./images/1_write_sketch.jpg" width="400px" />

PC 上で実行ファイルが作成されてからマイコンボードに書き込まれます。

スケッチに文法的なエラーがある場合には実行ファイルの作成に失敗します。この場合はマイコンボードへの書き込みも行われません。

スケッチに文法的なエラーがないかを確認するには検証します。（プログラミング一般ではコンパイルまたはビルドと言います）

検証するには、ツールバーの [検証] を選択します。

<img src="./images/1_compile_sketch.jpg" width="400px" />

---

この演習の通りに実施していれば、"**01_BlinkLed.ino**" が Grove Beginner Kit に書き込まれて、マイコンボード上の LED が1秒間隔で点滅します。

<img src="./images/1_blinkled.jpg" width="480px" />

以上が Arduino IDE の操作方法です。

スケッチの内容や文法には触れていませんが、まず操作方法を覚えておきましょう。