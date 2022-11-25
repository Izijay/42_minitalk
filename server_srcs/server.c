/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 21:36:45 by mdupuis           #+#    #+#             */
/*   Updated: 2021/12/01 15:08:10 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	ft_print(char *buff, int *i)
{
	write(1, buff, ft_strlen(buff));
	write(1, "\n", 1);
	ft_memset(buff, 0, MAX);
	*i = 0;
}

void	conv_binary(int nb, char *buff)
{
	static int	i = 0;
	static char	c;
	static int	nb_bit = 0;

	c = c + (nb << nb_bit++);
	if (nb_bit == 8)
	{
		buff[i] = c;
		c = '\0';
		nb_bit = 0;
		if (i == MAX - 1)
		{
			write(1, buff, ft_strlen(buff));
			ft_memset(buff, 0, MAX);
			i = 0;
		}
		else
		{
			if (buff[i++] == '\0')
			{
				ft_print(buff, &i);
				return ;
			}
		}
	}
}

void	check_signal(int signal)
{
	char	buff[MAX];

	if (signal == SIGUSR1)
		conv_binary(1, buff);
	if (signal == SIGUSR2)
		conv_binary(0, buff);
}

void	ft_reception(void)
{
	if (signal(SIGUSR1, check_signal) == SIG_ERR
		|| signal(SIGUSR2, check_signal) == SIG_ERR)
	{
		ft_putstr_fd("Error: Bad signal.\n", 2);
		exit(1);
	}
}

int	main(int ac, char **av)
{
	(void)av;
	if (ac != 1)
	{
		ft_putstr_fd("Error ! No argument needed.\n", 2);
		return (1);
	}
	ft_reception();
	ft_putstr_fd("PID is : [[ ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd(" ]]\n", 1);
	usleep(100);
	while (1)
		pause();
	return (0);
}
