make
clang -Wall -Wextra -Werror -g3 -fsanitize=address tests.c libftprintf.a -o libftprintf_output
printf "\n"
printf "\n"
echo ===========================
./libftprintf_output | cat -ve
echo ===========================
rm -rf ./libftprintf_output*
