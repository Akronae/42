/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:44:06 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:02:10 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "libft/io/ft_io.h"
#include "libft/list/ft_list.h"
#include "libft/string/ft_string.h"
#include "libft/number/ft_number.h"
#include "libft/memory/ft_memory.h"

t_list *ft_stack_from_input(t_list *input)
{
	if (input->length <= 1)
		ft_exit_err("no arguments supplied");

	t_list *stack = new_list();
	input->i->skip(input->i, 1);
	while (input->i->next(input->i))
	{
		if (!ft_str_is_numeric(input->i->curr->as_str))
			ft_exit_err("element %d is not a number (%s)", input->i->index, input->i->curr->as_str);
		long nbr = ft_str_to_number(input->i->curr->as_str);
		if (nbr < INT_MIN || nbr > INT_MAX)
			ft_exit_err("element %d is out of [INT_MIN, INT_MAX] boundaries (%s)", input->i->index, input->i->curr->as_str);
		stack->push_long(stack, nbr);
	}
	return (stack);
}

void sa (t_list *a)
{
	a->swap(a, -1, -2);
}
const size_t HERE = 1234321;
const size_t GO_BACK = 77577777;

void *laloc_init(void *data_ptr)
{
	void **ptr = malloc(sizeof(void*));
	ft_printfl("static ptr: %p", ptr);
	*ptr = data_ptr;
	size_t *a = malloc(sizeof (size_t));
	*a = HERE;
	return (a);
}

void *find_static_ptr (size_t size_of_data)
{
	size_t *a = malloc(sizeof(size_t));
	*a = GO_BACK;
	while (*a != HERE)
	{
		a -= sizeof (size_t) / 4;
	}
	return a - size_of_data / 4;
}


void clear_static_ptr (size_t size_of_data)
{
	size_t *a = malloc(sizeof(size_t));
	*a = GO_BACK;
	while (*a != HERE)
	{
		*a = 0;
		ft_safe_free(a);
		a -= sizeof (size_t) / 4;
	}
	*a = 0;
	ft_safe_free(a);
	a = a - size_of_data / 4;
	*a = 0;
	ft_safe_free(a);
}

typedef struct env
{
	int a;
	char *b;
} env;
void print_my_data ()
{
	env **here_flag_ptr = find_static_ptr(sizeof(env*));
	ft_printfl("found ptr:  %p", here_flag_ptr);
	ft_printfl("%d", (*here_flag_ptr)->a);
	ft_printfl("%s", (*here_flag_ptr)->b);
}

int main (int argc, char **argv)
{
	env *ptr_i = malloc(sizeof(env));
	ptr_i->a = 32;
	ptr_i->b = ft_strdup("lolahah");
	void* init_addr = laloc_init(ptr_i);
	//malloc(12);
	free(malloc(512));
	free(malloc(512));
	//free(malloc(12));
	print_my_data();
	clear_static_ptr(sizeof (int*));
	ft_printfl("cleared");
	return 0;
	t_list *input = new_list();
	input->from_str_arr(input, argv, 0, argc);
	t_list *stack_a = ft_stack_from_input(input);
	t_list *stack_b = new_list();

	stack_a->swap(stack_a, -1, -2);
	ft_printfl("stack_a\n-----------\n%s{free()}dsds", stack_a->join(stack_a, "\n"));

	input->free(input);
	stack_a->free(stack_a);
	stack_b->free(stack_b);
}