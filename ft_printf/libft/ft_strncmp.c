/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelisaro <eelisaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 20:21:09 by eelisaro          #+#    #+#             */
/*   Updated: 2022/12/03 13:19:41 by eelisaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i != n)
	{
		if (((unsigned char)s1[i]) == '\0' && ((unsigned char)s2[i]) == '\0')
			return (0);
		if (((unsigned char)s1[i]) > ((unsigned char)s2[i])
			|| ((unsigned char)s2[i]) == '\0')
		{
			return (1);
		}
		if (((unsigned char)s1[i]) < ((unsigned char)s2[i])
			|| ((unsigned char)s1[i]) == '\0')
			return (-1);
		i++;
	}
	return (0);
}
