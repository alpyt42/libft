/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 20:50:57 by ale-cont          #+#    #+#             */
/*   Updated: 2022/11/10 10:34:31 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*find;
	char	*str;
	int		i;
	int		j;

	str = (char*)haystack;
	find = (char*)needle;
	i = 0;
	if (!find)
		return (NULL);
	while (str[i] && len--)
	{
		j = 0;
		while (str[i + j] == find[j] && str[i + j] && find[j])
			j++;
		if (find[j] == '\0')
			return (&str[i]);
		i++;
	}
	return (NULL);
}