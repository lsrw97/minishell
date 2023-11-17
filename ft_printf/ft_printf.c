/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelisaro <eelisaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 14:55:31 by eelisaro          #+#    #+#             */
/*   Updated: 2022/12/18 16:41:02 by eelisaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include "./libft/libft.h"
#include "ft_printf.h"

void	casepercent(int	*countchar)
{
	ft_putchar_fd('%', 1);
	countchar[0]++;
}

void	converter(va_list ap, int *countchar, char c)
{
	if (c == 'c')
		case_c((char)va_arg(ap, int), countchar);
	else if (c == 's')
		case_s(va_arg(ap, char *), countchar);
	else if (c == 'p')
		case_p(va_arg(ap, unsigned long long), countchar);
	else if (c == 'd')
		ft_putnbr_fd_mod(va_arg(ap, int), 1, countchar);
	else if (c == 'i')
		ft_putnbr_fd_mod(va_arg(ap, int), 1, countchar);
	else if (c == 'u')
		uintputnbr((unsigned int) va_arg(ap, int), 1, countchar);
	else if (c == 'x')
		case_x(va_arg(ap, long), countchar, "0123456789abcdef");
	else if (c == 'X')
		case_x(va_arg(ap, long), countchar, "0123456789ABCDEF");
	else if (c == '%')
		casepercent(countchar);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		countchar[1];
	va_list	ap;

	countchar[0] = 0;
	va_start(ap, str);
	i = -1;
	while (str[++i])
	{
		if (str[i] == '%')
		{
			i++;
			converter(ap, countchar, str[i]);
			continue ;
		}
		write(1, &str[i], 1);
		countchar[0]++;
	}
	va_end(ap);
	return (countchar[0]);
}
