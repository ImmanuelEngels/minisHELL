#include "libft_list.h"

void	ft_dlstadd_after(t_dlist *dlis, t_dlist *insert)
{
	if (!dlis || !insert)	
		return ;
	insert->next = dlis->next;
	if (dlis->next)
		dlis->next->prev = insert;
	dlis->next = insert;
	insert->prev = dlis;
}
