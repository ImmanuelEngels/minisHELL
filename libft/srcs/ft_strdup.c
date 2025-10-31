/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imengels <imengels@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 16:33:16 by imengels          #+#    #+#             */
/*   Updated: 2025/05/07 16:33:18 by imengels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strdup(const char *s)
{
	char	*new;
	size_t	size;

	size = ft_strlen(s) + 1;
	new = (char *)malloc(sizeof(char) * size);
	if (!new)
		return (NULL);
	ft_memcpy(new, s, size);
	return (new);
}
