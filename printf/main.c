#include <stdio.h>
#include <stdlib.h>
#include "src/ft_printf.h"
#include "src/libft/link/ft_link.h"
#include "src/libft/iterator/ft_iterator.h"
#include "src/libft/hex/ft_hex.h"
#include "src/libft/number/ft_number.h"

int main() {
    printf("Hello, World!\n");

//	int a = 12;
//	ft_printf("%c <----c assd! %i %s pointer=%p NULL=%p llong=%u 66 in HEX=%X percent=%%\n", 'd', 12, "lalalala", &a, NULL, -465454654546546546, 66);

	int a = ft_printf(" %c %c %c \n", '0', 0, '1');
	int b = printf(" %c %c %c \n", '0', 0, '1');
	printf("%d, %d", a, b);
    return 0;
}
