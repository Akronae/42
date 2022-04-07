make re
#clang -Wall -Wextra -Werror -g3 -fsanitize=address tests/tests.c get_next_line.a -o get_next_line_output.out
clang -Wall -Wextra -Werror -ggdb3 tests/tests.c get_next_line.a -o get_next_line_output.out
printf "\n"
printf "\n"
echo ===========================
valgrind --leak-check=full \
         --show-leak-kinds=all \
         --track-origins=yes \
         ./get_next_line_output.out | cat -ve
echo ===========================
rm -rf ./get_next_line_output*
