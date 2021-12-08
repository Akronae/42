ARGS=$(find *.c ! -name "main.c")

if test "$#" -gt 0; then
  ARGS="$@"
fi

python3.8 -m norminette $ARGS