/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imengels <imengels@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 15:41:16 by imengels          #+#    #+#             */
/*   Updated: 2025/08/15 15:42:29 by imengels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>

/*	ft_get_next_line_utils.c	*/
void	*ft_free_and_null(char **a, char **b);
char	*ft_strchr(const char *s, int c);
char	*ft_gnl_strjoin(char *input, char *buffer);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_gnl_substr(char const *s, unsigned int start, size_t len);

/*	ft_get_next_line.c	*/
size_t	ft_gnl_strlen(const char *str);
char	*get_next_line(int fd);
char	*ft_get_input(int fd, char *input);
char	*ft_get_line(char *input);
char	*ft_remaining_input(char *input);
#endif
