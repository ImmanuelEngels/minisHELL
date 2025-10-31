#include "../libft.h"

void	ft_dlstdelone(t_dlist *dlst, void (*del)(void *))
{
	if (!dlst || !del)
		return ;
	del(dlst->content);
	free(dlst);
	dlst = NULL;
}
