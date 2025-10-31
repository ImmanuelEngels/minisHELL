/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imengels <imengels@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 16:23:39 by imengels          #+#    #+#             */
/*   Updated: 2025/05/07 16:23:43 by imengels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_isalnum(int c)
{
	if ((unsigned int)c - 65 < 26)
		return (1);
	if ((unsigned int)c - 97 < 26)
		return (1);
	if ((unsigned int)c - 48 < 10)
		return (1);
	return (0);
}
