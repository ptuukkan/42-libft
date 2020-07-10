/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avltinsert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 11:52:25 by ptuukkan          #+#    #+#             */
/*   Updated: 2020/07/07 09:36:10 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_avltree	*rotate(t_avltree *root, int balance, int cmpresult)
{
	if (balance > 1 && cmpresult < 1)
		return (ft_avltrotate_right(root));
	if (balance > 1 && cmpresult == 1)
	{
		root->left = ft_avltrotate_left(root->left);
		return (ft_avltrotate_right(root));
	}
	if (balance < -1 && cmpresult == 1)
		return (ft_avltrotate_left(root));
	if (balance < -1 && cmpresult < 1)
	{
		root->right = ft_avltrotate_right(root->right);
		return (ft_avltrotate_left(root));
	}
	return (root);
}

t_avltree			*ft_avltinsert(t_avltree *root, t_avltree *newavlt,
									int (*cmp)(void *, void *))
{
	int	cmpresult;
	int	balance;

	if (!root)
		return (newavlt);
	cmpresult = (*cmp)(newavlt->content, root->content);
	if (cmpresult > 0)
		root->right = ft_avltinsert(root->right, newavlt, cmp);
	else
		root->left = ft_avltinsert(root->left, newavlt, cmp);
	root->height = 1 + ft_max(ft_avltheight(root->right),
		ft_avltheight(root->left));
	balance = ft_avltbalance(root);
	if (balance > 1 || balance < -1)
		return rotate(root, balance, cmpresult);
	return root;
}
