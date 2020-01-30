/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 11:48:13 by ptuukkan          #+#    #+#             */
/*   Updated: 2019/10/17 11:48:15 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoin(int n, ...)
{
	va_list	ap;
	char	*result;
	char	*tmp;
	char	*tmp2;

	if (n < 2)
		return (NULL);
	va_start(ap, n);
	result = ft_strdup(va_arg(ap, char *));
	while (n > 1)
	{
		tmp = va_arg(ap, char *);
		tmp2 = ft_strjoin(result, tmp);
		ft_strdel(&result);
		result = tmp2;
		n--;
	}
	va_end(ap);
	return (result);
}
