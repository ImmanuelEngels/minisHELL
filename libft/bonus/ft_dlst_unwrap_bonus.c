#include "../libft.h"

t_dlist	*ft_dlst_unwrap(t_dlist **head, t_dlist *node)
{
	if (!head || !*head || !node)
		return (NULL);
	if (node->prev)
		node->prev->next = node->next;
	else
		*head = node->next;
	if (node->next)
		node->next->prev = node->prev;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}
