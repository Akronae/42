#include "ex02/ft_abs.h"
#include <stdio.h>
#include "ex03/ft_point.h"

void set_point(struct t_point *point)
{
	point->x = 42;
	point->y = 21;
}

int main(void)
{
	struct t_point point;
	set_point(&point);
	printf("%d", point.x);
	return (0);
}