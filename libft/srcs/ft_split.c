/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imengels <imengels@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 16:32:44 by imengels          #+#    #+#             */
/*   Updated: 2025/05/07 16:32:46 by imengels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static size_t	ft_count_words(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

static const char	*ft_strchr_if(char const *s, unsigned char c, bool b)
{
	while (*s)
	{
		if (*s == c && !b)
			return (s);
		else if (*s != c && b)
			return (s);
		s++;
	}
	return (s);
}

char	**ft_split(char const *s, char c)
{
	char		**arr;
	char const	*end;
	char		**temp;

	if (!s)
		return (NULL);
	arr = (char **)malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!arr)
		return (NULL);
	temp = arr;
	while (*s)
	{
		s = ft_strchr_if(s, c, 1);
		if (!*s)
			break ;
		end = ft_strchr_if(s, c, 0);
		*arr = ft_substr(s, 0, end - s);
		if (!*arr)
			return (ft_free_arr(temp));
		s = end;
		arr++;
	}
	*arr = NULL;
	return (temp);
}
