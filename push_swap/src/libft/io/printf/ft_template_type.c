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

enum t_template_type	ft_template_type_from_str(char *s, int *i)
{
	t_template_type	type;
	int 			a;

	*i += 1;
	a = ft_strlen(input + *i) - 1;
	while (a--)
	{
		type = ft_template_type_from_char(ft_substr(input, *i, a));
		if ((int) type != -1)
			break ;
	}
	*i += a - 1;
	return (type);
}