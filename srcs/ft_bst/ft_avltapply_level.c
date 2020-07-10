/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avltapply_level.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 11:52:25 by ptuukkan          #+#    #+#             */
/*   Updated: 2020/07/07 09:36:10 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	apply_level(t_avltree *root, int level, int *first,
						void (*applyf)(t_avltree *, int))
{
	if (!root || level < 0)
		return ;
	if (level == 0)
	{
		applyf(root, *first);
		if (*first)
			*first = 0;
	}
	apply_level(root->left, level - 1, first, applyf);
	apply_level(root->right, level - 1, first, applyf);
}

void		ft_avltapply_level(t_avltree *root,
								void (*applyf)(t_avltree *, int))
{
	int	level;
	int	first;

	level = 0;
	while (level < root->height)
	{
		first = 1;
		apply_level(root, level, &first, applyf);
		level++;
	}
}
