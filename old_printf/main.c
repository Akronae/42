#include <stdio.h>
#include "src/ft_printf.h"

int main() {
	int a = 12;
    printf("Hello, World!\n");
	ft_printf("%c <----c assd %i %s pointer=%p \n", 'd', 12, "lalalala", &a);
	printf("%p\n", &a);
    return 0;
}
