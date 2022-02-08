/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_final_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namrane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 23:09:35 by namrane           #+#    #+#             */
/*   Updated: 2021/07/11 23:38:43 by namrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int		ft_check_line(char *ligne, char c)
{
	int	i;
	int	max;

	max = ft_return_max(newstr);
	i = 1;
	while (i < max)
	{
		if (ligne[i] == c)
			return (0);
		i++;
	}
	return (1);
}

int		ft_check_col(char **table, char *newstr, int x, char c)
{
	int	max;
	int	y;

	max = ft_return_max(newstr);
	y = 0;
	while (y <= max)
	{
		if (table[y][x] == c)
			return (0);
		y++;
	}
	return (1);
}

void	ft_bt(char **table, char *newstr, int col)
{
	int		max;
	int		ligne;
	char	c;

	max = ft_return_max(newstr);
	ligne = 1;
	c = '1';
	if (col == max + 1)
	{
		ft_print_tab(table, newstr, 1);
		return ;
	}
	while (igne < max && ++ligne)
	{
		while (c < max + '0')
		{
			if (ft_check_all(table, newstr, ligne, c))
				break ;
			c++;
		}
		if (c <= max + '0')
		{
			table[col][ligne] = c;
			ft_bt(table, newstr, col + 1);
		};
	}
}
