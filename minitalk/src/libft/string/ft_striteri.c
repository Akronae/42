/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 12:56:43 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:02:10 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "../string/ft_string.h"

void	ft_striteri(t_str s, void (*f)(uint, t_str))
{
	uint	i;

	if (!s || !f)
		return ;
	i = 0;
	while (*s != '\0')
	{
		f(i, s);
		i++;
		s++;
	}
}
