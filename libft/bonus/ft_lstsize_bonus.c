/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imengels <imengels@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 16:29:26 by imengels          #+#    #+#             */
/*   Updated: 2025/05/07 16:29:27 by imengels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_lstsize(t_list *lst)
{
	int		size;
	t_list	*p;

	size = 0;
	p = lst;
	if (!lst)
		return (0);
	while (p)
	{
		size++;
		p = p->next;
	}
	return (size);
}
