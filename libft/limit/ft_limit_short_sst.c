/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_limit_short_sst.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imengels <imengels@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 13:47:16 by imengels          #+#    #+#             */
/*   Updated: 2025/10/22 13:47:18 by imengels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

ssize_t	ft_sstmax(void)
{
	return (~((ssize_t)1 << ((sizeof(ssize_t) * 8) - 1)));
}

ssize_t	ft_sstmin(void)
{
	return ((ssize_t)1 << ((sizeof(ssize_t) * 8) - 1));
}

short	ft_shortmax(void)
{
	return (~((short)(1 << ((sizeof(short) * 8) - 1))));
}

short	ft_shortmin(void)
{
	return ((short)(1 << ((sizeof(short) * 8) - 1)));
}
