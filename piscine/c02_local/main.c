#include <stdio.h>
#include <string.h>
#include "ex10/ft_strlcpy.c"
#define p(x, ...) { \
printf(_Generic(x, unsigned: "%u\n", signed: "%d\n", double: "%g\n", long int: "%ld\n", long long int: "%lld\n", unsigned long: "%lu\n", unsigned long long int: "%llu\n", char: "%c\n", char *: "%s\n"), x);\
}
#define p_nonl(x) {\
printf(_Generic(x, unsigned: "%u", signed: "%d", double: "%g", long int: "%ld", long long int: "%lld", unsigned long: "%lu", unsigned long long int: "%llu", char: "%c", char *: "%s"), x);\
}
#define parr(my_array) {\
int index;\
p_nonl("[");\
for( index = 0; index < (sizeof( my_array ) / sizeof( my_array[0] )); index++){\
        p_nonl(my_array[index]);\
p_nonl(", ");\
}\
p_nonl("]");\
}

int main()
{
	char dst[] = "Co";
	char src[] = "q";
	p(strlcpy(dst, src, 2));
	p(src)
	p(dst)
	return 0;
}
