/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_limit.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imengels <imengels@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 13:47:34 by imengels          #+#    #+#             */
/*   Updated: 2025/10/22 13:47:36 by imengels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_LIMIT_H
# define LIBFT_LIMIT_H

# include <stdlib.h>
# include <sys/types.h>

/**********************LIMIT*********************/
/*		ft_limit_int_ll.c		*/
int					ft_intmax(void);
int					ft_intmin(void);
long long			ft_llmax(void);
long long			ft_llmin(void);
/*______________________________________________*/

/*		ft_limit_short_sst.c		*/
ssize_t				ft_sstmax(void);
ssize_t				ft_sstmin(void);
short				ft_shortmax(void);
short				ft_shortmin(void);
/*______________________________________________*/

/*		ft_limit_unsigned.c		*/
size_t				ft_stmax(void);
unsigned int		ft_uintmax(void);
unsigned short		ft_ushortmax(void);
unsigned long long	ft_ullmax(void);
/*______________________________________________*/
/************************************************/
#endif
