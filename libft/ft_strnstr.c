#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	int	h;
	int	n;

	h = 0;
	n = 0;
	if (!s2)
		return (s1);
	while (s1[h] != '\0' && len > 0)
	{
		while (s1[h] == s2[n] && s1[h] != '\0' && s2[n] != '\0' && len > 0)
		{
			h++;
			n++;
			len--;
		}
		if (s2[n] == '\0')
			return (s1 + (h - n));
		h++;
		len--;
	}
	return (NULL);
}