make re
clang -Wall -Wextra -Werror -g3 -fsanitize=address main.c libftprintf.a -o libftprintf_output
make fclean
echo "\n"
echo "\n"
echo ===========================
./libftprintf_output
echo ===========================
rm -rf ./libftprintf_output*
