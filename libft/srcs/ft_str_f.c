/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_f.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imengels <imengels@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 13:42:45 by imengels          #+#    #+#             */
/*   Updated: 2025/10/22 13:42:47 by imengels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

bool	ft_str_is_f(char *str, bool (*f)(int c))
{
	size_t	i;

	if (!str || !f)
		return (false);
	i = 0;
	while (str[i])
	{
		if (!(*f)((unsigned char)str[i]))
			return (false);
		i++;
	}
	return (true);
}

bool	ft_str_any_f(char *str, bool (*f)(int c))
{
	size_t	i;

	if (!str || !f)
		return (false);
	i = 0;
	while (str[i])
	{
		if (f((unsigned char)str[i]))
			return (true);
		i++;
	}
	return (false);
}

void	ft_str_convert_f(char *str, int (*f)(int c))
{
	size_t	i;

	if (!str || !f)
		return ;
	i = 0;
	while (str[i])
	{
		str[i] = f((unsigned char)str[i]);
		i++;
	}
}

size_t	ft_str_count_f(char *str, bool (*f)(int c))
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	if (!str || !f)
		return (0);
	while (str[i])
	{
		if (f((unsigned char)str[i]))
			count++;
		i++;
	}
	return (count);
}

char	*ft_str_find_f(char *str, bool (*f)(int c))
{
	size_t	i;

	if (!str || !f)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (f((unsigned char)str[i]))
			return (&str[i]);
		i++;
	}
	return (NULL);
}
