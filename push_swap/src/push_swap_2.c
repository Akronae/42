/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_2.c                                      :+:      :+:    :+:   */
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

void	f(t_list *free_1, t_list *free_2, char *err, ...)
{
	va_list	args;

	va_start(args, err);
	if (err)
	{
		ft_printfl("Error");
		ft_print(err, args);
	}
	va_end(args);
	if (free_1)
		free_1->free(free_1);
	if (free_2)
		free_2->free(free_2);
	exit(1);
}

t_list	*ft_stack_from_input(t_list *input)
{
	t_list	*stack;
	long	nbr;

	if (input->length <= 1)
		f(input, NULL, NULL);
	stack = new_list();
	input->i->skip(input->i, 1);
	while (input->i->next(input->i))
	{
		if (!ft_str_is_numeric(input->i->curr->data->as_str))
			f(input, stack, "element %d is not a number (%s)\n", input->i->index,
				input->i->curr->data->as_str);
		nbr = ft_str_to_number(input->i->curr->data->as_str);
		if (nbr < INT_MIN || nbr > INT_MAX)
			f(input, stack, "element %d is out of [INT_MIN, INT_MAX] boundaries"
				" (%s)\n", input->i->index, input->i->curr->data->as_str);
		stack->push_long(stack, nbr);
		if (stack->count(stack, stack->get_elem(stack, -1)->data) > 1)
			f(input, stack, "element %d is a duplicate parameter (%s)"
				"\n", input->i->index, input->i->curr->data->as_str);
	}
	return (stack->reverse(stack));
}
