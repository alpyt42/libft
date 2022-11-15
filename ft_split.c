/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:45:19 by ale-cont          #+#    #+#             */
/*   Updated: 2022/11/15 12:41:52 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_freeall(char **res, int args)
{
	int	i;

	i = 0;
	while (i < args)
	{
		free(res[i]);
		i++;
	}
	free(res);
	return (NULL);
}

static int	ft_nbline(char const *s, char c)
{
	int	i;
	int	len;

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

static char	*ft_createline(char const *s, char c, char **res)
{
	int		len;
	int		j;
	char	*line;

	len = 0;
	j = 0;
	while (s[len] != c && s[len] != '\0')
		len++;
	line = (char *)malloc(sizeof(char) * (len + 1));
	if (!line)
		return ((char *)ft_freeall(res, ft_nbline(s, c)));
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
	int		i;
	int		j;
	char	**str;

	i = 0;
	j = 0;
	str = (char **)malloc(sizeof(char *) * (ft_nbline(s, c) + 1));
	if (!str)
		return (NULL);
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i != '\0'])
			i++;
		if (s[i] != c && s[i != '\0'])
		{
			str[j] = ft_createline(&s[i], c, str);
			j++;
		}
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	str[j] = NULL;
	return (str);
}

// int main(void)
// {
// 	char **tab = ft_split("split", 'l');
//     char s[] = "Bonjour";
//     char c = 'o';
//     char **res = ft_split(s,c);
// 	printf("%s", tab[0]);
// }