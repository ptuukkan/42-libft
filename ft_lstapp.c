#include "libft.h"

void	ft_lstapp(t_list **alst, t_list  *new)
{
	t_list	*temp;

	if (new == NULL)
		return;
	if (*alst == NULL)
	{
		*alst = new;
		return;
	}
	temp = *alst;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new;
}
