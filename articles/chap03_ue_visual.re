= Unreal Engine Visual用語編

Unreal EngineのVisualに関わる機能がイメージできるように図解しました。

//pagebreak
　　
//pagebreak
== Visual機能相関マップ

//image[chap03_ue_visual_01][Visual機能相関マップ][scale=1.0]{
//}

//pagebreak

UEで見た目に関わってくる用語の「Visual機能関連マップ」です。

「Model」には2種類あります。

 * StaticMesh
 * SkeletalMesh

2つの違いは「Skeleton（骨情報）」があるかどうかです。「Skeleton」があることで「Model」の形状を変更できます。

「Landscape」では広範囲の地形を作成できます。

「Effect（Naiagara）」や「UI（UMG）」といったAssetを持って見た目を調整するものや、「Lighting」のように「Level」の見た目を変えるようなものもあります。

各Visualに関連する「Asset」や「UEの機能」を「Material」で見た目を変えることができます。

「Material」は「Texture」という画像素材を使って詳細に変更できます。

「Audio（MetaSound）」も重要な要素です。Visualに音が合わさることでゲームがよりリアルになります。

各機能を専門としたアーティスト達がそれぞれの「Asset」を作成してゲームのVisualを作成します。

//blankline
UE4からあった機能やUE5で新しく導入された機能が入り乱れています。

UE5の新しい機能でどのように変わったか分かりやすく解説します。

//pagebreak

== StaticMeshとNanite

//image[chap03_ue_visual_02][StaticMeshとNanite][scale=1.0]{
//}

//pagebreak

「StaticMesh」は「Skeleton（骨情報）」がないModelです。一般的には動かないモデルのことを指しますが、Blueprint、MaterialやSkeletalMeshと組み合わせることでAnimationさせることもできます。

「StaticMesh」は以下のように使用されます。

 * 背景用のモデル（建造物、草・木といったFoliage）
 * キャラクターが持つ道具
 * 動く床のようなギミックを含んだモデル

「FBX」というファイル形式をインポートすることが一般的ですが、最近ではオープンソースの「gLTF」や「USD」という新しい拡張子が使えるようになり始めています。

//blankline
UE5から「Nanite」というハイポリModelをそのままゲームで使用できるような機能が入りました。

今まではハイポリModelとローポリModelを用意して差分をテクスチャ画像に焼き付けることでローポリModelをハイポリModelに錯覚させていました。

「LOD（Level Of Detail）」では距離に応じてポリゴン数を変更することで軽量化を図っていました。

最近のハードウェアの進化によって「Nanite」ではリアルタイムでハイポリModelを描画し、「LOD」のように距離に応じてポリゴン数を変更できるようになりました。

//pagebreak

== SkeletalMesh

//image[chap03_ue_visual_03][SkeletalMesh][scale=1.0]{
//}

//pagebreak

「SkeletalMesh」は「Skeleton（骨情報）」を持ったModelです。ゲームの主人公となるキャラクターに使用されるためVisualの中では一番見られるので花形の機能です。

図を見てもらえれば分かりますが、人間や動物のような生き物をリアルに再現できる仕組みが次々と追加されているので非常に複雑です。

「SkeletalMesh」に関しては本1冊分では足りないくらいの情報があるので、簡単な説明だけにして別の機会でSkeletalMeshについてまとめます。

//blankline

「SkeletalMesh」には目に見える「Mesh」情報があります。

「Skeleton」には「Mesh」を動かすための「Bone（骨）」と「Mesh」の「Weight」情報が入っています。

「Bone」を動かす「Animation」情報によって「SkeletalMesh」を動かせます。

道具や武器を持ちたい時は「Socket（ソケット）」を「Skeleton」に追加します。

「Physics（物理）」を「SkeletalMesh」に設定することで重力に従った動きをシミュレーションできます。

最近では「Control Rig」というUE上でRiggingできる仕組みが実装されたので、「Sequencer」で「Animation」を外部ツールを使わなくても作成したり修正できるようになりました。

//blankline
UE5.5では「SkeletalMesh」でも「Nanite」が使える機能が入ってくるそうなので、徐々にハイポリModelをそのまま扱えるような仕組みが整いつつあります。

//pagebreak

== Material

//image[chap03_ue_visual_04][Material][scale=1.0]{
//}

//pagebreak

「Material」は色や質感を調整できる機能です。UEではHLSL（High Level Shading Language）というDirectXで使わられるシェーディング言語をノードベースでシェーダーを組めます。

「Material」はModel、UI、Effect、ポストプロセスといったVisualに関連する機能で必要になります。「Material」のクオリティ次第でゲーム全体の見た目が決まってくるので、テクニカルアーティストとしてはおもしろいお仕事です。

