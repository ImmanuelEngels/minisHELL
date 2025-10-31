/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imengels <imengels@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 16:30:35 by imengels          #+#    #+#             */
/*   Updated: 2025/05/07 16:30:37 by imengels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (n == 0)
		return (dst);
	if (!dst && !src)
		return (NULL);
	s = (const unsigned char *)src;
	d = (unsigned char *)dst;
	while (n--)
		*d++ = *s++;
	return (dst);
}
