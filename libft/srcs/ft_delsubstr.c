#include "../libft.h"

char	*ft_delsubstr(char *src, char *del, size_t d_len, size_t pos)
{
	size_t	n_len;
	char	*n_str;

	if (!src || !del)
		return (NULL);
	if (pos > ft_strlen(src))
		return (NULL);
	if (ft_strncmp(&src[pos], del, d_len) != 0)
		return (NULL);
	n_len = ft_strlen(src) - d_len;
	n_str = malloc(sizeof(char) * (n_len + 1));
	if (!n_str)
		return (NULL);
	ft_memmove(n_str, src, pos);
	ft_memmove(n_str + pos, src + pos + d_len, ft_strlen(src + pos + d_len) + 1);
	return (n_str);
}