数学的な知識が必要になるので数学について楽しめるとより楽しいです。

//blankline
「Material」で使用している値をパラメータ化することで、「Material Instance」を作成すると後からパラメータの値を調整できます。
「Material Instance」で使用できるパラメータの種類は「オン・オフ（Bool）」「数値（Scalar）」「RGBA情報（Vector4）」「テクスチャ（Texture）」です。

//blankline
複数の「Material」で同時に値を変更したい場合には「Material Parameter Collection」という仕組みが用意されてます。1つの「Material」に対して最大2つまで異なる「Material Parameter Collection」を参照できます。
「Material Parameter Collection」では「数値（Scalar）」「RGBA情報（Vector4）」が扱えます。

//blankline
「Substrate」という新しいMaterialのオーサリング手法が開発段階です。

「Substrate」では1つのマテリアルで質感を実装した「Stab」という単位を複数レイヤーで重ねられるようになります。「Stab」は既存の「Material」でも実装できる「Material Attribute」に近い考えです。1部は組み方を覚えなおすことになりますが、現状の「Material」を「Substrate」に自動で変換する仕組みが用意されています。

//pagebreak

== Texture

//image[chap03_ue_visual_05][Texture][scale=1.0]{
//}

//pagebreak

「Texture」は画像ファイルです。ModelやEffectでは「Material」に使用するチャンネルごとに「Texture」を用意します。UIのように画像Imageとしてそのまま使用したり、UI用の「Material」と組み合わせて使用することがあります。

//blankline
最大4チャンネル（RGBA）の情報を持つことができます。

「Material」の入力で3チャンネル必要とする情報には1ファイルが必要です。

 * BaseColor : 色情報（RGB）や透明（A）の情報
 * Normal : 凹凸の法線（頂点の向いている方向（XYZの3軸情報 or XYの2軸情報））情報

「Material」の入力で1チャンネルしか必要としない場合は複数のチャンネルで使用する「Texture」を組み合わせて1枚の画像にまとめます。このチャンネルをまとめることを「Channel Packaging」と呼び「Texture」ファイルを少なくできます。

//blankline
「Texture」を2のべき乗の幅と高さに作成するとインポート時に「MipMap」を生成し、距離に応じて自動的に画像のサイズを調整してくれます。画面の最前面に表示するUIでは「Texture」を表示するような場合には「MipMap」は必要なので機能をオフにします。

//blankline
ゲーム制作ではTextureは使用方法によって設定方法が変わります。使用方法に応じた設定内容を覚えておくと見え方がガラッと変わるので奥深さを感じています。

//pagebreak

== Landscape

//image[chap03_ue_visual_06][Landscape][scale=1.0]{
//}

//pagebreak

「Landscape」はTerrain（テレイン：地形）を作成する機能です。

//blankline
ペイントツールでスカルプトして地形を作成することもあれば、「Height Map」と呼ばれる高低差を表現した白黒画像を使用して地形を作成します。

木、草や岩などの「Foliage」をペイントして配置できます。

//blankline
「Landscape Material」は1つのマテリアル内で地形の質感をレイヤー化できます。直接ペイントして塗ることもあれば、「Material」で高低差情報を取得してレイヤーを切り替えられます。

//blankline
レイヤー化した地形の質感ごとに「Physics Material」を設定できます。「Physics Material」は設定したオブジェクトの摩擦係数を調整できる特殊なマテリアルです。プログラムでプレイヤーの足元の「Physics Material」が何かを判定して足音を変えることができます。

//blankline
UE5で「PCG（Procedural Content Genrator）」という「Procedural（手続き型）」と呼ばれる繰り返しやランダムをプログラミングできる仕組みが導入されました。範囲指定や乱数を変えることで配置が変えられるので、広範囲の配置物を一瞬で配置できるため期待が高まっています。

//pagebreak

== LightingとLumen

//image[chap03_ue_visual_07][LightingとLumen][scale=1.0]{
//}

//pagebreak

「Lighting」で光や影を描画します。UE5で「Lumen」という次世代コンソール機向けにリアルタイムでGI（Global Illumination）やReflection（反射）を計算するシステムが導入されました。

//blankline
ゲームでは「Lighting」を軽くするために、さまざまな工夫が取り込まれていました。その代表例が「Lighting Build」です。

ゲーム開始前に動かないオブジェクトは「Lighting」の計算を事前に行って、「Lighting Build」で影のTextureをRenderingしていました。ゲームが開始してから動くオブジェクトのみ影をリアルタイムで描写するといった取捨選択を行っていました。

「Lighting Build」で影を事前計算するかは「Mobility」の設定で行います。

 * Static : ゲームが始まってから動かないオブジェクト
 * Stationary : ゲームが始まってから動かないけど、ライトの影響を受けるオブジェクト
 * Movable : ゲームが始まってから動くオブジェクト

