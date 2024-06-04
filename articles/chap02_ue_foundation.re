= Unreal Engine 基本用語編

Unreal Engine独自の用語の仕組みがイメージできるように図解しました。

//pagebreak
　　
//pagebreak
== LevelとAsset

//image[chap02_ue_foundation_01][LevelとAsset][scale=1.0]{
//}

//pagebreak

「外部File」はUEのプロジェクト外のFileのことです。UEに「外部File」をインポートするとUE専用の「Asset（.uasset）」というバイナリーデータに変換されます。
//blankline
「Asset」はゲームを動かすための素材です。「Asset」は「Contents Browser」やUE5から追加された「Contents Drawer」でファイルエクスプローラのように管理できます。「Asset」をViewportに追加すると「Level」に「Actor」として配置されます。
//blankline
「Level」にはゲームを動かすための「Asset」を配置します。「Level」に配置できるように「Actor」に変換されます。

「Asset」の複製として「Level」に配置するので、「Asset」を編集すれば配置しているすべての「Actor」を変更できます。

「Level」で編集した「Actor」は「Asset」に変換できます。
//blankline
「Level」と「Asset」を行ったり来たりしながらゲームを作成します。「Asset」を「外部File」にエクスポートしてUE以外の「外部ツール（DCCツール）」で編集できます。

UE4の後半バージョンからUE内でも外部ファイルとしてインポートしていた「Asset」をUE内で作成できるようになってきています。

数年後にはUE内ですべての「Asset」を作れるようになるかもしれません。

//pagebreak

== ソースコントロールとRedirector

//image[chap02_ue_foundation_02][ソースコントロールとRedirector][scale=1.0]{
//}

//pagebreak

複数人で開発すると大量の「Asset」が「UEプロジェクト」に含まれます。

リモートワークや複数の会社間でゲームを開発するケースが増えてきました。

//blankline
複数人でゲーム開発するには1台のPCで作業できないので、「UEプロジェクト」の「Asset」やゲームで使用する「外部File」は「ソースコントロール」という仕組みを使ってサーバーやクラウドサービスで管理します。

UEではソースコントロールは「Perforce」、「SVN」、「Git」が選ばれます。「Asset」や「外部ファイル」が100MBを越えるバイナリーデータを扱うので、バイナリーデータを扱いやすい「Perforce」や「SVN」が選ばれるケースが多かったです。「Git」もバイナリーデータを扱いやすくなり、技術の共有が多いため選ばれるようになってきました。

//blankline
「ソースコントロール」では「Asset」をバージョンを付けて管理しています。一番の利点は何か問題が起きた時に問題が起きていなかったバージョンに戻すことができます。

//blankline
使用するツールによって用語や使用方法が異なりますが、使用する場合は以下のことに注意をしています。

 * 最新版を取得してから編集する
 * エラーが発生する情報はサーバーにアップしない
 * エラーが発生したら詳しい人にすぐ確認する

//blankline
ソースコントロールは便利な仕組みなのですが、「ソースコントロールの仕組み」や「Redirector」のことを把握していないとトラブルの原因になります。

同じバージョンのファイルを同時に変更すると「コンフリクト（衝突）」が発生します。同じファイルを同時に編集しないように作業を振り分けるようにしています。同じファイルを編集する可能性がある場合は声を掛け合うようにしています。

UEでは「Asset」同士関係しあうと「参照（Reference）」が発生します。「参照」がある「Asset」を「削除」や「移動や名前変更」をすると「Redirector」という参照先の情報を持っている「Asset」が生成されます。「Redirector」も「Asset」なのですが、「Contents Browser」に表示されず、ソースコントロールでサーバにアップし忘れるケースが起こります。サーバーから最新の「Asset」を受け取った側では「Redirector」がないので「Asset」が見つからなくなります。

//pagebreak

== Actor

//image[chap02_ue_foundation_03][Actor][scale=1.0]{
//}

//pagebreak

「Level」に配置できる「Asset」は「Actor」に変換されます。すでに配置されている「Actor」には「Asset」を上書きできます。

