#include <stdio.h>

#define p(x, ...) { \
printf(_Generic(x, unsigned: "%u\n", signed: "%d\n", double: "%g\n", long int: "%ld\n", long long int: "%lld\n", unsigned long: "%lu\n", unsigned long long int: "%llu\n", char: "%c\n", char *: "%s\n"), x);\
}
#define p_nonl(x) {\
printf(_Generic(x, unsigned: "%u", signed: "%d", double: "%g", long int: "%ld", long long int: "%lld", unsigned long: "%lu", unsigned long long int: "%llu", char: "%c", char *: "%s"), x);\
}
#define parr(my_array) {\
unsigned long index;\
p_nonl("[");\
for( index = 0; index < (sizeof( my_array ) / sizeof( my_array[0] )); index++){\
        p_nonl(my_array[index]);\
p_nonl(", ");\
}\
p_nonl("]");\
}
#define parrmem(my_array) {\
int i = -1;\
p_nonl("[");\
while (my_array[++i]){\
        p_nonl(my_array[i]);\
p_nonl(", ");\
}\
p_nonl("]");\
}

#include "ex03/ft_strjoin.c"

int main()
{
	char **a= malloc(100);
	a[0] = malloc(100);
	a[0][0] = 'a';
	a[0][1] = 'c';
	a[0][2] = 'a';
	a[1] = malloc(100);
	a[1][0] = 'a';
	a[1][1] = 'c';
	a[1][2] = 'a';
	p(ft_strjoin(2, a, " "));
	p(23)
	return 0;
}
