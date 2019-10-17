#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*substr;

	if (start > ft_strlen(s))
		return (NULL);
	substr = ft_strnew(len);
	if (substr == NULL)
		return (NULL);
	substr = ft_strncpy(substr, s + start, len);
	return (substr);
}