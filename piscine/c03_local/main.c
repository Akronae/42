#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ex05/ft_strlcat.c"
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
	char dest40[20] = "abcdef";
	char dest50[20] = "abcdef";
	char src60[10] = "123";
	printf("ft_strlcat  n = 0: %u\n",ft_strlcat(dest40 , src60, 0));
	printf("%s\n",dest40);
	printf("strlcat n = 0: %lu\n",strlcat(dest50 , src60, 0));
	printf("%s\n\n",dest50);

	char dest41[20] = "abcdef";
	char dest51[20] = "abcdef";
	char src61[10] = "ab";
	printf("ft_strlcat n = 2: %u\n",ft_strlcat(dest41 , src61, 2));
	printf("%s\n",dest41);
	printf("strlcat pour n = 2: %lu\n",strlcat(dest51 , src61, 2));
	printf("%s\n\n",dest51);

	char dest42[20] = "abcdef";
	char dest52[20] = "abcdef";
	char src62[10] = "PO";
	printf("ft_strlcat n = 10: %u\n",ft_strlcat(dest42 , src62, 10));
	printf("%s\n", dest42);
	printf("strlcat n = 10: %lu\n",strlcat(dest52 , src62, 10));
	printf("%s\n\n", dest52);

	char dest43[20] = "";
	char dest53[20] = "";
	char src63[10] = "";
	printf("ft_strlcat n = 2: %u\n",ft_strlcat(dest43 , src63, 2));
	printf("%s\n", dest43);
	printf("strlcat n = 2: %lu\n",strlcat(dest53 , src63, 2));
	printf("%s\n\n", dest53);

	char dest44[20] = "";
	char dest54[20] = "";
	char src64[10] = "123";
	printf("ft_strlcat n = 2: %u\n",ft_strlcat(dest44 , src64, 2));
	printf("%s\n", dest44);
	printf("strlcat n = 2: %lu\n",strlcat(dest54 , src64, 2));
	printf("%s\n\n", dest54);


	char dest45[20] = "abcdef";
	char dest55[20] = "abcdef";
	char src65[10] = "";
	printf("ft_strlcat n = 2: %u\n",ft_strlcat(dest45 , src65, 2));
	printf("%s\n", dest45);
	printf("strlcat  n = 2: %lu\n",strlcat(dest55 , src65, 2));
	printf("%s\n\n", dest55);

	return 0;

}
