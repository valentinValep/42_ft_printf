#include "sources/ft_printf.h"
#include <stdio.h>
int	main(void)
{
	char *const	a = NULL;

	printf("%d\n", printf("REAL  :\nChar : {%c}\n\
String : {%s}\n\
String : {%s}\n\
Pointer : {%p}\n\
Pointer : {%p}\n\
Decimal : {%d}\n\
Integer : {%i}\n\
Unsigned : {%u}\n\
LowHex : {%x}\n\
UppHex : {%X}\n\
Percent : {%%}\n", 'Z', "XYZ", a, &(int){42}, NULL, -21, -21, -21, -21, -21));

	printf("%d\n", ft_printf("YOURS :\nChar : {%c}\n\
String : {%s}\n\
String : {%s}\n\
Pointer : {%p}\n\
Pointer : {%p}\n\
Decimal : {%d}\n\
Integer : {%i}\n\
Unsigned : {%u}\n\
LowHex : {%x}\n\
UppHex : {%X}\n\
Percent : {%%}\n", 'Z', "XYZ", a, &(int){42}, NULL, -21, -21, -21, -21, -21));
	printf("%d\n", printf("fail : %y\n", 42));
	printf("%d\n", ft_printf("fail : %y\n", 42));
}
