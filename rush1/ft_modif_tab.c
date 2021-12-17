/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modif_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namrane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 21:51:31 by namrane           #+#    #+#             */
/*   Updated: 2021/07/11 21:51:43 by namrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

char	*ft_newstr(char *str)
{
	char	*newstr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	newstr = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
	if (!(newstr))
		return (0);
	while (str[i])
	{
		if (str[i] != ' ')
			newstr[j++] = str[i];
		i++;
	}
	newstr[j] = 0;
	return (newstr);
}
