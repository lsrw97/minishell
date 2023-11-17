/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertX.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelisaro <eelisaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 13:52:13 by eelisaro          #+#    #+#             */
/*   Updated: 2022/12/18 13:52:37 by eelisaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	convertx(int tobase, unsigned int number, char *set, int *len)
{
	if (number / tobase == 0)
	{
		write(1, &set[number % tobase], 1);
		len[0]++;
	}
	else
	{
		convertx(tobase, (number / tobase), set, len);
		if (number == 0)
			number *= -1;
		write(1, &set[number % tobase], 1);
		len[0]++;
	}
}
