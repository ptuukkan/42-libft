/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vlq_sum.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 15:04:38 by ptuukkan          #+#    #+#             */
/*   Updated: 2019/10/22 15:00:51 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_sum(char **nb1, char **nb2)
{
	int	val1;
	int	val2;

	if (**nb1 != '\0')
	{
		val1 = **nb1 - '0';
		(*nb1)++;
	}
	else
		val1 = 0;
	if (**nb2 != '\0')
	{
		val2 = **nb2 - '0';
		(*nb2)++;
	}
	else
		val2 = 0;
	return (val1 + val2);
}

static char	*vlq_sum_integer(char *nb1, char *nb2, int i, int rem)
{
	int		n;
	char	*result;

	result = ft_strnew(ft_max(ft_strlen(nb1), ft_strlen(nb2)) + 1);
	if (nb1 == NULL || nb2 == NULL || result == NULL)
		return (NULL);
	ft_strrev(nb1);
	ft_strrev(nb2);
	i = 0;
	rem = 0;
	while (*nb1 != '\0' || *nb2 != '\0' || rem > 0)
	{
		n = get_sum(&nb1, &nb2) + rem;
		rem = 0;
		if (n > 9)
		{
			result[i++] = n - 10 + '0';
			rem = 1;
		}
		else
			result[i++] = n + '0';
	}
	ft_strrev(result);
	return (result);
}

static void	equalize_strings(char **nb1, char **nb2, size_t len1, size_t len2)
{
	char	*new;

	if (len1 == len2)
		return ;
	if (len1 > len2)
	{
		if (!(new = ft_strnew(len1)))
			return ;
		ft_strncpy(new, nb2[1], len2);
		ft_memset(new + len2, '0', len1 - len2);
		ft_strdel(&nb2[1]);
		nb2[1] = new;
	}
	else
	{
		if (!(new = ft_strnew(len2)))
			return ;
		ft_strncpy(new, nb1[1], len1);
		ft_memset(new + len1, '0', len2 - len1);
		ft_strdel(&nb1[1]);
		nb1[1] = new;
	}
}

static char	*vlq_sum_frac(char *res_int, char **nb1, char **nb2, char *tmp)
{
	char	*result;

	if (nb1[1] != NULL && nb2[1] != NULL)
	{
		equalize_strings(nb1, nb2, ft_strlen(nb1[1]), ft_strlen(nb2[1]));
		tmp = vlq_sum_integer(nb1[1], nb2[1], 0, 0);
		if ((int)ft_strlen(tmp) > ft_max(ft_strlen(nb1[1]), ft_strlen(nb2[1])))
		{
			result = vlq_sum_integer(res_int, "1", 0, 0);
			ft_strdel(&res_int);
			res_int = result;
			result = ft_strnjoin(3, res_int, ".", tmp + 1);
		}
		else
			result = ft_strnjoin(3, res_int, ".", tmp);
		ft_strdel(&tmp);
	}
	else if (nb1[1] != NULL)
		result = ft_strnjoin(3, res_int, ".", nb1[1]);
	else
		result = ft_strnjoin(3, res_int, ".", nb2[1]);
	ft_strdel(&res_int);
	ft_strarrdel(&nb1);
	ft_strarrdel(&nb2);
	return (result);
}

char		*vlq_sum(char *nb1, char *nb2)
{
	char	**nb1_split;
	char	**nb2_split;
	char	*result;
	char	*tmp;

	tmp = NULL;
	if (nb1 == NULL || nb2 == NULL)
		return (NULL);
	nb1_split = ft_strsplit(nb1, '.');
	nb2_split = ft_strsplit(nb2, '.');
	result = vlq_sum_integer(nb1_split[0], nb2_split[0], 0, 0);
	if (nb1_split[1] == NULL && nb2_split[1] == NULL)
	{
		ft_strdel(nb1_split);
		free(nb1_split);
		ft_strdel(nb2_split);
		free(nb2_split);
		return (result);
	}
	else
		return (vlq_sum_frac(result, nb1_split, nb2_split, tmp));
}
