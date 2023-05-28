/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:43:35 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/05/28 04:14:54 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk_bonus.h"

char	g_char = 0;

void	print_char(int signal, siginfo_t *siginfo, void *context)
{
	static int	i = 0;

	(void)context;
	if (signal == SIGUSR1)
		g_char += (1 << i);
	if (i == 7)
	{
		if (g_char)
			write(1, &g_char, 1);
		else
		{
			write(1, "\n", 1);
			kill(siginfo->si_pid, SIGUSR2);
		}
		g_char = 0;
		i = 0;
	}
	else
		i++;
	kill(siginfo->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	s_sa;
	sigset_t			sigset;

	sigemptyset(&sigset);
	sigaddset(&sigset, SIGUSR1);
	sigaddset(&sigset, SIGUSR2);
	s_sa.sa_handler = NULL;
	s_sa.sa_mask = sigset;
	s_sa.sa_flags = SA_SIGINFO;
	s_sa.sa_sigaction = print_char;
	sigaction(SIGUSR1, &s_sa, NULL);
	sigaction(SIGUSR2, &s_sa, NULL);
	ft_printf("PID = %d\n", getpid());
	while (1)
		pause();
}
