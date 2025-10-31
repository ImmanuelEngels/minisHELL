/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_limit_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imengels <imengels@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 13:47:26 by imengels          #+#    #+#             */
/*   Updated: 2025/10/22 13:47:27 by imengels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

unsigned int	ft_uintmax(void)
{
	return (~(0u));
}

unsigned long long	ft_ullmax(void)
{
	return (~(0ULL));
}

size_t	ft_stmax(void)
{
	return (~((size_t)0));
}

unsigned short	ft_ushortmax(void)
{
	return (~((unsigned short)0));
}
