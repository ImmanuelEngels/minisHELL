/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imengels <imengels@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 19:23:38 by imengels          #+#    #+#             */
/*   Updated: 2025/05/07 15:57:38 by imengels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*d;
	char		*d_len;
	const char	*s;
	const char	*s_len;

	d_len = dst + ft_strlen(dst);
	s_len = src + ft_strlen(src);
	if (((size_t)(d_len - dst)) >= size)
		return ((s_len - src) + size);
	s = src;
	d = d_len;
	size -= d_len - dst;
	if (size)
	{
		while (--size && *s)
			*d++ = *s++;
		*d = '\0';
	}
	return ((d_len - dst) + (s_len - src));
}
