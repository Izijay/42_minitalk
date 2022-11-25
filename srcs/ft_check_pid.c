/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_pid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 10:38:51 by mdupuis           #+#    #+#             */
/*   Updated: 2021/11/24 12:23:24 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int	ft_is_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}

int	ft_check_pid(char *pid)
{
	if (!ft_is_digit(pid))
	{
		printf("Error ! PID must contain only numbers !\n");
		return (0);
	}
	if (ft_atoi(pid) < 1 || ft_atoi(pid) > 4194304)
	{
		printf("Error ! PID not valid ! \n");
		return (0);
	}
	return (1);
}
