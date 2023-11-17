/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelisaro <eelisaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 13:18:10 by eelisaro          #+#    #+#             */
/*   Updated: 2022/12/18 16:58:52 by eelisaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	case_c(char c, int *countchar)
{
	countchar[0]++;
	write(1, &c, 1);
}

void	case_s(char *s, int *countchar)
{
	if (s == NULL)
		s = "(null)";
	countchar[0] += ft_strlen(s);
	ft_putstr_fd(s, 1);
}

void	case_p(unsigned long long d, int *countchar)
{
	if (d == 0)
	{
		write(1, "(nil)", 5);
		countchar[0] += 5;
		return ;
	}
	write(1, "0x", 2);
	countchar[0] += 2;
	printconvfromdec(16, d, "0123456789abcdef", countchar);
}

void	case_d(unsigned long long d, int *countchar)
{
	if (d == 0)
	{
		write(1, "(nil)", 5);
		countchar[0] += 5;
		return ;
	}
	write(1, "0x", 2);
	countchar[0] += 2;
	printconvfromdec(16, d, "0123456789abcdef", countchar);
}

void	case_x(unsigned int d, int *countchar, char *set)
{
	convertx(16, d, set, countchar);
}
