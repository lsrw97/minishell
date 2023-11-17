/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printconvfromdec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelisaro <eelisaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 13:51:05 by eelisaro          #+#    #+#             */
/*   Updated: 2022/12/18 13:52:04 by eelisaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printconvfromdec(int tobase, uintptr_t number, char *set, int *len)
{
	if (number / tobase == 0)
	{
		write(1, &set[number % tobase], 1);
		len[0]++;
	}
	else
	{
		printconvfromdec(tobase, (number / tobase), set, len);
		if (number == 0)
			number *= -1;
		write(1, &set[number % tobase], 1);
		len[0]++;
	}
}
