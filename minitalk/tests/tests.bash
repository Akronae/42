make
echo ===========================
valgrind --leak-check=full \
         --show-leak-kinds=all \
         --track-origins=yes \
         --quiet \
          ./server $@| cat -ve
kill -USR2 784607
echo ===========================