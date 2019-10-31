/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 11:50:34 by ptuukkan          #+#    #+#             */
/*   Updated: 2019/10/18 16:00:29 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	if ((s2 == NULL || *s2 == '\0') || (*s2 == '\0' && *s1 == '\0'))
		return ((char *)s1);
	while (*s1 && len)
	{
		if (*s1 == *s2)
		{
			if (ft_strncmp(s1, s2, len) == 0)
				return ((char *)s1);
		}
		s1++;
		len--;
	}
	return (NULL);
}
