/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:13:58 by ale-cont          #+#    #+#             */
/*   Updated: 2022/11/11 13:30:23 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	char	*tmp;

	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	tmp = str;
	s += start;
	while (str && len--)
		*str++ = *s++;
	*str = '\0';
	return (tmp);
}
