/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_err.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 11:23:58 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:02:10 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../libft.h"
#include "./ft_io.h"
#include "../string/ft_string.h"
#include "../memory/ft_memory.h"

void	*ft_exit_err(t_str msg, ...)
{
	va_list	args;
	int		*a;
	t_str str;

	a = (int *) 1;
	ft_putstr_fd("Error\n", 1);
	str = ft_strjoin(msg, "\n");
	va_start(args, msg);
	ft_print(str, args);
	va_end(args);
	ft_safe_free(str);
	if (ENV_DEV)
		*a = 0;
	exit(1);
	return (NULL);
}
