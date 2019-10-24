/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 11:50:50 by ptuukkan          #+#    #+#             */
/*   Updated: 2019/10/18 16:00:07 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int	h;
	int	n;

	h = 0;
	n = 0;
	if (needle == NULL || (*needle == '\0' && *haystack == '\0'))
		return ((char *)haystack);
	while (haystack[h] != '\0')
	{
		while (haystack[h] == needle[n] &&
				haystack[h] != '\0' && needle[n] != '\0')
		{
			h++;
			n++;
		}
		if (needle[n] == '\0')
			return ((char *)haystack + (h - n));
		h = h - n + 1;
		n = 0;
	}
	return (NULL);
}
