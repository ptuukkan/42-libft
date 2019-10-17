#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int	h;
	int	n;

	h = 0;
	n = 0;
	if (!needle)
		return (haystack);
	while (haystack[h] != '\0')
	{
		while (haystack[h] == needle[n] && haystack[h] != '\0' && needle[n] != '\0')
		{
			h++;
			n++;
		}
		if (needle[n] == '\0')
			return (haystack + (h - n));
		h++;
	}
	return (NULL);
}