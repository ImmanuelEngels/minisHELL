/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imengels <imengels@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 15:41:09 by imengels          #+#    #+#             */
/*   Updated: 2025/08/15 15:41:11 by imengels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (n == 0)
		return (dst);
	if (!dst || !src)
		return (NULL);
	s = (const unsigned char *)src;
	d = (unsigned char *)dst;
	while (n--)
		*d++ = *s++;
	return (dst);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s && (unsigned char)*s != (unsigned char)c)
		s++;
	if (*s || (char)c == '\0')
		return ((char *)s);
	return (NULL);
}

void	*ft_free_and_null(char **a, char **b)
{
	if (a && *a)
	{
		free(*a);
		*a = NULL;
	}
	if (b && *b)
	{
		free(*b);
		*b = NULL;
	}
	return (NULL);
}

char	*ft_gnl_substr(char const *s, unsigned int start, size_t len)
{
	char		*new;
	char const	*s_len;

	if (!s)
		return (NULL);
	s_len = s + ft_gnl_strlen(s);
	if ((s_len - s) < start)
		return (ft_gnl_strjoin(NULL, ""));
	if ((size_t)((s_len - s) - start) <= len)
		len = (size_t)(s_len - s) - start;
	new = (char *)malloc((len + 1) * sizeof(char));
	if (!new)
		return (NULL);
	ft_memcpy(new, s + start, len);
	*(new + len) = '\0';
	return (new);
}

char	*ft_gnl_strjoin(char *s1, char *s2)
{
	char	*new;
	size_t	len_s1;
	size_t	len_s2;

	if (!s1 && !s2)
		return (NULL);
	len_s1 = ft_gnl_strlen(s1);
	len_s2 = ft_gnl_strlen(s2);
	new = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!new)
		return (ft_free_and_null(NULL, &s1));
	ft_memcpy(new, s1, len_s1);
	ft_memcpy(new + len_s1, s2, len_s2);
	new[len_s1 + len_s2] = '\0';
	ft_free_and_null(NULL, &s1);
	return (new);
}
