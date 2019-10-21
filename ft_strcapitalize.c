/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 11:51:28 by ptuukkan          #+#    #+#             */
/*   Updated: 2019/10/17 11:51:29 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strcapitalize(char *str)
{	
	int	i;
	i = 1;

	str[0] = ft_toupper(str[0]);
	while (str[i] != '\0')
	{

		str[i] = ft_tolower(str[i]);
		i++;
	}
}
