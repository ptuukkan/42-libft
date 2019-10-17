#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int	i;

	i = 0;
	while (dst[i] != '\0')
		i++;
	while (size - i > 1 && *src != '\0')
	{
		dst[i] = *src;
		i++;
		src++;
	}
	dst[i] = '\0';
	return (ft_strlen(dst));
}