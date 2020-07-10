/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avltrotate_left.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 11:52:25 by ptuukkan          #+#    #+#             */
/*   Updated: 2020/07/07 09:36:10 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_avltree	*ft_avltrotate_left(t_avltree *node)
{
	t_avltree	*newroot;
	t_avltree	*rightleft;

	newroot = node->right;
	rightleft = node->right->left;
	newroot->left = node;
	node->right = rightleft;
	node->height = 1 + ft_max(ft_avltheight(node->left),
								ft_avltheight(node->right));
	newroot->height = 1 + ft_max(ft_avltheight(newroot->left),
								ft_avltheight(newroot->right));
	return (newroot);
}
