make
echo ===========================
valgrind --leak-check=full \
         --show-leak-kinds=all \
         --track-origins=yes \
         --quiet \
          ./so_long "${@:2}"| cat -ve
echo ===========================