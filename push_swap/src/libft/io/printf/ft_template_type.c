/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_template_type.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:44:06 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:12:23 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../../string/ft_string.h"
#include <stdio.h>

enum t_template_type	ft_template_type_from_char(char *s)
{
	if (ft_str_equal(s, "lld"))
		return (LONGLONG);
	if (ft_str_equal(s, "c"))
		return (CHAR);
	if (ft_str_equal(s, "s"))
		return (STRING);
	if (ft_str_equal(s, "p"))
		return (POINTER);
	if (ft_str_equal(s, "d"))
		return (DECIMAL);
	if (ft_str_equal(s, "i"))
		return (INT);
	if (ft_str_equal(s, "u"))
		return (U_DECIMAL);
	if (ft_str_equal(s, "x"))
		return (HEXADECIMAL);
	if (ft_str_equal(s, "X"))
		return (UPPER_HEXADECIMAL);
	if (ft_str_equal(s, "%"))
		return (PERCENT);
	return (-1);
}

enum t_template_type	ft_template_type_from_str(char *s, size_t *i)
{
	t_template_type	type;
	int 			a;

	*i += 1;
	a = ft_strlen(s + *i) - 1;
	printf("a: %d\n", a);
	while (a-- && a >= 0)
	{
		//printf("'%s'\n", ft_substr("12345", 0, 0));
		printf("--- a: %d, s: %s, i: %zu, sub: %s\n", a, s, *i, ft_substr(s, *i, a));
		type = ft_template_type_from_char(ft_substr(s, *i, *i + a));
		if ((int) type != -1)
			break ;
	}
	if ((int) type != -1)
		*i += a - 2;
	return (type);
}