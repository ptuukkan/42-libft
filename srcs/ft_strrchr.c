#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	cc;
	int		i;

	cc = (char)c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == cc)
		{
			s = s + 1;
			i = 0;
		}
		i++;
	}
	if (*s == cc)
		return (s);
	else
		return (NULL);
}