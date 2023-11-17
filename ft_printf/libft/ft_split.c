/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelisaro <eelisaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 21:04:00 by eelisaro          #+#    #+#             */
/*   Updated: 2022/12/03 14:34:49 by eelisaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ts(char *s, char c)
{
	int	i;
	int	total;
	int	x;

	i = 0;
	total = 0;
	x = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			if (x != 1)
				total++;
			i++;
			x = 1;
		}
		else
		{
			i++;
			x = 0;
		}
	}
	if (total == 0)
		return (1);
	return (total);
}

static char	*makeword(char *str, int start, int end)
{
	char	*s;
	int		i;

	i = 0;
	s = malloc((end - start) + 1);
	if (!s)
		return (NULL);
	while (start < end)
		s[i++] = str[start++];
	s[i] = '\0';
	return (s);
}

static int	vl(char *s, char c)
{
	int	i;

	i = -1;
	while (s[++i])
		if (s[i] != c)
			return (1);
	return (0);
}

static char	**fillwords(char **str, char *s, char c)
{
	size_t	start;
	size_t	end;
	size_t	i;

	i = 0;
	start = 0;
	end = 0;
	while (i <= (size_t)(ts((char *)s, c) - 1))
	{
		if (s[end] && s[end] == c)
		{
			end++;
			start = end;
			continue ;
		}
		while (s[end] && s[end] != c)
			end++;
		str[i] = makeword((char *)s, start, end);
		if (!str[i])
			return (NULL);
		i++;
	}
	str[i] = NULL;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;

	if (ts((char *)s, c) == 1
		&& (ft_strlen((char *)s) == 0 || !vl((char *)s, c)))
	{
		str = malloc (sizeof(char *) * 1);
		str[0] = NULL;
		return (str);
	}
	str = malloc((sizeof(char *) * (ts((char *)s, c) + 1)));
	if (!str)
		return (NULL);
	return (fillwords(str, (char *)s, c));
}
