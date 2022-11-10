/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:14:06 by ale-cont          #+#    #+#             */
/*   Updated: 2022/11/09 16:13:46 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen(const char *s)
{
	int	j;

	j = 0;
	while (s[j])
		j++;
	return (j);
}

size_t	ft_strlcat(char * dst, const char * src, size_t dstsize)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(dst);
	if (dstsize == 0 || dstsize <= len)
		return (ft_strlen(src) + dstsize);
	while (i < (dstsize - len) && src[i])
	{
		dst[len + i] = src[i];
		i++;
	}
	dst[i + len] = '\0';
	return (ft_strlen(src) + len);
}
