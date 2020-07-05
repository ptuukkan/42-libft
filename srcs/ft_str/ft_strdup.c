/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 11:47:15 by ptuukkan          #+#    #+#             */
/*   Updated: 2019/10/23 12:43:17 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dupstr;
	int		i;

	dupstr = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
	i = 0;
	if (dupstr)
	{
		while (s1[i] != '\0')
		{
			dupstr[i] = s1[i];
			i++;
		}
		dupstr[i] = '\0';
		return (dupstr);
	}
	else
		return (NULL);
}
