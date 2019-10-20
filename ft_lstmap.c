#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*temp;
	t_list	*newlst;
	t_list	*newlsthead;

	temp = (*f)(lst);
	newlst = NULL;
	newlst = ft_lstnew(newlst->content, newlst->content_size);
	if (newlst == NULL)
		return (NULL);
	newlsthead = newlst;
	lst = lst->next;
	while (lst != NULL)
	{
		temp = (*f)(lst);
		newlst->next = ft_lstnew(newlst->content, newlst->content_size);
		if (newlst->next == NULL)
			return (NULL);
		newlst = newlst->next;
		lst = lst->next;
	}
	return(newlsthead);
}
