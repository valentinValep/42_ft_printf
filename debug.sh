make
cc -Wall -Werror -Wextra main.c libft.a -o exec -g3
echo "\n\n"
lldb ./exec
echo "\n\n"
rm exec
make fclean