「Lighting Build」の品質は「Lightmass Importance Volume」で変更できます。

その他には反射情報の影響を計算するための「Reflection（反射）」用のActorも必要です。

「Lighting Build」を行った後にActorを動かすと影情報が残ってしまうため、再度「Lighting Build」を行う必要がありました。

「Lighting Build」はLevelが大きくなるにつれて計算時間が伸びていきます。「Lighting Build」が完了してからActorを動かすにはリスクを伴いました。

//blankline
次世代コンソール機やゲーミングPCでは「Lighting」をリアルタイムで計算できるようになってきました。

UE5でGI（Global Illumination）をリアルタイムで計算できる「Lumen」が導入されました。

リアルタイムで影の計算することによってさまざまな恩恵を受けられます。

 * Lighting Buildを必要としないので常に最終品質で確認できる
 * Mobilityの設定はすべて「Movable」
 * Lumenの設定は「Post Process Volume」のみで調整できるため

//blankline
「Lumen」は非常に便利な機能ですが、まだすべてのプラットフォームで「Lumen」が使用できる環境が整っていないため、2つの「Lighting」の設定方法についての知識は必要です。

//pagebreak

== Effect（Niagara）

//image[chap03_ue_visual_08][Effect（Niagara）][scale=1.0]{
//}

//pagebreak

「Effect」は2D画像を細かく散らすパーティクルやMeshをアニメーションすることでド派手な演出に使用されます。

UE4の後半のMinorバージョンで「Cascade」から「Niagara」にEffectの機能が拡張されました。UE5でも「Cascade」は使用できますが「Niagara」が一般的になっています。

新しい機能に移行すると「Legacy（遺産）」という名称が追加されます。「Legacy」が付いた機能はいずれ削除される可能性があります。「Legacy」という名称が追加されたら、新しい機能でAssetを作成するようにしてください。

//blankline
「Niagara」では3つのAssetで「Effect」が作成されます。

 * Module  : 1つ1つに機能を持ったBlockを追加してEmitterを作成する
 * Emitter : Moduleの集合体
 * System  : Emitterを組み合わて実際にゲーム上で使用されるEffect

「Niagara」では「Module」をBlueprintで作成できるようになりました。「Cascade」の時にはC++でModuleを作ることはできましたが、機能も限定されていました。「Niagara」になってから「Module」をアーティストが作成できるようになりEffectの幅が広がりました。

//blankline
また「Emitter」をAssetで管理できるようになりました。

 * 「System」で「Emitter」の組み合わせができる
 * 1つの「Emitter」を変更すれば使用している「System」に同じ変更が反映される

//pagebreak

== UI（UMG）

//image[chap03_ue_visual_09][UI（UMG）][scale=1.0]{
//}

//pagebreak

UI（UserInterface）はゲームの操作やガイドを表示します。

ゲームオブジェクトよりも前面にUIを表示するのでHUD（Head Up Display）とも呼びます。

//blankline
UEでは「Unreal Motion Graphics（UMG）」というUIデザイナーでゲームのUIを作成できます。

「UMG」では「Widget」と呼ばれるUIの部品を配置してデザインします。

//blankline
UEでは世界中に配信するために多言語対応できる仕組みが用意されています。とくにFontは使用する言語によってAssetで変更できるようになっています。

//blankline
最前面に表示する以外にも3Dオブジェクトとして立体的に「UMG」を表示できます。

//blankline
UE5.4で「Motion Design」という新機能が試験的機能で導入されました。「UMG」では2Dと3Dが別々に切り分けられていましたが、「Motion Design」では3Dと2Dを組み合わせるコンセプトで作られています。

UIに新しい表現が入れられそうなので今後が楽しみです。

//pagebreak

== Audio（MetaSound）

//image[chap03_ue_visual_10][Audio（MetaSound）][scale=1.0]{
//}

//pagebreak

「Audio」はゲームのBGMやEffectやUIで効果音として使用されます。目には見えませんが「Audio」がAssetに組み合わさることによってリアルな世界が想像できるようになります。

//blankline
UE5で「MetaSound」という新しい高性能オーディオシステムが導入されました。

今まではDTMソフトで作成された音声ファイル（WAVEファイル）をインポートして音声Assetを調整していました。

「MetaSound」ではDTMソフトのように波形から音を作成できるようになりました。実質DTMソフトのようにUE内で音楽を作成する事例も出てきています。

//blankline
「Sound Attenuation（サウンドの減衰）」と「MetaSound」を組み合わせることで立体的な音を再現できます。

//blankline
「MetaSound」についてはZennでまとめていますのでよかったら確認してください。

@<href>{https://zenn.dev/posita33/books/ue5_metasound_createsound}



