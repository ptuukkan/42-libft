#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*temp;

	temp = malloc(size);
	if (temp != NULL)
	{
		temp = ft_memset(temp, 0, size);
		return (temp);
	}
	return (NULL);
}