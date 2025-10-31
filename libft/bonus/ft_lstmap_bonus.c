/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imengels <imengels@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 16:28:57 by imengels          #+#    #+#             */
/*   Updated: 2025/05/07 16:28:59 by imengels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*n_lst;
	t_list	*new;
	void	*temp;

	if (!lst || !del || !f)
		return (NULL);
	n_lst = NULL;
	while (lst)
	{
		temp = f(lst->content);
		new = ft_lstnew(temp);
		if (!new)
		{
			del(temp);
			if (n_lst)
				ft_lstclear(&n_lst, del);
			break ;
		}
		ft_lstadd_back(&n_lst, new);
		lst = lst->next;
	}
	return (n_lst);
}
