/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namrane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 21:51:51 by namrane           #+#    #+#             */
/*   Updated: 2021/07/11 21:52:26 by namrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	main(int ac, char **av)
{
	char	*tab = ft_newstr(av[1]);

	if (ac == 2)
	{
		printf("%d\n", ft_strlen(av[1]));
		//printf("%d\n", ft_newstr(av[1]));
		printf("%s", tab);
	}
	else
		write(1, "Error\n", 6);
}
