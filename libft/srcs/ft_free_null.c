/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_null.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imengels <imengels@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 13:39:08 by imengels          #+#    #+#             */
/*   Updated: 2025/10/22 13:39:10 by imengels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_free2(void **ptr1, void **ptr2)
{
	if (ptr1 && *ptr1)
	{
		free(*ptr1);
		*ptr1 = NULL;
	}
	if (ptr2 && *ptr2)
	{
		free(*ptr2);
		*ptr2 = NULL;
	}
	return (NULL);
}

void	*ft_free(void **ptr1)
{
	if (ptr1 && *ptr1)
	{
		free(*ptr1);
		*ptr1 = NULL;
	}
	return (NULL);
}

void	*ft_close(int *fd)
{
	if (fd && *fd >= 0)
	{
		close(*fd);
		*fd = -1;
	}
	return (NULL);
}

void	*ft_free_arr(char **arr)
{
	size_t	i;

	if (arr)
	{
		i = 0;
		while (arr[i])
			ft_free((void **)&arr[i++]);
		free(arr);
	}
	return (NULL);
}

void	*ft_free_intarr(int **arr)
{
	size_t	i;

	if (arr)
	{
		i = 0;
		while (arr[i])
			ft_free((void **)&arr[i++]);
		free(arr);
	}
	return (NULL);
}
