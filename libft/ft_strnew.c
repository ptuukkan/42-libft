#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*temp;

	temp = (char *)malloc(size + 1);
	if (temp != NULL)
	{
		ft_bzero(temp, size + 1);
		return (temp);
	}
	return (NULL);
}