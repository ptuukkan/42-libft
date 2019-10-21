#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*temp;
	t_list	*newlst;
	t_list	*newlsthead;

	newlst = (*f)(lst);
	if (newlst == NULL)
		return (NULL);
	newlsthead = newlst;
	lst = lst->next;
	while (lst != NULL)
	{
		newlst->next = (*f)(lst);
		if (newlst->next == NULL)
			return (NULL);
		newlst = newlst->next;
		lst = lst->next;
	}
	return(newlsthead);
}
