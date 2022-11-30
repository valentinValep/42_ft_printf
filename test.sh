make
cc -Wall -Wextra main.c libftprintf.a -o exec -g3
echo "\n\n"
valgrind ./exec
echo "\n\n"
rm exec
make fclean