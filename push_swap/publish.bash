FILE_DIR=$(dirname "$0")

cd $FILE_DIR

make fclean
PUBLISH_DIR="../$(basename "$PWD")_final"
if [ ! -z "$1" ]; then
  PUBLISH_DIR=$1;
fi;
rm -rf $PUBLISH_DIR
mkdir $PUBLISH_DIR

cp -r src/** $PUBLISH_DIR/
cp -r Makefile $PUBLISH_DIR/