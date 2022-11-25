/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 02:47:23 by mdupuis           #+#    #+#             */
/*   Updated: 2021/12/01 14:34:36 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	*ft_memset(void *str, int c, size_t count)
{
	unsigned char	*mem;

	mem = (unsigned char *)str;
	while (count--)
		*mem++ = c;
	return (str);
}
