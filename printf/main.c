#include <stdio.h>
#include <stdlib.h>
#include "src/ft_printf.h"
#include "src/ft_link.h"
#include "src/ft_iterator.h"
#include "src/ft_hex.h"
#include "src/ft_long.h"

int main() {
    printf("Hello, World!\n");
//	t_link *l = new_link();
//	l->data = malloc(sizeof(int));
//	*((int *)l->data) = 2;
//	l = l->insert(l);
//	l->data = malloc(sizeof(int));
//	*((int *)l->data) = 7;
//	l = l->insert(l);
//	l->data = malloc(sizeof(int));
//	*((int *)l->data) = 93;
//	l = l->reverse(l);
//	t_iterator *iterator = new_iterator(l->get_first(l));
//	while (iterator->current) printf("%d\n", *((int *)iterator->next(iterator)));
//	iterator->free(iterator);

	int a = 12;
	ft_printf("%c <----c assd! %i %s pointer=%p NULL=%p llong=%u 66 in HEX=%X percent=%%\n", 'd', 12, "lalalala", &a, NULL, -465454654546546546, 66);
	printf("%X\n", 654654654);
    return 0;
}
