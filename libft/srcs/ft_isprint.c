/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imengels <imengels@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 19:09:40 by imengels          #+#    #+#             */
/*   Updated: 2025/05/07 15:24:31 by imengels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_isprint(int c)
{
	if ((unsigned int)c - 32 < 95)
		return (1);
	return (0);
}

/*
int	main(void)
{
	printf("my\t%i\n", ft_isprint('A'));
	printf("my\t%i\n", isprint('A'));
	return (0);
}
*/
