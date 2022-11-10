/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:45:46 by ale-cont          #+#    #+#             */
/*   Updated: 2022/11/10 13:52:08 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = strlen(s);
	if (s == NULL)
		return (NULL);
	while (len != 0 && s[len] != c)
		len--;
	if (len == 0 && s[len] != c)
		return (NULL);
	else
		return ((char *)&s[len]);
	return (NULL);
}
