/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 11:51:28 by ptuukkan          #+#    #+#             */
/*   Updated: 2019/10/22 15:19:23 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		str[i] = ft_toupper(str[i]);
		i++;
		while (str[i] != '\0' && ft_isalnum(str[i]) == 1)
		{
			str[i] = ft_tolower(str[i]);
			i++;
		}
		while (str[i] != '\0' && ft_isalnum(str[i]) == 0)
			i++;
	}
}
