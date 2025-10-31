/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imengels <imengels@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 15:41:14 by imengels          #+#    #+#             */
/*   Updated: 2025/08/15 15:41:14 by imengels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_gnl_strlen(const char *str)
{
	const char	*s;

	s = str;
	if (!str)
		return (0);
	while (*s)
		s++;
	return (s - str);
}

char	*ft_get_input(int fd, char *input)
{
	char	*buffer;
	int		r;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	r = 42;
	if (!buffer)
		return (ft_free_and_null(NULL, &input));
	while (!ft_strchr(input, '\n') && r > 0)
	{
		r = read(fd, buffer, BUFFER_SIZE);
		if (r < 0)
			return (ft_free_and_null(&input, &buffer));
		buffer[r] = '\0';
		if (!buffer[0])
			break ;
		input = ft_gnl_strjoin(input, buffer);
		if (!input)
			return (ft_free_and_null(NULL, &buffer));
	}
	if (input && !*input)
		return (ft_free_and_null(&input, &buffer));
	ft_free_and_null(NULL, &buffer);
	return (input);
}

char	*ft_get_line(char *input)
{
	char	*new;

	new = ft_strchr(input, '\n');
	if (new)
		return (ft_gnl_substr(input, 0, new - input + 1));
	return (ft_gnl_substr(input, 0, ft_gnl_strlen(input)));
}

char	*ft_remaining_input(char *input)
{
	char	*new;
	char	*rest;
	size_t	len;

	len = ft_gnl_strlen(input);
	new = ft_strchr(input, '\n');
	if (!new)
		return (ft_free_and_null(NULL, &input));
	rest = ft_gnl_substr(input, new - input + 1, len - (new - input + 1));
	ft_free_and_null(NULL, &input);
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*input;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	input = ft_get_input(fd, input);
	if (!input)
		return (NULL);
	line = ft_get_line(input);
	if (!line)
		return (ft_free_and_null(&input, NULL));
	input = ft_remaining_input(input);
	return (line);
}
