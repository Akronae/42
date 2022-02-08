#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

#define p(x) {\
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

int main() {
    char **s2 = ft_split("je suis un test", ' ');

    printf("0: %s\n", s2[0]);
    printf("1: %s\n", s2[1]);
    printf("2: %s\n", s2[2]);
    printf("3: %s\n", s2[3]);

    free(s2[0]);
    free(s2[1]);
    free(s2[2]);
    free(s2[3]);

    return 0;
}
