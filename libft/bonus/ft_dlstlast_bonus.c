#include "../libft.h"

t_dlist	*ft_dlstlast(t_dlist *dlst)
{
	t_dlist	*p;

	if (!dlst)
		return (NULL);
	p = dlst;
	while (p->next)
		p = p->next;
	return (p);
}
