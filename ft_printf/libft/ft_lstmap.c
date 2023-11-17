/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelisaro <eelisaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 13:50:57 by eelisaro          #+#    #+#             */
/*   Updated: 2022/12/11 16:11:53 by eelisaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*cpylist;
	t_list	*listelement;

	if (!lst || !f || !del)
		return (NULL);
	cpylist = ft_lstnew(f(lst->content));
	if (!cpylist)
	{
		ft_lstclear(&lst, del);
		return (NULL);
	}
	lst = lst->next;
	while (lst)
	{
		listelement = ft_lstnew(f(lst->content));
		if (!listelement)
		{
			ft_lstclear(&cpylist, del);
			ft_lstclear(&lst, del);
			return (NULL);
		}
		ft_lstadd_back(&cpylist, listelement);
		lst = lst->next;
	}
	return (cpylist);
}
