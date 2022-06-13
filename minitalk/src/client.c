/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:44:06 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:02:10 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "minitalk.h"
#include "libft/io/ft_io.h"
#include "libft/number/ft_number.h"

int	main(int argc, char **argv)
{
	ft_printfl("Im a client with %d args which is the first is: %s", argc, argv[0]);
	kill(ft_str_to_number(argv[1]), SIGUSR2);
	kill(ft_str_to_number(argv[1]), SIGUSR1);
}
