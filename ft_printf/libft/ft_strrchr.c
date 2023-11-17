/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelisaro <eelisaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 20:06:54 by eelisaro          #+#    #+#             */
/*   Updated: 2022/11/29 20:22:23 by eelisaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*p;

	i = ft_strlen(s);
	if (i == 0 || s[0] == 0)
	{
		if (c == '\0')
			return ((char *)s + ft_strlen(s));
		return (NULL);
	}
	if (i < 0)
		return ((char *)(s));
	while (i != -1)
	{
		if ((unsigned char)s[i] == (unsigned char)c)
		{
			p = (char *)s + i;
			return (p);
		}
		i--;
	}
	return (NULL);
}
