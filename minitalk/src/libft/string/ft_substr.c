/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 12:27:10 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:02:10 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../string/ft_string.h"
#include "../memory/ft_memory.h"
#include <stdlib.h>
#include <unistd.h>

t_string 	ft_substr(t_string s, long from, long to)
{
	t_string 	new;
	long	i;

	if (to < 0)
		to = ft_str_index_of("\0", s) + to;
	if (to < 0)
		to = 0;
	if (to > ft_str_index_of("\0", s) - 1)
		to = ft_str_index_of("\0", s) - 1;
	if (from > to)
		return (NULL);
	new = ft_safe_malloc(to - from + 2);
	i = 0;
	if (!new)
		return (NULL);
	while (s[i] && i <= (to - from))
	{
		new[i] = s[from + i];
		i++;
	}
	new[i] = 0;
	return (new);
}
