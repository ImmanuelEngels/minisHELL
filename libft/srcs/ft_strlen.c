/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imengels <imengels@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 19:23:38 by imengels          #+#    #+#             */
/*   Updated: 2025/10/22 13:28:02 by imengels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlen(const char *str)
{
	const char	*s;

	s = str;
	while (*s)
		s++;
	return (s - str);
}

/*
#include <stdio.h>

int	main(int ac, char **av)
{
	printf("len: %li\tstring: :%s:\n", ft_strlen(av[ac - 1]), av[ac - 1]);
	return (0);
}
*/
