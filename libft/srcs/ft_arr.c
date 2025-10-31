/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imengels <imengels@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 13:23:36 by imengels          #+#    #+#             */
/*   Updated: 2025/10/22 13:26:31 by imengels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putarr_fd(char **arr, int fd)
{
	size_t	i;

	if (!arr)
	{
		ft_putstr_fd("No Array\n", fd);
		return ;
	}
	i = 0;
	while (arr[i])
	{
		ft_putstr_fd(arr[i], fd);
		ft_putchar_fd('\n', fd);
		i++;
	}
}

size_t	ft_arrlen(char **arr)
{
	size_t	i;

	if (!arr)
		return (0);
	i = 0;
	while (arr[i])
		i++;
	return (i);
}

char	**ft_arrdup(char **arr)
{
	size_t	size;
	size_t	i;
	char	**n_arr;

	if (!arr)
		return (NULL);
	size = ft_arrlen(arr);
	n_arr = malloc(sizeof(char *) * (size + 1));
	if (!n_arr)
		return (NULL);
	i = 0;
	while (i < size)
	{
		n_arr[i] = ft_strdup(arr[i]);
		if (!n_arr[i])
			return (ft_free_arr(n_arr));
		i++;
	}
	n_arr[size] = NULL;
	return (n_arr);
}

void	ft_arrcpy(char **dest, char **src)
{
	size_t	i;

	if (!dest || !src)
		return ;
	i = 0;
	while (src[i])
	{
		ft_strlcpy(dest[i], src[i], ft_strlen(src[i]));
		i++;
	}
	dest[i] = NULL;
}

char	**ft_append_arr(char **arr, char *str)
{
	char	**new_arr;
	size_t	n;
	size_t	i;

	if (!arr || !str)
		return (NULL);
	n = ft_arrlen(arr);
	new_arr = malloc(sizeof(char *) * (n + 2));
	if (!new_arr)
		return (NULL);
	new_arr[n + 1] = NULL;
	new_arr[n] = ft_strdup(str);
	if (!new_arr[n])
	{
		free(new_arr);
		return (ft_free_arr(arr));
	}
	i = 0;
	while (i < n)
	{
		new_arr[i] = arr[i];
		i++;
	}
	free(arr);
	return (new_arr);
}
