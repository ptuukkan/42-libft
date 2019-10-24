/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 11:49:26 by ptuukkan          #+#    #+#             */
/*   Updated: 2019/10/22 15:13:24 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*newstr;
	int		i;

	if (s == NULL || (*f) == NULL)
		return (NULL);
	newstr = ft_strnew(ft_strlen(s));
	if (newstr == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		newstr[i] = (*f)(s[i]);
		i++;
	}
	return (newstr);
}
