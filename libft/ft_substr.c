/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 12:27:10 by adaubric          #+#    #+#             */
/*   Updated: 2022/01/06 12:29:45 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, int len)
{
	int		i;
	char	*str;

	str = (char *)malloc(sizeof(*s) * (len + 1));
	if (!str)
		return (NULL);
	i = start;
	while (s[i] && i < len)
	{
		str[i - start] = s[i];
		i++;
	}
	str[i - start] = 0;
	return (str);
}
