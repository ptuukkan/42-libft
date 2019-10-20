#include "libft.h"

void	ft_lstadd(t_list **alst, t_list  *new)
{
	if (new == NULL)
		return;
	if (*alst == NULL)
		*alst = new;
	else
	{
		new->next = *alst;
		*alst = new;
	}
}
