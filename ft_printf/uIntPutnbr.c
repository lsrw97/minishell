/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uIntPutnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelisaro <eelisaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 15:50:07 by eelisaro          #+#    #+#             */
/*   Updated: 2022/12/18 13:53:36 by eelisaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	intlength(unsigned int n)
{
	int	i;

	i = 0;
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
	return (i);
}

static char	*ft_itoas(unsigned int n)
{
	char		*str;
	int			len;
	int			i;

	len = intlength(n);
	str = malloc(len + 1);
	if (len == 0 || !str)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	str[len] = '\0';
	while (n != 0)
	{
		i = n % 10;
		str[len-- - 1] = i + 48;
		n /= 10;
	}
	return (str);
}

void	uintputnbr(unsigned int n, int fd, int *len)
{
	char			*str;
	int				i;

	i = 0;
	str = ft_itoas(n);
	while (str[0] != '\0')
	{
		write(fd, str, 1);
		len[0]++;
		i++;
		str++;
	}
	str -= i;
	free (str);
}
