URL="https://c.ndtvimg.com/2019-04/532f6g4c_belt-and-road-xi-jinping_120x90_27_April_19.JPG"
DEST="/tmp/bg-img.jpg"
curl -L $URL --output $DEST
sqlite3 ~/Library/Application\ Support/Dock/desktoppicture.db "update data set value = '$DEST'"
killall Dock
