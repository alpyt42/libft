/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:45:19 by ale-cont          #+#    #+#             */
/*   Updated: 2022/11/21 12:23:22 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_freeall(char **res, size_t args)
{
	size_t	i;

	i = 0;
	while (res[i] && i < args)
	{
		free(res[i]);
		i++;
	}
	free(res);
	return (NULL);
}

static size_t	ft_nbline(char const *s, char c)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
			len++;
		while (s[i] != c && s[i])
			i++;
	}
	return (len);
}

static char	*ft_createline(char const *s, char c)
{
	size_t		len;
	size_t		j;
	char		*line;

	len = 0;
	j = 0;
	while (s[len] != c && s[len] != '\0')
		len++;
	line = (char *)malloc(sizeof(char) * (len + 1));
	if (!line)
		return (NULL);
	while (j < len)
	{
		line[j] = s[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	**ft_split(char const *s, char c)
{
	size_t		i;
	size_t		j;
	char		**str;

	i = 0;
	j = 0;
	str = (char **)malloc(sizeof(char *) * (ft_nbline(s, c) + 1));
	if (!str)
		return (NULL);
	while (j < ft_nbline(s, c))
	{
		while (s[i] == c && s[i != '\0'])
			i++;
		if (s[i] != c && s[i != '\0'])
		{
			str[j] = ft_createline(&s[i], c);
			if (!str[j])
				return ((char **)ft_freeall(str, ft_nbline(s, c)));
			j++;
		}
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	str[j] = NULL;
	return (str);
}
