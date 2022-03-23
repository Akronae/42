make re
clang -Wall -Wextra -Werror -g3 -fsanitize=address tests/tests.c get_next_line.a -o get_next_line_output.out
printf "\n"
printf "\n"
echo ===========================
./get_next_line_output.out | cat -ve
echo ===========================
rm -rf ./get_next_line_output*
