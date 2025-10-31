/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imengels <imengels@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 16:33:47 by imengels          #+#    #+#             */
/*   Updated: 2025/05/07 16:33:50 by imengels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*new;
	char const	*s_len;

	if (!s)
		return (NULL);
	s_len = s + ft_strlen(s);
	if ((s_len - s) < start)
		return (ft_calloc(1, 1));
	if ((size_t)((s_len - s) - start) <= len)
		len = (size_t)(s_len - s) - start;
	new = (char *)malloc((len + 1) * sizeof(char));
	if (!new)
		return (NULL);
	ft_memcpy(new, s + start, len);
	*(new + len) = '\0';
	return (new);
}

/*
#include <stdio.h>

int	main(void)
{
	printf("%s\n", ft_substr("hola", 0, 18446744073709551615);
	ft_substr("hola", 0, 18446744073709551615);
	ft_substr("hola", 0, 18446744073709551615);
	return (0);
}
*/
