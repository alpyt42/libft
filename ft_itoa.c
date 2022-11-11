/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 19:14:32 by ale-cont          #+#    #+#             */
/*   Updated: 2022/11/11 20:10:47 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int	i;
	int	len;
	int	nb;
	int	sign;
	char	*res;

	i = 0;
	len = 0;
	nb = n;
	sign = 1;
	if (n == 0)
	{
		res = (char *)malloc(sizeof(char) * 2);
		res[0] = 0 + 48;
		len++;
	}
	else
	{
		if (n < 0)
		{
			len++;
			n *= -1;
			sign *= -1;
		}
		while (nb != 0)
		{
			nb = nb / 10;
			len++;
		}
		res = (char *)malloc(len + 1);
		if (!res)
			return (NULL);
		while (n != 0)
		{
			res[len -1 - i++] = n % 10 + 48;
			n = n /10;
		}
		if (sign == -1)
			res[0] = '-';
	}
	res[len] = '\0';
	return (res);
}

// int	main(void)
// {
// 	int	nb;
// 	nb = -2147483648;
// 	printf("%s", ft_itoa(nb));
// }
