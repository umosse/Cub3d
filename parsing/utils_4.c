/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:56:23 by aroualid          #+#    #+#             */
/*   Updated: 2024/12/09 15:30:59 by aroualid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	get_line(char *file)
{
	char	*str;
	int		infile;
	int		i;

	i = 0;
	infile = open(file, O_RDONLY);
	str = get_next_line(infile);
	while (str)
	{
		i++;
		free(str);
		str = get_next_line(infile);
	}
	close(infile);
	free(str);
	return (i);
}

int	check_lines(t_parse *parse, int i, int j, int k)
{
	int	l;

	l = skip_space(parse->lines[i]);
	if (l == (int) ft_strlen(parse->lines[i]))
		return (1);
	else if (j == (int)ft_strlen(parse->lines[i]))
	{
		j = 0;
		while (parse->lines[i][j])
		{
			if (parse->lines[i][j] == '\t')
			{
				parse->map[k] = replace_tab_by_space(parse->lines[i]);
				return (1);
			}
			j++;
		}
		parse->map[k] = ft_strdup(parse->lines[i]);
	}
	else
		free_and_exit(parse, 1, "Error\nMap Invalid 1\n");
	return (1);
}

int	fill_map_lines(t_parse *parse, int max, int fd)
{
	int	i;
	int	k;
	int	j;

	i = parse->first_line + 1;
	k = 1;
	while (i < max)
	{
		parse->lines[i] = get_next_line(fd);
		j = 0;
		while (j < (int)ft_strlen(parse->lines[i]))
		{
			if (is_ok(parse->lines[i][j]) == 1)
				j++;
			else if (is_ok(parse->lines[i][j]) == 0)
				free_and_exit(parse, 1, "Error\nMap Invalid 2\n");
		}
		check_lines(parse, i, j, k);
		i++;
		k++;
	}
	return (1);
}

void	fill_map(t_parse *parse, int max, int fd)
{
	parse->map = ft_calloc (sizeof(char *), (max - parse->first_line) + 1);
	parse->map[0] = replace_tab_by_space(parse->lines[parse->first_line]);
	fill_map_lines(parse, max, fd);
	max_map(parse);
	if (parse->max_y < get_line(parse->av) - parse->first_line - 1)
		free_and_exit(parse, 1, "Error\nMap Error\n");
	if (find_direction(parse) == 1)
		find_player_pos(parse);
	else
		free_and_exit(parse, 1, "Error\nWrong Number of Players\n");
}
