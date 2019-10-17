#include "libft.h"

char	*ft_strmap(char const *s, char(*f)(char))
{
	char	*newstr;
	int		i;

	newstr = ft_strnew(ft_strlen(s));
	if (newstr == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		newstr[i] = (*f)(s[i]);
		i++;
	}
	return (newstr);
}