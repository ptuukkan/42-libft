#include "libft.h"

void	*ft_lstfold(t_list *lst, void *(*f)(const void *, const void *))
{
	void	*result;

	if (lst == NULL)
		return (NULL);
	result = lst->content;
	lst = lst->next;
	while (lst != NULL)
	{
		result = (*f)(result, lst->content);
		lst = lst->next;
	}
	return (result);
}
