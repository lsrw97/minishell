/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelisaro <eelisaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 15:50:07 by eelisaro          #+#    #+#             */
/*   Updated: 2022/12/06 19:09:05 by eelisaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long long	number;
	long long	i;
	char		c;

	number = n;
	i = 1;
	if (number < 0)
	{
		write(fd, "-", 1);
		number = -number;
	}
	while (number / (i * 10) != 0)
		i *= 10;
	while (i >= 1)
	{
		c = number / i + '0';
		write(fd, &c, 1);
		number %= i;
		i /= 10;
	}
}
