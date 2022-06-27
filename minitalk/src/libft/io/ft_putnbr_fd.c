/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 11:23:58 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:02:10 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../string/ft_string.h"
#include "../number/ft_number.h"
#include "../memory/ft_memory.h"
#include "ft_io.h"
#include <unistd.h>

void	ft_putnbr_fd(llong nbr, int fd)
{
	t_str str = ft_number_to_str(nbr);
	ft_putstr_fd(str, fd);
	ft_safe_free(str);
}
