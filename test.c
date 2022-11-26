#include <stdio.h>
int	main(void)
{
	printf("Char : {%c}\n\
String : {%s}\n\
Pointer : {%p}\n\
Decimal : {%d}\n\
Integer : {%i}\n\
Unsigned : {%u}\n\
LowHex : {%x}\n\
UppHex : {%X}\n\
Percent : {%%}\n", 'Z', "XYZ", &(int){42}, 21, 21, 21, 21, 21);
}