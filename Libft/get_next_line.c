/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umosse <umosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 12:23:32 by umosse            #+#    #+#             */
/*   Updated: 2024/04/29 16:16:28 by umosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin2(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*dest;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	dest = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!dest)
		return (0);
	while (s1[i] != '\0')
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		dest[i] = s2[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	free (s1);
	return (dest);
}

char	*ft_readfile(int fd, char *line)
{
	int		bytes;
	char	*buffer;

	bytes = 1;
	if (!line)
		line = ft_calloc(sizeof(char), 1);
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free (line);
			free (buffer);
			return (NULL);
		}
		buffer[bytes] = 0;
		line = ft_strjoin2(line, buffer);
		if (ft_strchr(buffer, '\n') != NULL)
			break ;
	}
	free (buffer);
	return (line);
}

char	*ft_cutline(char *line)
{
	int		i;
	char	*newline;

	i = 0;
	if (line == NULL || line[i] == '\0')
		return (NULL);
	while (line[i] != '\0' && line[i] != '\n' )
		i++;
	newline = ft_calloc(sizeof(char), i + 2);
	if (!newline)
		return (NULL);
	i = 0;
	while (line[i] != '\0' && line[i] != '\n' )
	{
		newline[i] = line[i];
		i++;
	}
	if (line[i] && line[i] == '\n')
		newline[i] = '\n';
	return (newline);
}

char	*ft_linecomp(char *line)
{
	int		i;
	int		j;
	char	*nextline;

	i = 0;
	j = 0;
	if (*line == 0)
	{
		free (line);
		return (NULL);
	}
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] && line[i] == '\n')
		i++;
	nextline = ft_calloc(sizeof(char), (ft_strlen(line) - i) + 1);
	if (!nextline)
		return (NULL);
	while (line[i])
		nextline[j++] = line[i++];
	if (ft_strlen(nextline) == 0)
		return (free(nextline), free(line), NULL);
	free(line);
	return (nextline);
}

char	*get_next_line(int fd)
{
	static char	*buffer[8192];
	char		*line;

	if (BUFFER_SIZE <= 0)
		return (NULL);
	buffer[fd] = ft_readfile(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = ft_cutline(buffer[fd]);
	buffer[fd] = ft_linecomp(buffer[fd]);
	return (line);
}
