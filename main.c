/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 11:54:08 by ptuukkan          #+#    #+#             */
/*   Updated: 2019/10/17 12:52:10 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <ctype.h>

void	printarray(int *arr, int n)
{
	int	i;

	i = 0;
	while (n > i)
	{
		printf("%d", arr[i]);
		i++;
	}
}

void	ft_toupper2(unsigned int i, char *c)
{
	printf("%d\n", i);
	*c = ft_toupper(*c);
}

int		main(int argc, char **argv)
{
	char	**tab;
	
	if (argc != 3)
		return (1);
	tab = ft_strsplit(argv[2], argv[3][0]);
	if (tab != NULL)
	{
		while (*tab != NULL)
		{
			printf("%s\n", *tab);
			tab++;
		}
	}
}
