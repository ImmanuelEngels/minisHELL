#include "../libft.h"

int	ft_isspace(int n)
{
	unsigned char c;

	c = n;
	return (c == ' ' || (c >= '\t' && c <= '\r'));
}