キャラクター、背景、Effectといった目に見える分かりやすい「Actor」もあれば、Light、Camera、Collisionといった目に見えない「Actor」もあります。

「Actor」はその名の通りゲームの中の俳優（Actor）として扱われます。「Actor」をどのように配置して、どのように動かすかでゲームを作成します。

//blankline
「Level」に配置できる「Actor」という共通単位を持つことで、ゲーム中に共通で処理できます。

「BeginPlay」イベントに処理を実装した「Actor」にはゲーム開始時に処理が実行されます。

「Tick」イベントでは毎フレーム処理を実行できます。毎フレーム処理が実行されてしまうので、「Tick」イベントには処理を実装しないように工夫しています。

//pagebreak

== Gameplay Framework

//image[chap02_ue_foundation_04][Gameplay Framework][scale=1.0]{
//}

//pagebreak

UEでは「Gameplay Framework」と呼ばれる独自の仕組みで、Gameをメインで動かすPlayer、コントローラー、カメラやUIといったCore（核）となる要素を設定できます。

「GameMode」にゲームで使用するメインの機能を設定することで、ゲームをPlayした時に「Level」の動作が決まります。

「GameMode」の構成を変えることで同じ「Asset」を使ってジャンルの異なるゲームや異なるプラットフォームに向けた操作やUIを決定できます。

//blankline
ゲームで共通して使用する「GameMode」はプロジェクト設定で1つだけ設定し、「GameMode」を変更したい場合は「Level」単位で上書きできます。

「Gameplay Framework」は「Level」単位で設定しますが、「Level」間で共通の情報を受け渡したい時には「GameInstance」を使用します。「GameInstance」は「UEプロジェクト」で1つだけ持てます。

//pagebreak

== 親子関係 / World・Local Space

//image[chap02_ue_foundation_05][親子関係 / World・Local Space"][scale=1.0]{
//}

//pagebreak

「Level」に配置した「Actor」には「親子関係」を持てます。

親の変更は子に影響するので親を動かすと子も連動して動きます。子は親に影響は与えないので子を動かしても親は動きません。

「Location（位置情報）」はどこを基準にするかでLocationの値は変わります。

 * World Space : 原点からの距離（絶対座標）
 * Local Space : 親からの距離（相対座標）

「Location」に限らず、「Rotation」や「Scale」にもWorldとLocalの関係があります。

UEのEditorでは「Local Space」の設定が「Transform」に表示されているので、親子関係を持った時には親からの位置が表示されています。

//blankline
BlueprintではComponentに対して親子関係を持てますが、「World」と「Relative」という名称に変わります。

//pagebreak

== Persistent LevelとSublevel

//image[chap02_ue_foundation_06][Persistent LevelとSublevel][scale=1.0]{
//}

//pagebreak

「Level」は「Persistent Level」と複数の「Sublevel」で構成できるように作られています。

「Level」は1つの「Asset」なので複数人では編集できません。（「One File Per Actor」という機能を使用することで「Actor」単位で編集できるようになりました。）

「Level」は別々のチームが作成したアセットを配置することになります。チームごとに編集した「Level」を「Sublevel」として「Persistent Level」レベルに紐づけます。

//blankline
「Sublevel」は状況に応じて切り替えることができます。たとえば、背景は同じ「Actor」で構成されているけど、Lightingは朝と夜で別々のActorで構成した「Level」で作成します。Lighting用の「Sublevel」はプログラムで使用する「Level」を切り替えます。

「Sublevel」には「常に表示する」と「Bluerprint」(プログラムで表示する)との2つの設定があります。ゲームをプレイした際に「Sublevel」が表示されていない場合は「Bluerprint」の設定になっているかを確認してください。

//pagebreak

== Level Design

//image[chap02_ue_foundation_07][Level Design][scale=1.0]{
//}

//pagebreak

「Level Design」は遊びの部分を優先してプロトタイプを作成を行います。

