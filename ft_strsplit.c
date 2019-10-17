/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 12:21:48 by ptuukkan          #+#    #+#             */
/*   Updated: 2019/10/17 15:02:57 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordcount(char const *s, char c)
{
	int	i;
	int	n;

	i = 0;
	n = 1;
	while (s[i] != '\0')
	{
		if (s[i] == c && (s[i + 1] != c && s[i + 1] != '\0'))
			n++;
		i++;
	}
	return (n);
}

char		**ft_strsplit(char const *s, char c)
{
	char			**tab;
	unsigned int	start;
	size_t			len;
	int				i;

	tab = (char **)ft_memalloc(sizeof(char *) * ft_wordcount(s, c) + 1);
	if (tab == NULL)
		return (NULL);
	start = 0;
	i = 0;
	while (s[start] != '\0')
	{
		len = 0;
		while (s[start] != c && s[start] != '\0')
		{
			len++;
			start++;
		}
		if (len > 0)
			tab[i++] = ft_strsub(s, start - len, len);
		start++;
	}
	tab[i] = 0;
	return (tab);
}
