#include <stdio.h>
#include <stdlib.h>

int main ()
{
	void* a = malloc(10);
	printf("%p\n", a);
	a = malloc(12);
	printf("%p\n", a);
	a = malloc(123);
	printf("%p\n", a);
}
