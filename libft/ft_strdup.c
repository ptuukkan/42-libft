#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dupstr;
	int		i;

	dupstr = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	i = 0;
	if (dupstr)
	{
		while (s[i] != '\0')
		{
			dupstr[i] = s[i];
			i++;
		}
		dupstr[i] = '\0';
		return (dupstr);
	}
	else
		return (NULL);
}