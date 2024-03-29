/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avltprint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 11:52:25 by ptuukkan          #+#    #+#             */
/*   Updated: 2020/07/07 09:36:10 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			g_first;

static void	print_content(t_avltree *node, int first, int height)
{
	int field1;
	int	field2;

	field1 = 0;
	if (height > 2)
		field1 = (int)ft_pow(2.0, height - 3) * 6 - 3;
	field2 = field1 * 2 + 1;
	if (!first)
		field1 = field2;
	if (node->left)
		ft_printf("%*d", field1 + 5, *(int *)node->left->content);
	else
		ft_printf("%*c", field1 + 5, ' ');
	if (node->right)
		ft_printf("%*d", field2 + 5, *(int *)node->right->content);
	else
		ft_printf("%*c", field2 + 5, ' ');
}

static void	print_slash(t_avltree *node, int field1, int field2)
{
	if (node->left)
		ft_printf("%*c", field1, '/');
	else
		ft_printf("%*c", field1, ' ');
	if (node->right)
		ft_printf("%*c", field2, '\\');
	else
		ft_printf("%*c", field2, ' ');
}

static void	print_slashes(t_avltree *node, int first, int height)
{
	int field1;
	int	field2;

	field1 = 3;
	field2 = 6;
	if (height < 3 && !first)
		field1 = 6;
	else if (height > 2 && first)
	{
		field1 = (int)ft_pow(2.0, height - 3) * 6 - 3;
		field2 = field1 * 2;
		field1 += 6;
	}
	else if (height > 2 && !first)
	{
		field1 = (int)ft_pow(2.0, height - 3) * 6 - 3;
		field2 = field1 * 2;
		field1 = field2 + 12;
	}
	print_slash(node, field1, field2);
}

static void	apply_level(t_avltree *root, int level,
						void (*applyf)(t_avltree *, int, int), int height)
{
	if (!root || level < 0)
		return ;
	if (level == 0)
	{
		applyf(root, g_first, height);
		if (g_first)
			g_first = 0;
	}
	apply_level(root->left, level - 1, applyf, height - 1);
	apply_level(root->right, level - 1, applyf, height - 1);
}

void		ft_avltprint(t_avltree *node, int depth)
{
	int	level;
	int	field;

	if (!node)
		return ;
	field = (int)ft_pow(2.0, node->height - 2) * 6 + 2;
	ft_printf("%*d\n", field, *(int *)node->content);
	level = 0;
	depth = ft_min(node->height, depth);
	while (level < depth - 1)
	{
		g_first = 1;
		apply_level(node, level, &print_slashes, node->height);
		ft_printf("\n");
		g_first = 1;
		apply_level(node, level, &print_content, node->height);
		ft_printf("\n");
		level++;
	}
}
