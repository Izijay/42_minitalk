/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 21:19:23 by mdupuis           #+#    #+#             */
/*   Updated: 2021/12/01 11:02:48 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	char_send(char c, int pid)
{
	char	p;
	int		i;

	i = -1;
	p = '\0';
	while (++i < 8)
	{
		if (((c >> p++) & 1) == 1)
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				ft_putstr_fd("Error: Unable to send signal1.\n", 2);
				exit (1);
			}
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				ft_putstr_fd("Error: Unable to send signal2.\n", 2);
				exit (1);
			}
		}
		usleep(200);
	}
}

void	char_parse(char *str, int pid)
{
	int		i;

	i = 0;
	while (str[i])
	{
		char_send(str[i], pid);
		i++;
	}
	char_send(str[i], pid);
}

void	check_signal(int signal)
{
	(void) signal;
}

int	main(int ac, char **av)
{
	if (ac != 3)
	{
		ft_putstr_fd("Error! Bad argument.\n", 2);
		return (1);
	}
	if (!ft_check_pid(av[1]))
		return (1);
	if (signal(SIGUSR1, check_signal) == SIG_ERR
		|| signal(SIGUSR2, check_signal) == SIG_ERR)
	{
		ft_putstr_fd("Error: Bad signal.\n", 2);
		exit (1);
	}
	char_parse(av[2], ft_atoi(av[1]));
	return (0);
}
