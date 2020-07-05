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
	size_t	s2len;
	int		i;

	i = 0;
	if ((s2 == NULL || *s2 == '\0') || (*s2 == '\0' && *s1 == '\0'))
		return ((char *)s1);
	s2len = ft_strlen(s2);
	while (s1[i] && len)
	{
		if (s1[i] == *s2)
		{
			if (len < s2len)
				return (NULL);
			if (ft_strncmp(&s1[i], s2, ft_strlen(s2)) == 0)
				return ((char *)&s1[i]);
		}
		i++;
		len--;
	}
	return (NULL);
}
