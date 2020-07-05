/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrimchr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 11:51:08 by ptuukkan          #+#    #+#             */
/*   Updated: 2019/10/23 12:24:40 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrimchr(char const *s, char c, char mode)
{
	int		start;
	int		end;

	if (s == NULL)
		return (NULL);
	start = 0;
	end = (int)ft_strlen(s) - 1;
	if (mode == 1 || mode == 3)
	{
		while (s[end] == c)
			end--;
	}
	if (mode == 2 || mode == 3)
	{
		while (s[start] == c)
			start++;
	}
	if (start > end)
		return (ft_strnew(0));
	end = end + 1 - start;
	return (ft_strsub(s, start, end));
}
