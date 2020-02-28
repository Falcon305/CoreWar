/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazani <hrazani@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 04:56:06 by hrazani           #+#    #+#             */
/*   Updated: 2019/05/05 11:32:24 by hrazani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				detect_error(const int fd, char **line)
{
	if (fd < 0 || !line || (read(fd, *line, 0) == -1) || BUFF_SIZE < 0)
		return (-1);
	return (0);
}

int				read_func(const int fd, char **s)
{
	char	buff[BUFF_SIZE + 1];
	char	*tmp;
	int		i;

	if ((i = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[i] = '\0';
		tmp = *s;
		*s = ft_strnjoin(tmp, buff, i);
		free(tmp);
	}
	return (i);
}

int				get_next_line(const int fd, char **line)
{
	static char	*save[255];
	char		*str_end;
	int			i;

	if (detect_error(fd, line) == -1)
		return (-1);
	if (!save[fd])
		save[fd] = ft_strnew(1);
	while (!(str_end = ft_strchr(save[fd], '\n')))
	{
		if ((i = read_func(fd, &save[fd])) < 0)
			return (-1);
		if (i == 0 && !str_end)
		{
			if (save[fd][0] == '\0')
				return (0);
			*line = save[fd];
			save[fd] = NULL;
			return (1);
		}
	}
	*line = ft_strsub(save[fd], 0, str_end - save[fd]);
	save[fd] = ft_strdup(str_end + 1);
	return (1);
}
