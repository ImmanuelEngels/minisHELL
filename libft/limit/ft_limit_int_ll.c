/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_limit_int_ll.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imengels <imengels@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 13:47:07 by imengels          #+#    #+#             */
/*   Updated: 2025/10/22 13:47:09 by imengels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_intmax(void)
{
	return (~(1 << ((sizeof(int) * 8) - 1)));
}

int	ft_intmin(void)
{
	return (1 << ((sizeof(int) * 8) - 1));
}

long long	ft_llmax(void)
{
	return (~(1LL << ((sizeof(long long) * 8) - 1)));
}

long long	ft_llmin(void)
{
	return (1LL << ((sizeof(long long) * 8) - 1));
}
