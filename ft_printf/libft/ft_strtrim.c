/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelisaro <eelisaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 15:22:03 by eelisaro          #+#    #+#             */
/*   Updated: 2022/12/06 19:33:12 by eelisaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_in_set(const char *set, char c)
{
	int	i;

	i = -1;
	while (set[++i])
	{
		if (set[i] == c)
			return (1);
	}
	return (0);
}

char	*getfinalstring(char *s, int j)
{
	char	*s2;

	s2 = malloc(ft_strlen(s) + 1);
	if (!s2)
	{
		free(s - j);
		return (NULL);
	}
	ft_strlcpy(s2, s, ft_strlen(s) + 1);
	free (s - j);
	return (s2);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	char	*s;
	char	*s2;
	int		j;

	if (!s1 || !set)
		return (NULL);
	j = 0;
	s = malloc(ft_strlen(s1) + 1);
	if (!s)
		return (NULL);
	i = 0;
	ft_strlcpy(s, s1, ft_strlen(s1) + 1);
	while (s[i] && is_in_set(set, s1[i++]) && ++j)
		s += 1;
	i = ft_strlen(s) - 1;
	while (i >= 0 && is_in_set(set, s[i]))
		s[i--] = '\0';
	s2 = getfinalstring(s, j);
	if (!s2)
		return (NULL);
	return ((char *)s2);
}
