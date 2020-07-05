/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 14:23:19 by ptuukkan          #+#    #+#             */
/*   Updated: 2019/11/06 09:37:07 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		copy_line(t_list **stack, char **line, int eof)
{
	char	*temp;
	char	*templine;

	if (!(ft_lstchr(*stack, '\n')))
	{
		if (eof == 0 && *stack)
		{
			if (!(*line = (char *)ft_lstfold(stack, &ft_lstjoin)))
				return (-1);
			return (1);
		}
		return (0);
	}
	if (!(templine = (char *)ft_lstfold(stack, &ft_lstjoin)))
		return (-1);
	temp = ft_strchr(templine, '\n');
	*(temp++) = '\0';
	if (!(*line = ft_strdup(templine)))
		return (-1);
	if (*temp != '\0')
		if (!(*stack = ft_lstnew(temp, ft_strlen(temp) + 1)))
			return (-1);
	ft_strdel(&templine);
	temp = NULL;
	return (1);
}

static int		read_line(const int fd, char **line, t_list **stack)
{
	char	buf[BUFF_SIZE + 1];
	int		ret;
	int		res;

	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		ft_lstapp(stack, ft_lstnew(buf, ret + 1));
		if ((*stack)->content == NULL)
			return (-1);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	res = copy_line(stack, line, ret);
	return (res);
}

int				get_next_line(const int fd, char **line)
{
	char			buf;
	static t_list	*stack[MAX_FD];
	int				res;

	if (fd < 0 || line == NULL || (read(fd, &buf, 0)) == -1)
		return (-1);
	if (stack[fd])
	{
		res = copy_line(&stack[fd], line, 1);
		if (res == 1)
			return (res);
	}
	res = read_line(fd, line, &stack[fd]);
	return (res);
}
