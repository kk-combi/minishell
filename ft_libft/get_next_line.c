/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasasaki <kasasaki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 19:55:35 by kasasaki          #+#    #+#             */
/*   Updated: 2024/12/14 16:05:21 by kasasaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*get_line(char *buf)
{
	char	*line;
	size_t	i;

	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (buf[i] && buf[i] != '\n')
	{
		line[i] = buf[i];
		i++;
	}
	if (buf[i] && buf[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*update_buf(char *buf, int *is_err)
{
	size_t	i;
	size_t	j;
	char	*newbuf;

	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (!buf[i])
		return (free(buf), NULL);
	newbuf = malloc(sizeof(char) * ((ft_strlen(buf) - i) + 1));
	if (!newbuf)
	{
		*is_err = 1;
		return (free(buf), NULL);
	}
	i++;
	j = 0;
	while (buf[i])
		newbuf[j++] = buf[i++];
	newbuf[j] = '\0';
	free(buf);
	return (newbuf);
}

static char	*read_file(int fd, char *rest)
{
	char	*buf;
	ssize_t	n;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (free(rest), NULL);
	n = 1;
	while (rest && n > 0 && (ft_strchr(rest, '\n') == NULL))
	{
		n = read(fd, buf, BUFFER_SIZE);
		if (n == -1)
		{
			free(buf);
			free(rest);
			return (NULL);
		}
		buf[n] = '\0';
		rest = strjoin_and_free(rest, buf);
	}
	free(buf);
	return (rest);
}

int	is_empty_line(char **buf)
{
	if (*buf && !*buf[0])
	{
		free(*buf);
		*buf = NULL;
		return (1);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*line;
	int			is_err;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buf)
	{
		buf = malloc(sizeof(char) * 1);
		if (!buf)
			return (NULL);
		buf[0] = '\0';
	}
	buf = read_file(fd, buf);
	if (!buf || is_empty_line(&buf))
		return (NULL);
	line = get_line(buf);
	if (!line)
		return (NULL);
	is_err = 0;
	buf = update_buf(buf, &is_err);
	if (is_err)
		return (NULL);
	return (line);
}
