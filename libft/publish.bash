FILE_DIR=$(dirname "$0")

cd $FILE_DIR

PUBLISH_DIR="../$(basename "$PWD")_final"
if [ ! -z "$1" ]; then
  PUBLISH_DIR=$1;
fi;
mkdir $PUBLISH_DIR

cp -r Makefile $PUBLISH_DIR/
cp -r libft.h $PUBLISH_DIR/
cp -r ft_isalpha.c $PUBLISH_DIR/
cp -r ft_isdigit.c $PUBLISH_DIR/
cp -r ft_isalnum.c $PUBLISH_DIR/
cp -r ft_isascii.c $PUBLISH_DIR/
cp -r ft_isprint.c $PUBLISH_DIR/
cp -r ft_strlen.c $PUBLISH_DIR/
cp -r ft_memset.c $PUBLISH_DIR/
cp -r ft_bzero.c $PUBLISH_DIR/
cp -r ft_memcpy.c $PUBLISH_DIR/
cp -r ft_memmove.c $PUBLISH_DIR/
cp -r ft_strlcpy.c $PUBLISH_DIR/
cp -r ft_strlcat.c $PUBLISH_DIR/
cp -r ft_toupper.c $PUBLISH_DIR/
cp -r ft_tolower.c $PUBLISH_DIR/
cp -r ft_strchr.c $PUBLISH_DIR/
cp -r ft_strrchr.c $PUBLISH_DIR/
cp -r ft_strncmp.c $PUBLISH_DIR/
cp -r ft_memchr.c $PUBLISH_DIR/
cp -r ft_memcmp.c $PUBLISH_DIR/
cp -r ft_strnstr.c $PUBLISH_DIR/
cp -r ft_atoi.c $PUBLISH_DIR/
cp -r ft_calloc.c $PUBLISH_DIR/
cp -r ft_strdup.c $PUBLISH_DIR/
cp -r ft_substr.c $PUBLISH_DIR/
cp -r ft_strjoin.c $PUBLISH_DIR/
cp -r ft_strtrim.c $PUBLISH_DIR/
cp -r ft_split.c $PUBLISH_DIR/
cp -r ft_itoa.c $PUBLISH_DIR/
cp -r ft_strmapi.c $PUBLISH_DIR/
cp -r ft_striteri.c $PUBLISH_DIR/
cp -r ft_putchar_fd.c $PUBLISH_DIR/
cp -r ft_putstr_fd.c $PUBLISH_DIR/
cp -r ft_putendl_fd.c $PUBLISH_DIR/
cp -r ft_putnbr_fd.c $PUBLISH_DIR/