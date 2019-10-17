#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char			*trimstr;
	unsigned int	start;
	size_t			end;

	start = 0;
	end = (ft_strlen(s) - 1);
	while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
		start++;
	while (s[end] == ' ' || s[end] == '\n' || s[end] == '\t')
		end--;
	trimstr = ft_strsub(s, start, end - start + 1);
	if (trimstr == NULL)
		return (NULL);
	return (trimstr); 
} 