/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
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
#include "libft/logic/ft_logic.h"

void	ft_signal_handler(int signum, siginfo_t *info, void *context)
{
	ft_printfl("received signal signum: %d, from pid: %, context: %p", signum, info->si_pid, context);
}

int	main(int argc, char **argv)
{
	struct sigaction	sa_signal;
	sigset_t			block_mask;

	ft_printfl("Im a serv with %d args which is the first is: %s", argc, argv[0]);

	sigemptyset(&block_mask);
	sigaddset(&block_mask, SIGINT);
	sigaddset(&block_mask, SIGQUIT);
	sa_signal.sa_handler = 0;
	sa_signal.sa_flags = SA_SIGINFO;
	sa_signal.sa_mask = block_mask;
	sa_signal.sa_sigaction = ft_signal_handler;
	sigaction(SIGUSR1, &sa_signal, NULL);
	sigaction(SIGUSR2, &sa_signal, NULL);
	ft_printfl("server PID: %d", getpid());
	while (true)
		pause();
}
