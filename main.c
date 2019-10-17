/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 11:54:08 by ptuukkan          #+#    #+#             */
/*   Updated: 2019/10/17 16:11:20 by ptuukkan         ###   ########.fr       */
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

int		main(void)
{
	ft_putstr_fd("toto", 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(123123, 1);
	ft_putchar_fd('\n', 1);
	ft_putendl_fd("tata", 1);
	
	ft_putstr_fd("toto", 2);
	ft_putchar_fd('\n', 2);
	ft_putnbr_fd(123123, 2);
	ft_putchar_fd('\n', 2);
	ft_putendl_fd("tata", 2);
	
	
	return (0);
}
