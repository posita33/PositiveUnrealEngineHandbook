rem PDF Extraを閉じる
taskkill /IM PDFExtra.exe

rem PDFを作成する
docker-compose run --rm review rake pdf

rem PDFを開く
start "" "PositiveUnrealEngineHandbook.pdf"
