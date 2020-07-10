/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avltrotate_right.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 11:52:25 by ptuukkan          #+#    #+#             */
/*   Updated: 2020/07/07 09:36:10 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_avltree	*ft_avltrotate_right(t_avltree *node)
{
	t_avltree	*newroot;
	t_avltree	*leftright;

	newroot = node->left;
	leftright = node->left->right;
	newroot->right = node;
	node->left = leftright;
	node->height = 1 + ft_max(ft_avltheight(node->left),
								ft_avltheight(node->right));
	newroot->height = 1 + ft_max(ft_avltheight(newroot->left),
								ft_avltheight(newroot->right));
	return (newroot);
}
