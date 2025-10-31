/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imengels <imengels@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 16:28:00 by imengels          #+#    #+#             */
/*   Updated: 2025/05/07 16:28:03 by imengels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

bool	ft_lstiter_str(t_list *lst, int (*f)(char *))
{
	if (!lst || !f)
		return (false);
	while (lst)
	{
		if (!f((char *)lst->content))
			return (false);
		lst = lst->next;
	}
	return (true);
}
