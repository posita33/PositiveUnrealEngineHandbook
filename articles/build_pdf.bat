rem PDF Extra�����
taskkill /IM PDFExtra.exe

rem PDF���쐬����
docker-compose run --rm review rake pdf

rem PDF���J��
start "" "PositiveUnrealEngineHandbook.pdf"
