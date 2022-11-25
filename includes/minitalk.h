/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 21:56:20 by mdupuis           #+#    #+#             */
/*   Updated: 2021/12/01 15:00:13 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# define MAX 200

void	conv_binary(int nb, char *buff);
void	check_signal(int signal);
void	ft_reception(void);
void	char_send(char c, int pid);
void	char_parse(char *str, int pid);
int		ft_check_pid(char *pid);
int		ft_atoi(const char *str);
int		ft_strlen(const char *str);
void	ft_putstr_fd(char *str, int fd);
void	ft_putnbr_fd(int nb, int fd);
void	*ft_memset(void *str, int c, size_t count);

#endif
