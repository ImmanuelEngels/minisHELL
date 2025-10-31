/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imengels <imengels@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 19:23:38 by imengels          #+#    #+#             */
/*   Updated: 2025/05/07 15:52:01 by imengels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s && (unsigned char)*s != (unsigned char)c)
		s++;
	if (*s || (char)c == '\0')
		return ((char *)s);
	return (NULL);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	*str;
	char	*p1;
	char	*p2;

	str = ft_strdup("teste");
	p1 = strchr(str, 'e' + 256);
	p2 = ft_strchr(str, 'e' + 256);
	if (p1 == p2)
		printf("ok\n");
	else
		printf("nope\n");
	free(str);
	return (0);
}
*/
