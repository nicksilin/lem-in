/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroleo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 13:58:08 by jgroleo           #+#    #+#             */
/*   Updated: 2019/10/04 17:15:27 by jgroleo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_add(char **s, char *buf, int fd)
{
	char	*tmp;

	if (!s[fd])
		s[fd] = ft_strdup(buf);
	else
	{
		tmp = ft_strjoin(s[fd], buf);
		free(s[fd]);
		s[fd] = tmp;
	}
}

static int		ft_check(char **s, char **line, int fd)
{
	int		i;
	char	*tmp;

	i = 0;
	if (s[fd] == NULL)
		return (0);
	while (s[fd][i] != '\n' && s[fd][i] != '\0')
		i++;
	if (s[fd][i] == '\n')
	{
		*line = ft_strndup(s[fd], (size_t)i);
		tmp = ft_strdup(s[fd] + i + 1);
		free(s[fd]);
		s[fd] = tmp;
	}
	else if (s[fd][i] == '\0')
	{
		*line = ft_strdup(s[fd]);
		tmp = ft_strdup(s[fd] + i);
		free(s[fd]);
		s[fd] = tmp;
		if (*line[0] == '\0')
			return (0);
	}
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	int			read_bytes;
	static char	*s[FD_SIZE];

	if (!line || fd < 0 || fd > 10240)
		return (-1);
	while ((read_bytes = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[read_bytes] = '\0';
		ft_add(s, buf, fd);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (read_bytes < 0)
		return (-1);
	if ((!ft_check(s, line, fd)) && read_bytes == 0 &&
			(!s[fd] || s[fd][0] == '\0'))
		return (0);
	return (1);
}
