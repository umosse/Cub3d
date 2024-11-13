/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 09:17:24 by aroualid          #+#    #+#             */
/*   Updated: 2024/11/13 13:53:28 by aroualid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	line_length(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	return (i);
}

static char	*join(char *str, char *buffer)
{
	char	*s;
	int		i;
	int		j;
	int		line_len;

	line_len = line_length(buffer);
	s = ft_calloc(ft_strlen(str) + line_len + 1, 1);
	if (!s)
		return (NULL);
	i = 0;
	while (str[i])
	{
		s[i] = str[i];
		i++;
	}
	j = 0;
	while (j < line_length(buffer))
		s[i++] = buffer[j++];
	return (free(str), s);
}

static char	*ft_read(int fd, char *buffer, char *str)
{
	int			bytes;
	char		*nl;

	if (!str)
		return (NULL);
	while (1)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
			return (free(str), NULL);
		else if (bytes == 0)
			return (buffer[0] = '\0', str);
		buffer[bytes] = '\0';
		str = join(str, buffer);
		if (!str)
			return (NULL);
		nl = ft_strchr(buffer, '\n');
		if (nl++)
		{
			ft_memcpy(buffer, nl, bytes - (int)(nl - buffer));
			buffer[bytes - (int)(nl - buffer)] = '\0';
			break ;
		}
	}
	return (str);
}

static char	*copy_remaining(char *buffer)
{
	char	*s;
	int		i;
	char	*nl;
	int		line_len;

	line_len = line_length(buffer);
	s = malloc(line_len + 1);
	s[line_len] = '\0';
	if (!s)
		return (NULL);
	i = -1;
	while (++i < line_len)
		s[i] = buffer[i];
	nl = ft_strchr(buffer, '\n');
	if (nl)
	{
		nl++;
		ft_memcpy(buffer, nl, BUFFER_SIZE - (int)(nl - buffer));
		buffer[BUFFER_SIZE - (int)(nl - buffer)] = '\0';
	}
	else
		buffer[0] = '\0';
	return (s);
}

char	*get_next_line(int fd)
{
	char		*line;
	int			n;
	static char	buffer[BUFFER_SIZE + 1];

	line = NULL;
	if (*buffer != '\0')
	{
		line = copy_remaining(buffer);
		n = ft_strlen(line);
		if (line[n - 1] == '\n')
			return (line);
		else if (line[n - 1] == '\0')
			return (line);
	}
	else
		line = ft_calloc(1, 1);
	line = ft_read(fd, buffer, line);
	if (!line)
		return (NULL);
	if (*line == '\0')
		return (free(line), NULL);
	return (line);
}
