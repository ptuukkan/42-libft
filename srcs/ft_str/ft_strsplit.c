/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 12:21:48 by ptuukkan          #+#    #+#             */
/*   Updated: 2019/10/23 11:51:26 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordcount(char const *s, char c)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		while (s[i] != c && s[i] != '\0')
			i++;
		if (s[i - 1] != c)
			n++;
	}
	return (n);
}

static int	split_string(char ***tab, char const *s, char c)
{
	unsigned int	start;
	size_t			len;
	int				i;

	start = 0;
	i = 0;
	while (s[start] != '\0')
	{
		len = 0;
		while (s[start] != c && s[start] != '\0')
		{
			start++;
			len++;
		}
		if (len > 0)
		{
			if (!(tab[0][i] = ft_strsub(s, start - len, len)))
				return (1);
			i++;
		}
		if (s[start] != '\0')
			start++;
	}
	tab[0][i] = 0;
	return (0);
}

char		**ft_strsplit(char const *s, char c)
{
	char			**tab;

	if (s == NULL)
		return (NULL);
	tab = (char **)ft_memalloc(sizeof(char *) * ft_wordcount(s, c) + 1);
	if (tab == NULL)
		return (NULL);
	if (split_string(&tab, s, c) == 0)
		return (tab);
	return (NULL);
}
