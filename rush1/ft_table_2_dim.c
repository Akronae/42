/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_table_2_dim.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namrane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 21:53:24 by namrane           #+#    #+#             */
/*   Updated: 2021/07/11 23:17:20 by namrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

char	**init_table(char *newstr)
{
	char	**table;

	table = (char **)malloc(sizeof(char *) * ft_return_max(newstr) + 3);
	if (!(table) || !(ft_check_number(newstr)))
		return (0);
	return (table);
}

void	ft_init_place(char **table, char *newstr)
{
	int	max;
	int	x;
	int	y;
	int	i;

	max = ft_return_max(newstr) + 2;
	x = 1;
	y = 0;
	i = 0;
	while (newstr[j])
	{
		if (x == (max - 1))
			y++;
		if (position == 0 || position == 5)
			tab[y][x++] = newstr[j++];
		else if (position > 0 && position < 5)
		{
			tab[y][0] = newstr[j++];
			tab[y][max - 1] = newstr[j++];
		}
		i++;
	}
}

void	ft_print_tab(char **table, char *newstr, int col)
{
	int	max;
	int	i;

	i = 1;
	max = ft_return_max(newstr);
	if (table[col])
	{
		while (i < max)
			ft_putchar(table[col][i++]);
		ft_print_tab(table, newstr, col + 1);
	}
}
