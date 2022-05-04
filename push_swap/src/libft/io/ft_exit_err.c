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

#include "./ft_io.h"
#include "../string/ft_string.h"
#include "../memory/ft_memory.h"
#include <stdlib.h>

void	*ft_exit_err(char *msg, ...)
{
	va_list				args;
	char				*str;

	str = ft_strjoin("Error\n", msg);
	va_start(args, msg);
	ft_print(str, args);
	va_end(args);
	ft_putstr_fd("\n", 1);
	exit(1);
	return (NULL);
}
