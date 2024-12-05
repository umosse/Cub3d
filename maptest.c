/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maptest.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 10:09:18 by aroualid          #+#    #+#             */
/*   Updated: 2024/12/05 15:40:52 by aroualid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_mapread2(int fd, char *line)
{
	while (line)
	{
		line = get_next_line(fd);
		free(line);
		close(fd);
	}
}

int	ft_mapread3(char *line, t_game *game, int fd)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		line = get_next_line(fd);
		free(line);
		i++;
	}
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		game->map[i] = line;
		game->maptest[i] = ft_strdup(line);
		game->maxmapx = ft_strlen(game->map[0]);
		if ((int)ft_strlen(game->map[i]) != game->maxmapx)
		{
			ft_mapread2(fd, line);
			return (-1);
		}
		i++;
		line = get_next_line(fd);
	}
	return (i);
}

char	**ft_mapread(char *file, t_game *game)
{
	(void) file;
	game->map = game->parse->map_square;
	return (game->map);
}

char	**ft_mapalloc(char *file, t_game *game)
{
	int		fd;
	char	*line;
	char	**map;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	line = get_next_line(fd);
	while (line)
	{
		game->maxmapy++;
		free (line);
		line = get_next_line(fd);
	}
	free (line);
	map = ft_calloc(game->maxmapy, sizeof(char *));
	game->maptest = ft_calloc(game->maxmapy, sizeof(char *));
	close(fd);
	return (map);
}
