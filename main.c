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
Percent : {%%}\n\
String : {%s}\n\
", 'Z', "XYZ", a, &(int){42}, NULL, -21, -21, -21, -21, -21, "TEST"));

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
Percent : {%%}\n\
String : {%s}\n\
", 'Z', "XYZ", a, &(int){42}, NULL, -21, -21, -21, -21, -21, "TEST"));
	printf("%d\n", printf("fail : %y\n", 42));
	printf("%d\n", ft_printf("fail : %y\n", 42));

	printf("\n\n");
	printf("%d\n", printf("%d<-int\n", 42));
	printf("%d\n", ft_printf("%d<-int\n", 42));

	printf("\n\n");
	printf("%d\n", printf("%c<-\\0\n", 0));
	printf("%d\n", ft_printf("%c<-\\0\n", 0));

	printf("\n\n");
	printf("\n%d\n", printf("TEST%"));
	printf("\n%d\n", ft_printf("TEST%"));

	printf("\n\n");
	printf("\n%d\n", printf(""));
	printf("\n%d\n", ft_printf(""));

	printf("\n\n");
	printf("\n%d\n", printf("%c", 'a'));
	printf("\n%d\n", ft_printf("%c", 'a'));

	printf("\n\n");
	printf("\n%d\n", printf("1, 2, 3, -d test, testing, 0.4s sound, 1, 2, 3xp, sound, -*dtest"));
	printf("\n%d\n",ft_printf("1, 2, 3, -d test, testing, 0.4s sound, 1, 2, 3xp, sound, -*dtest"));
}
