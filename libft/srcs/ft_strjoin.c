/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imengels <imengels@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 16:34:30 by imengels          #+#    #+#             */
/*   Updated: 2025/05/07 16:34:32 by imengels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size_new;
	size_t	size_s1;
	char	*new;

	if (!s1 && !s2)
		return (NULL);
	size_s1 = ft_strlen(s1) + 1;
	size_new = size_s1 + ft_strlen(s2);
	new = (char *)malloc(sizeof(char) * size_new);
	if (!new)
		return (NULL);
	ft_memcpy(new, s1, size_s1);
	ft_strlcat(new, s2, size_new);
	return (new);
}
