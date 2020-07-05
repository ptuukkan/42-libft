/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 11:48:13 by ptuukkan          #+#    #+#             */
/*   Updated: 2019/10/17 11:48:15 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joinstr;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	joinstr = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (joinstr == NULL)
		return (NULL);
	joinstr = ft_strcat(joinstr, s1);
	joinstr = ft_strcat(joinstr, s2);
	return (joinstr);
}
