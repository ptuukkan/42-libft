/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exiterror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 12:37:21 by ptuukkan          #+#    #+#             */
/*   Updated: 2019/12/19 12:39:09 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_exiterror(char *err_msg, int exitcode, int fd)
{
	if (err_msg)
		ft_putendl_fd(err_msg, fd);
	exit(exitcode);
}
