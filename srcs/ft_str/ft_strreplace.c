/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 11:50:42 by ptuukkan          #+#    #+#             */
/*   Updated: 2019/10/18 14:11:37 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strreplace(char *search, char *replace, char **subject)
{
	char	*tmp;
	int		n;
	char	*start;
	char	*end;

	tmp = ft_strstr(*subject, search);
	if (tmp == NULL)
		return (*subject);
	n = tmp - *subject;
	start = ft_strsub(*subject, 0, (size_t)n);
	end = ft_strsub(*subject, n + ft_strlen(search), ft_strlen(*subject));
	ft_strdel(subject);
	if (*replace == '\0')
		*subject = ft_strjoin(start, end);
	else
	{
		tmp = ft_strjoin(start, replace);
		*subject = ft_strjoin(tmp, end);
		ft_strdel(&tmp);
	}
	ft_strdel(&start);
	ft_strdel(&end);
	return (*subject);
}
