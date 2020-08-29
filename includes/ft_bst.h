/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bst.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 11:52:25 by ptuukkan          #+#    #+#             */
/*   Updated: 2020/07/07 09:36:10 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BST_H
# define FT_BST_H

# include "libft.h"

typedef struct			s_avltree
{
	void				*content;
	size_t				content_size;
	int					height;
	struct s_avltree	*right;
	struct s_avltree	*left;
}						t_avltree;

t_avltree				*ft_avltnew(void const *content, size_t content_size);
t_avltree				*ft_avltinsert(t_avltree *root, t_avltree *newavlt,
										int (*cmp)(void *, void *));
int						ft_avltheight(t_avltree *node);
void					ft_avltprint(t_avltree *node, int depth);
void					ft_avltapply_level(t_avltree *root,
										void (*applyf)(t_avltree *, int));
t_avltree				*ft_avltrotate_right(t_avltree *node);
t_avltree				*ft_avltrotate_left(t_avltree *node);
int						ft_avltbalance(t_avltree *node);
int						ft_avltcount(t_avltree *node);

#endif
