#include "libft.h"

int	ft_isprint(int c)
{
	if (c == 32)
		return (64);
	if (c >= 33 && c <= 47)
		return (16);
	if (c >= 48 && c <= 57)
		return (4);
	if (c >= 58 && c <= 64)
		return (16);
	if (c >= 65 && c <= 90)
		return (1);
	if (c >= 91 && c <= 96)
		return (16);
	if (c >= 97 && c <= 122)
		return (2);
	if (c >= 123 && c <= 126)
		return (16);
	return (0);
}