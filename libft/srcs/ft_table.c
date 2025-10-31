/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_table.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imengels <imengels@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 13:15:02 by imengels          #+#    #+#             */
/*   Updated: 2025/10/22 13:15:03 by imengels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

bool	ft_is_table(int c, t_table table)
{
	return (table[(unsigned char)c]);
}

unsigned int	ft_get_utable(int c, t_utable table)
{
	return (table[(unsigned char)c]);
}

void	ft_set_table(const char *set, t_table *table)
{
	ft_memset(*table, 0, 256 * sizeof(bool));
	while (*set)
		(*table)[(unsigned char)*set++] = true;
}

void	ft_set_utable(const char *set, t_utable *table)
{
	ft_memset(*table, 0, 256 * sizeof(unsigned int));
	while (*set)
		(*table)[(unsigned char)*set++] += 1;
}

void	ft_add_utable(const char *set, t_utable *table)
{
	while (*set)
		(*table)[(unsigned char)*set++] += 1;
}
