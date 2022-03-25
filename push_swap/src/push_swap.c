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
#include "libft/io/ft_io.h"
#include "libft/list/ft_list.h"
#include "libft/string/ft_string.h"
#include "libft/number/ft_number.h"

void	ft_error()
{
	ft_printfl("Error");
	exit(1);
}

int main (int argc, char **argv)
{
	t_list *list = new_list();

	if (argc <= 1)
		ft_error();

	int i = 1;
	while (i < argc)
	{
		if (!ft_str_is_numeric(argv[i]))
			ft_error();
		list->push_long(list, ft_str_to_number(argv[i]));
		i++;
	}
	struct t_iterator *iterator = list->get_iterator(list);
	while (iterator->current)
	{
		ft_printfl("%d", iterator->next_long(iterator));
	}
	iterator->free(iterator);
	list->free(list);
}