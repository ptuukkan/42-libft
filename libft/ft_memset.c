#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	int				i;
	unsigned char	uc;
	unsigned char	*str;

	i = 0;
	uc = (unsigned char)c;
	str = (unsigned char *)s;
	while (n > 0)
	{
		str[i] = uc;
		n--;
		i++;
	}
	return (s);
}
