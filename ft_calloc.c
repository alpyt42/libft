/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 10:35:06 by ale-cont          #+#    #+#             */
/*   Updated: 2022/11/11 12:07:16 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*memcal;

	memcal = malloc (size * count);
	if (!memcal)
		return (NULL);
	ft_bzero(memcal, size * count);
	if (!memcal)
		return (NULL);
	return (memcal);
}
