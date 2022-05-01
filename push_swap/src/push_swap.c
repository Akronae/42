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

void *lol (int write, void *ptr)
{
	void *a[1];
	if (write)
	{
		a[0] = ptr;
	}
	return a[0];
}

int a () {int a = 1;int b = 1;int c = 1;int d = 1;int e = 3;int f = 3;int g = 3;return 1;}
int b () {return 1;}

int main (int argc, char **argv)
{
	ft_printfl("%p", &a);
	ft_printfl("%p", &b);
	int a = 233;
	lol(0, "");
	lol(0, "");
	lol(1, &a);
	lol(0, "");
	lol(0, "");
	int *ptr = lol(0, NULL);
	ft_printfl("%d", *ptr);
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