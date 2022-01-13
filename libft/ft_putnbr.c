/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 11:30:05 by adaubric          #+#    #+#             */
/*   Updated: 2022/01/13 11:33:17 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putnbr(n / 10, fd);
		ft_putnbr(-(n % 10), fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n > 9)
	{
		ft_putnbr(n / 10, fd);
	}
	ft_putchar_fd(n % 10 + '0', fd);
}
