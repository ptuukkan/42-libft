/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 11:51:08 by ptuukkan          #+#    #+#             */
/*   Updated: 2019/10/23 12:24:40 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char			*trimstr;
	unsigned int	start;
	size_t			end;

	if (s == NULL)
		return (NULL);
	start = 0;
	end = (ft_strlen(s) - 1);
	while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
		start++;
	while ((end >= 1) && (s[end] == ' ' || s[end] == '\n' || s[end] == '\t'))
		end--;
	if (end < start)
		return (ft_strnew(0));
	trimstr = ft_strsub(s, start, end - start + 1);
	if (trimstr == NULL)
		return (NULL);
	return (trimstr);
}
