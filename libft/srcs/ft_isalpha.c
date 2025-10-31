/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imengels <imengels@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 16:23:21 by imengels          #+#    #+#             */
/*   Updated: 2025/05/07 16:23:27 by imengels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_isalpha(int c)
{
	if ((unsigned int)c - 65 < 26)
		return (1);
	if ((unsigned int)c - 97 < 26)
		return (1);
	return (0);
}
