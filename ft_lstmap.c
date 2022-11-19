/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:28:53 by ale-cont          #+#    #+#             */
/*   Updated: 2022/11/19 02:15:18 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*lstnew;

	lstnew = (void *)0;
	if (!lst)
		return (lstnew);
	while (lst->next != NULL)
	{
		new = ft_lstnew(f(lst->content));
		if (!new)
		{
			ft_lstclear(&lstnew, del);
			return ((void *)0);
		}
		ft_lstadd_back(&new, lstnew);
		lst = lst->next;
	}
	return (lstnew);
}
#include <stdio.h>


void	*f(void *first_char)
{
	((char *)first_char)[0] = 'W';
	return (first_char);
}

void	del(void *content)
{
	printf("delete this - %s", content);
}


int	main()
{
	t_list	*elem1;
	t_list	*elem2;
	t_list	*elem3;
	t_list	*elem4;
	t_list	*elem5;
	t_list	*list;

	char	str1[] = "content1";
	char	str2[] = "content2";
	char	str3[] = "content3";
	char	str4[] = "content4";
	char	str5[] = "content5";
	elem1 = ft_lstnew(str1);
	elem2 = ft_lstnew(str2);
	elem3 = ft_lstnew(str3);
	elem4 = ft_lstnew(str4);
	elem5 = ft_lstnew(str5);
	elem1->next = elem2;
	elem2->next = elem3;
	elem3->next = elem4;
	elem4->next = elem5;
	elem5->next = NULL;
	list = ft_lstmap(elem2, f, del);
	while (list != NULL)
	{
		printf("%s\n", list->content);
		list = list->next;
	}
}