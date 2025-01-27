
= Unreal Engineのゲーム制作

Unreal Engineでゲームを作る環境についての概要を書きました。

//pagebreak
　　
//pagebreak
== Unreal Engineのゲーム制作

//image[chap01_ue_game_development_01][Unreal Engineのゲーム制作][scale=1.0]{
//}

//pagebreak

UEをインストールしたら、いよいよゲーム制作が始まります。

//blankline
次に「UE プロジェクト」を用意します。個人であれば新規で作成しますが、開発チームに途中から参加する場合は自分の作業PCにソースコントロールからダウンロードします。

//blankline
UEでゲームを作っていくには「外部ツール（DCC（Digital Content Creationの略）ツール）」で作成した「Asset」が必要になります。「外部ツール」で作成したり、MarketPlaceなどから無料・有料のコンテンツをプロジェクトに取り込みます。

UE4の後半バージョンからUE内で「Asset」を作成できるツールが次々に追加されています。

大量の「Asset」を「Level」に配置して、UEのEditorで動作を確認します。Editorでゲームを試遊することを「PIE（Play In Editor）」と呼びます。

「外部ツールでAssetを作成 <-> UEプロジェクトでゲームを編集・試遊」を繰り返しながらゲームを作成します。 
//blankline
作成したプロジェクトは「Packaging」という工程で各プラットフォームに配布できるようになります。

//blankline
UEで「編集」できる機能は「どこから手を出したらいいのか分からない」くらい、たくさんの機能があります。

この本ではUEでゲームを開発する際に使用頻度が高い用語について分かりやすく図解します。

//pagebreak

== Unreal Engineのゲーム制作者マップ

//image[chap01_ue_game_development_02][Unreal Engineのゲーム制作者マップ][scale=1.0]{
//}

//pagebreak

ゲームエンジンが普及したことで、ゲームを企画・プログラムからアートまで1人でもすべて行えるようなケースが増えてきました。

SNSでゲームを少人数で開発しているインディーゲーム開発者が注目を集めていたり、ゲームを作成する技術書では全般的な範囲が書かれています。

1人でゲーム開発する人より、チームで役割分担をして開発する方が一般的です。

//blankline
コンシューマゲームではゲーム開発は「デベロッパー」と呼ばれるゲーム開発会社が開発を担い、「パブリッシャー」と呼ばれる会社がゲームをリリースしています。

「デベロッパー」と「パブリッシャー」を1つの会社が両方兼ねている作品もあります。
//blankline

ゲームの開発は大きく以下の役職に分かれます。

 * プロデューサー：ゲームプロジェクトの全体の企画や予算を取り仕切る
 * ディレクター　：ゲーム全体の進行やクオリティを監督する
 * プランナー　　：ゲームの遊び（企画やレベルデザイン）パートを担当する
 * プログラマー　：ゲームの核となるプログラムのパートを担当する
 * アーティスト　：ゲームの見たに関わるパートを担当する

「プロデューサー」や「ディレクター」に最初からなることは少なく、「プランナー」、「プログラマー」「アーティスト」いずれかのパートの経験を得てから責任を持てる立場に昇格しています。

//blankline
ゲーム開発会社に入ってゲーム開発に携わりたい場合は、以下の観点を抑えてゲーム開発会社を選ぶといいのではないでしょうか。

 * ゲームの何処に興味を持ったのかで、自分の担当したい役職に必要な技術を選定する
 * 開発に携わりたいゲームのデベロッパーが何処であるかを確認して会社を選ぶ

//blankline
ポジTAはTA（テクニカルアーティスト）という職種に付いています。

「アーティスト」寄りの「プログラマー」みたいな役割です。

「アーティスト」が開発しやすくなるように「ツール・リグ・シェーダー」といったゲームの「遊び」ではなく「見た目」に関連するプログラミングを行っています。

ときどきミーティングに呼ばれて、「プログラマ」と「アーティスト」の通訳として仕様をお互いに分かりやすく伝えることもあります。

