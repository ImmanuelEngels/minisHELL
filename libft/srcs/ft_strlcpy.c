/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imengels <imengels@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 19:23:38 by imengels          #+#    #+#             */
/*   Updated: 2025/05/07 15:57:26 by imengels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	const char	*s;

	s = src;
	if (size && dst)
	{
		while (--size && *s)
			*dst++ = *s++;
		*dst = '\0';
	}
	while (*s)
		s++;
	return (s - src);
}
