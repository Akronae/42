make
gcc libftprintf.a -o libftprintf_output
echo ===========================
./libftprintf_output
echo ===========================
make fclean
rm ./libftprintf_output*