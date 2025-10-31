/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imengels <imengels@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 16:27:02 by imengels          #+#    #+#             */
/*   Updated: 2025/05/07 16:27:04 by imengels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*p1;
	t_list	*p2;

	if (!lst || !del)
		return ;
	p1 = *lst;
	while (p1)
	{
		p2 = p1;
		p1 = p1->next;
		ft_lstdelone(p2, del);
	}
	*lst = NULL;
}
