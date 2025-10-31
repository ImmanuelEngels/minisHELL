/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_checks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imengels <imengels@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 13:36:01 by imengels          #+#    #+#             */
/*   Updated: 2025/10/22 13:36:04 by imengels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

bool	ft_arr_is_of(char **arr, char *set)
{
	size_t	i;

	if (!arr || !arr[0])
		return (false);
	i = 0;
	while (arr[i])
	{
		if (!ft_str_is_of(arr[i], set))
			return (false);
		i++;
	}
	return (true);
}

size_t	ft_arr_contains(char **arr, char *set)
{
	t_utable	table;
	size_t		found;
	size_t		i;
	size_t		j;

	ft_set_utable(set, &table);
	found = 0;
	i = 0;
	while (arr[i])
	{
		j = 0;
		while (arr[i][j])
		{
			if (ft_get_utable(arr[i][j], table))
			{
				table[(unsigned char)arr[i][j]] -= 1;
				found++;
			}
			j++;
		}
		i++;
	}
	return (found);
}

bool	ft_arr_contains_exact(char **arr, char *set)
{
	t_utable	t1;
	t_utable	t2;
	size_t		i;

	i = 0;
	ft_set_utable(set, &t1);
	ft_set_utable(arr[0], &t2);
	while (arr[++i])
		ft_add_utable(arr[i], &t2);
	i = 1;
	while (i < 256)
	{
		if (t1[i] && t1[i] != t2[i])
			return (false);
		i++;
	}
	return (true);
}

void	ft_arr_get_pos(int *x, int *y, char **arr, char f)
{
	*y = 0;
	while (arr[*y])
	{
		*x = 0;
		while (arr[*y][*x])
		{
			if (arr[*y][*x] == f)
				return ;
			*x += 1;
		}
		*y += 1;
	}
	*x = -1;
	*y = -1;
}
