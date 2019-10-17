#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joinstr;

	joinstr = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (joinstr == NULL)
		return (NULL);
	joinstr = ft_strcat(joinstr, s1);
	joinstr = ft_strcat(joinstr, s2);
	return (joinstr);
}