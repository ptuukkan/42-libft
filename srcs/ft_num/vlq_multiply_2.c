/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vlq_multiply_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 15:04:38 by ptuukkan          #+#    #+#             */
/*   Updated: 2019/10/22 15:00:51 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	vlq_multiply_2(char **nb, int times)
{
	char	*result;
	char	*dup;

	result = NULL;
	dup = NULL;
	while (times > 0)
	{
		if (!(dup = ft_strdup(*nb)))
			return ;
		if (!(result = vlq_sum(*nb, dup)))
			return ;
		ft_strdel(&dup);
		ft_strdel(nb);
		*nb = result;
		times--;
	}
}
