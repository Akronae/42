#include <stdio.h>
#include "ex07/ft_find_next_prime.c"

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
	printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n",
		   ft_find_next_prime(-1) == 2 ? "OK" : "Fail",
		   ft_find_next_prime(-3) == 2 ? "OK" : "Fail",
		   ft_find_next_prime(0) == 2 ? "OK" : "Fail",
		   ft_find_next_prime(1) == 2 ? "OK" : "Fail",
		   ft_find_next_prime(2) == 2 ? "OK" : "Fail",
		   ft_find_next_prime(3) == 3 ? "OK" : "Fail",
		   ft_find_next_prime(4) == 5 ? "OK" : "Fail",
		   ft_find_next_prime(5) == 5 ? "OK" : "Fail",
		   ft_find_next_prime(6) == 7 ? "OK" : "Fail",
		   ft_find_next_prime(7) == 7 ? "OK" : "Fail",
		   ft_find_next_prime(10) == 11 ? "OK" : "Fail",
		   ft_find_next_prime(11) == 11 ? "OK" : "Fail",
		   ft_find_next_prime(13) == 13 ? "OK" : "Fail",
		   ft_find_next_prime(19) == 19 ? "OK" : "Fail",
		   ft_find_next_prime(20) == 23 ? "OK" : "Fail"
	);
}
