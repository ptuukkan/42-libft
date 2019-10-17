#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*s;
	char	*d;
	size_t	i;
	char	*temp;

	s = (char *)src;
	d = (char *)dest;
	i = 0;
	temp = (char *)malloc(sizeof(char) * n);
	if (temp)
	{
		while (i < n)
		{
			temp[i] = s[i];
			i++;
		}
		i = 0;
		while (i < n)
		{
			d[i] = temp[i];
			i++;
		}
	}
	free(temp);
	return (dest);
}