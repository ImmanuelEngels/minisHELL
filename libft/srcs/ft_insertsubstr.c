#include "../libft.h"

char	*ft_insertsubstr(char *src, char *insert, size_t i_len, size_t pos)
{
	size_t	n_len;
	char	*n_str;

	if (!src || !insert)
		return NULL;
	if (pos > ft_strlen(src))
		return NULL;
	n_len = ft_strlen(src) + i_len;
	n_str = malloc(sizeof(char) * (n_len + 1));
	if (!n_str)
		return NULL;
	ft_memmove(n_str, src, pos);
	ft_memmove(n_str + pos, insert, i_len);
	ft_memmove(n_str + pos + i_len, src + pos, ft_strlen(src + pos) + 1);
	return (n_str);
}

