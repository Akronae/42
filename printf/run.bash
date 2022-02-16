make re
clang -g3 -fsanitize=address main.c libftprintf.a -o libftprintf_output
make fclean
echo "\n"
echo "\n"
echo ===========================
./libftprintf_output
echo ===========================
rm ./libftprintf_output*