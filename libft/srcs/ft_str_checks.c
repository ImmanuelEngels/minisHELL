/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_checks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imengels <imengels@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 13:43:03 by imengels          #+#    #+#             */
/*   Updated: 2025/10/22 13:43:04 by imengels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

bool	ft_str_is_of(char *str, char *set)
{
	size_t	i;
	t_table	table;

	ft_set_table(set, &table);
	i = 0;
	while (str[i])
	{
		if (!ft_is_table(str[i], table))
			return (false);
		i++;
	}
	return (true);
}

size_t	ft_str_contains(char *str, char *set)
{
	t_utable	table;
	size_t		i;
	size_t		found;

	ft_set_utable(set, &table);
	found = 0;
	i = 0;
	while (str[i])
	{
		if (ft_get_utable(str[i], table))
		{
			table[(unsigned char)str[i]] -= 1;
			found++;
		}
		i++;
	}
	return (found);
}

bool	ft_str_contains_exact(char *str, char *set)
{
	t_utable	t1;
	t_utable	t2;
	size_t		i;

	if (!str || !set)
		return (false);
	ft_set_utable(set, &t1);
	ft_set_utable(str, &t2);
	i = 1;
	while (i < 256)
	{
		if (t1[i] && t1[i] != t2[i])
			return (false);
		i++;
	}
	return (true);
}
