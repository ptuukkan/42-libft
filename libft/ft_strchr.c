#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	cc;

	cc = (char)c;
	while (*s != '\0' && *s != cc)
		s++;
	if (*s == cc)
		return ((char *)s);
	else
		return (NULL);
}