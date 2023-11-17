/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelisaro <eelisaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 17:42:41 by eelisaro          #+#    #+#             */
/*   Updated: 2023/10/17 12:49:47 by eelisaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	int		i;

	i = -1;
	if (ft_strlen(s) < start)
	{
		substr = malloc(sizeof(char) * 1);
		if (!substr || start == 0)
			return (substr);
		substr[0] = '\0';
		return (substr);
	}
	if (len + start < ft_strlen(s))
		substr = malloc(len + 1);
	else
		substr = malloc(ft_strlen(s) - start + 1);
	if (!substr)
		return (NULL);
	while ((size_t)++i < len && s[start] && len)
		if ((size_t)i < len)
			substr[i] = s[start++];
	substr[i] = '\0';
	return (substr);
}

// char
// 	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	size_t	i;
// 	size_t	j;
// 	char	*str;

// 	if (len + start < ft_strlen(s))
// 		str = malloc(len + 1);
// 	else
// 		str = malloc(ft_strlen(s) - start + 1);
// 	if (!str)
// 		return (NULL);
// 	i = 0;
// 	j = 0;
// 	while (s[i])
// 	{
// 		if (i >= start && j < len)
// 		{
// 			str[j] = s[i];
// 			j++;
// 		}
// 		i++;
// 	}
// 	str[j] = 0;
// 	return (str);
// }
