/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btreeprefix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 11:52:25 by ptuukkan          #+#    #+#             */
/*   Updated: 2020/07/07 09:36:10 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_btreeprefix(t_btree *root, void (*applyf)(void *))
{
	if (!root)
		return ;
	(*applyf)(root->content);
	ft_btreeprefix(root->left, applyf);
	ft_btreeprefix(root->right, applyf);
}
