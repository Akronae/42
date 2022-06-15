#include <stdio.h>
#include "../src/minitalk.h"

#define TEST(aa, ...) {\
   	int a = ft_printf(aa, ##__VA_ARGS__); \
    printf("\n");                   \
	int b = printf(aa, ##__VA_ARGS__);       \
    printf("\n");                   \
	printf("%d, %d\n--------------------\n", a, b); \
}

int main() {
	// disable stdout buffering
	setvbuf(stdout, NULL, _IONBF, 0);
	TEST("%c%c%c*", '\0', '1', 1)
	TEST("lol")
	TEST("")
	TEST("===*")
	TEST("")
	TEST("%c%c", 0, '\a')
	TEST("%X", -42)
	TEST("%p", NULL)
	TEST("%s", ((t_string )NULL))

    return 0;
}
