/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelisaro <eelisaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 17:56:45 by eelisaro          #+#    #+#             */
/*   Updated: 2022/12/03 14:33:47 by eelisaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	intlen(int n)
{
	int	i;
	int	neg;

	i = 0;
	if (n < 0)
		neg = 1;
	else
		neg = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		if (n == 0)
		{
			i++;
			return (i);
		}
		n /= 10;
		i++;
	}
	return (i + neg);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			len;
	int			i;
	long int	num;

	num = n;
	len = intlen(num);
	str = malloc(len + 1);
	if (len == 0 || !str)
		return (NULL);
	if (num == 0)
		str[0] = '0';
	if (num < 0)
	{
		str[0] = '-';
		num *= -1;
	}
	str[len] = '\0';
	while (num != 0)
	{
		i = num % 10;
		str[len-- - 1] = i + 48;
		num /= 10;
	}
	return (str);
}
