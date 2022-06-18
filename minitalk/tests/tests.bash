make
echo ===========================
valgrind --leak-check=full \
         --show-leak-kinds=all \
         --track-origins=yes \
         --quiet \
          ./$1 "${@:2}"| cat -ve
kill -USR2 784607
echo ===========================