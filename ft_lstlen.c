#include "libft.h"

size_t	ft_lstlen(t_list *lst)
{
	size_t	len;

	len = lst->content_size;
	lst = lst->next;
	while (lst)
	{
		len = len + lst->content_size;
		lst = lst->next;
	}
	return (len);
}
