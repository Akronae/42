/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namrane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 21:51:07 by namrane           #+#    #+#             */
/*   Updated: 2021/07/11 22:40:03 by namrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	ft_strlen(char *str)
{
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	while (str[i])
	{
		if (!(i % 2))
			j++;
		i++;
	}
	if (ft_sqrt(i))
		return (j);
	else
		return (0);
}

int	ft_return_max(char *newstr)
{
	int	i;
	
	i = 0;
	while (newstr[i])
		i++;
	if (i >= 16 && i <= 36 && !(i % 4))
		return (i);
	else
		return (0);
}

int	ft_check_number(char *newstr)
{
	int		i;
	char	max;

	i = 0;
	if (!(max = (ft_return_max(newstr) / 4) + '0'))
		return (0);
	while (newstr[i])
	{
		if (!(newstr[i] >= '1' && newstr[i] <= max))
			return (0);
		i++;
	}
	return (1);
}
