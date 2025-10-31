/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_f.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imengels <imengels@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 13:24:07 by imengels          #+#    #+#             */
/*   Updated: 2025/10/22 13:24:07 by imengels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

bool	ft_arr_is_f(char **arr, bool (*f)(int c))
{
	size_t	i;

	if (!arr || !arr[0] || !f)
		return (false);
	i = 0;
	while (arr[i])
	{
		if (!ft_str_is_f(arr[i], f))
			return (false);
		i++;
	}
	return (true);
}

bool	ft_arr_any_f(char **arr, bool (*f)(int c))
{
	size_t	i;

	if (!arr || !arr[0] || !f)
		return (false);
	i = 0;
	while (arr[i])
	{
		if (ft_str_any_f(arr[i], f))
			return (true);
		i++;
	}
	return (false);
}

void	ft_arr_convert_f(char **arr, int (*f)(int c))
{
	size_t	i;

	if (!arr || !arr[0] || !f)
		return ;
	i = 0;
	while (arr[i])
	{
		ft_str_convert_f(arr[i], f);
		i++;
	}
}

size_t	ft_arr_count_f(char **arr, bool (*f)(int c))
{
	size_t	i;
	size_t	count;

	if (!arr || !arr[0] || !f)
		return (0);
	i = 0;
	count = 0;
	while (arr[i])
	{
		count += ft_str_count_f(arr[i], f);
		i++;
	}
	return (count);
}

char	*ft_arr_find_f(char **arr, bool (*f)(int c))
{
	size_t	i;
	char	*found;

	if (!arr || !arr[0] || !f)
		return (NULL);
	i = 0;
	while (arr[i])
	{
		found = ft_str_find_f(arr[i], f);
		if (found)
			return (found);
		i++;
	}
	return (NULL);
}
