/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imengels <imengels@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 16:22:53 by imengels          #+#    #+#             */
/*   Updated: 2025/05/07 16:23:01 by imengels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;
	size_t	nb;

	if (nmemb && size)
	{
		nb = nmemb * size;
		if (nb / nmemb != size)
			return (NULL);
	}
	else
		return (malloc(0));
	p = malloc(nb);
	if (!p)
		return (NULL);
	return (ft_memset(p, 0, nb));
}
