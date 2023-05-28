/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:43:01 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/05/28 01:24:13 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int	g_bit = 0;

void	received(int sigusr, siginfo_t *info, void *context)
{
	if (sigusr == SIGUSR1)
		g_bit = 0;
	(void)info;
	(void)context;
}

int	check_digit(char *str_pid)
{
	while (*str_pid)
	{
		if (*str_pid >= '0' && *str_pid <= '9')
			str_pid++;
		else
			return (1);
	}
	return (0);
}

void	error(char *msg)
{
	ft_printf("%s\n", msg);
	exit(0);
}

void	send_bit(char *argv, int pid)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < 8)
		{
			if (g_bit == 0)
			{
				g_bit = 1;
				if (*argv >> i & 1)
					kill(pid, SIGUSR1);
				else
					kill(pid, SIGUSR2);
				i++;
			}
			usleep(100);
		}
		if (!*argv)
			break ;
		argv++;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	s_sa;
	sigset_t			sigset;
	pid_t				pid;

	if (argc != 3)
		error("Wrong number of arguments. Use: ./client.c <PID> <message> \n");
	if (check_digit(argv[1]))
		error("Wrong PID number! \n");
	pid = ft_atoi(argv[1]);
	s_sa = (struct sigaction){0};
	sigemptyset(&sigset);
	sigaddset(&sigset, SIGUSR1);
	sigaddset(&sigset, SIGUSR2);
	s_sa.sa_mask = sigset;
	s_sa.sa_flags = SA_SIGINFO;
	s_sa.sa_sigaction = received;
	sigaction(SIGUSR1, &s_sa, NULL);
	sigaction(SIGUSR2, &s_sa, NULL);
	send_bit(argv[2], pid);
}