仮モデルで遊びを確認しながら、「Asset」ができたら「Sublevel」を新規作成して仮モデルを上書きするように配置します。徐々にゲームに必要な「Sublevel」ができあがり、本番環境ができたら最終的に仮モデルを配置した「Sublevel」は非表示にします。

仮モデルの段階で遊びに確認ができているので、いろんな「Asset」が配置されても遊び部分はほとんど変わりません。

UE4の時は「Geometry Brush」と呼ばれる簡単な形状を配置して作っていましたが、「Level Design」専用のAssetが配布されたり、UEのEngineフォルダ内のマテリアルにLevel Designをしやすいグリッド表示が実装されました。

最近では「Modeling Tool」というUE上でModelingできるツールにも「Level Design」で使用できる機能が追加されています。

UE5になってからバージョンを重ねるごとにUE内で「Asset」を作成できるようになってきています。ゲーム用の素材を作成できるツールへと進化しています。

//pagebreak

== CollisionとTrace

//image[chap02_ue_foundation_08][CollisionとTrace][scale=1.0]{
//}

//pagebreak

「Collision（衝突判定）」は透明な壁です。

形状は「Cube」、「Sphere」と「Cupsule」があります。凸型の形状でも動作をします。

凹型のように内側に凹んでいる形状は持てません。凹型にしたい場合は複数の凸型の形状を組み合わせます。この凸型の形状のことを「Collision Hull」と呼びます。

「Collision」は「Collition Channel」でチャンネル同士の関係で衝突した時の動作が決まります。

「Collition Channel」では大きく3つの関係を持ちます。

 * Ignore  ： 何もしない
 * Overlap ： 通り抜けた時に通知する
 * Block   ： ぶつかる

「Collision Channel」の設定を事前にまとめて「Collision Preset」として設定できます。

//blankline
「Trace」は「Collision」のように見えない線や範囲を発生させることで、「Trace」に衝突した情報から「どのActorに衝突した」や「位置情報」といったゲームを作るうえで必要な詳細情報を取得できます。

見えない線として扱えるので、キャラクターや敵の視線や爆弾の爆発する範囲を見ために影響を与えずに処理できます。

「Trace」にも「Collision」と同様の3つの関係を持ちます。
//blankline

「Collision」や「Trace」のチャンネル同士の関係はCollision Presetとして特定の組み合わせを事前に構成できます。

//pagebreak

== Packaging

//image[chap02_ue_foundation_09][Packaging][scale=1.0]{
//}

//pagebreak

「UE プロジェクト」の状態ではUEをインストールしたPCにプロジェクトを配布しないと遊ぶことができません。プロジェクト内は「秘伝のタレ」のような貴重な情報がたくさん入っています。「UE プロジェクト」を配布するわけにもいきません。

//blankline

「UE プロジェクト」を「Packaging」という工程を通して家庭用ゲーム機、スマートフォンやUEがインストールされていないPCでも遊べるようにバイナリーファイル化することで配布できます。

UEではさまざまなプラットフォーム向けに「Packaginig」できます。

//blankline
「Packaging」の作業はプロジェクトの規模が拡大するにしたがって時間が増えていきます。配布するギリギリのタイミングなどで「Packaging」をしてエラーが発生してしまうと配布できなくなってしまいます。

UEではプロジェクトを開かなくてもコマンドで「Packaging」を行える「Unreal Automation Tool(UAT)」というツールが用意されています。

Cl/CD(継続的インテグレーションおよび継続的デリバリー/デプロイメントの略)ツールで作業をしていない夜間に「UAT」を実行して、朝出社した時には「Packaging」されたバイナリーファイルができているように工夫しています。

日常的に「Packaging」した配布データで確認をすることでエラーや修正点を素早く見つけたり、ギリギリに「Packaging」をして間に合わないといったリスクを防げます。

とくにUEのPC上のEditorと配布するプラットフォームの実機では見え方が変わるので、「Packaging」した配布データで対応するプラットフォームの実機で確認することは非常に大事です。
