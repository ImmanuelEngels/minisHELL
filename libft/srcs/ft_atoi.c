/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imengels <imengels@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 16:22:17 by imengels          #+#    #+#             */
/*   Updated: 2025/05/07 16:22:23 by imengels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_atoi(const char *str)
{
	int	sign;
	int	nb;

	nb = 0;
	while (*str == 32 || ((unsigned char)(*str - 9) < 5))
		str++;
	if (*str == '-')
	{
		str++;
		sign = -1;
	}
	else
	{
		if (*str == '+')
			str++;
		sign = 1;
	}
	while (((unsigned char)(*str - 48) < 10))
		nb = ((nb << 3) + (nb << 1)) + (*str++ - '0');
	return (sign * nb);
}

/*
#include <stdio.h>

int	main(void)
{
	printf("%d\n", ft_atoi("\001 2"));
	printf("%d\n", ft_atoi("\002 3")); // av
	printf("%d\n", ft_atoi("\003 4")); // av
	printf("%d\n", ft_atoi("\004 5")); // av
	printf("%d\n", ft_atoi("\005 6")); // av
	printf("%d\n", ft_atoi("\006 7")); // av
	printf("%d\n", ft_atoi("\007 8")); // av
	printf("%d\n", ft_atoi("\008 9")); // av
	printf("%d\n", ft_atoi("\009 10")); // av
	return (0);
}
*/
