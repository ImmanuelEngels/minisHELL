#include "../libft.h"

void	ft_dlstadd_back(t_dlist **dlst, t_dlist *new)
{
	t_dlist	*p;

	if (!new || !dlst)
		return ;
	if (!*dlst)
	{
		*dlst = new;
		return ;
	}
	p = ft_dlstlast(*dlst);
	p->next = new;
	new->prev = p;
}
