make
cc -Wall -Werror -Wextra main.c libft.a -o exec
echo "\n\n"
./exec
echo "\n\n"
rm exec
make fclean