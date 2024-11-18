/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:37:57 by aroualid          #+#    #+#             */
/*   Updated: 2024/11/18 16:25:43 by aroualid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "parsing.h"

int	isspace(int c)
{
	if (c == ' ' || c == '\f' || c == '\n' || c == '\r'
		|| c == '\t' || c == '\v')
		return (1);
	return (0);
}

int	is_all_fill(t_parse *parse)
{
	if (parse->info->no_ok == 1 && parse->info->so_ok == 1
		&& parse->info->we_ok == 1 && parse->info->ea_ok == 1
		&& parse->info->c_ok == 1 && parse->info->f_ok == 1)
		return (1);
	return (0);
}

void	new_map(t_parse *parse)
{
	int	i;

	i = 0;
	parse->map_square = ft_calloc(sizeof(char *), parse->max_y + 1);
	while (i < parse->max_y)
	{
		parse->map_square[i] = ft_calloc(sizeof(char), parse->max_x );
		ft_memset(parse->map_square[i], ' ', parse->max_x - 1);
		ft_memcpy(parse->map_square[i], parse->map[i], ft_strlen(parse->map[i]) - 1);
		i++;
	}
	printf("%i\n", check_wall(parse, skip_space(parse->map_square[0]), 0 ));
}

void	fill_map(t_parse *parse, int max, int fd)
{
	int	i;
	int	j;
	int	k;

	k = 1;
	i = parse->first_line + 1;
	parse->map = ft_calloc (sizeof(char *), (max - parse->first_line) + 1);
	parse->map[0] = ft_strdup (parse->lines[parse->first_line]);
	while (i < max)
	{
		parse->lines[i] = get_next_line(fd);
		j = 0;
		while (parse->lines[i][j])
		{
			if (is_ok(parse->lines[i][j]) == 1)
				j++;
			else
			{
				printf("Error\nMap Invalid\n");
				return ;
			}
		}
		if (j == (int)ft_strlen(parse->lines[i]))
			parse->map[k] = ft_strdup(parse->lines[i]);
		else
		{
			printf("Error\nMap Invalid\n");
			return ;
		}
		free_parse_args(parse, i);
		i++;
		k++;
	}
	max_map(parse);
	if (find_direction(parse) == 1)
		find_player_pos(parse);
	else
		return ;
}

int	first_line(t_parse *parse, int i)
{
	int	j;
	int	k;

	j = 0;
	k = 0;
	while (parse->lines[i][k])
	{
		if (parse->lines[i][k] == '1'
			|| isspace(parse->lines[i][k]) == 1)
			j++;
		k++;

	}
	if (j == (int)ft_strlen(parse->lines[i]))
	{
		parse->first_line = i;
		return (1);
	}
	else
		return (0);
}

int	check_map(t_parse *parse, int fd, char *av)
{
	int	i;
	int	j;

	i = parse->last;
	while (i < get_line(av))
	{
		parse->lines[i] = get_next_line(fd);
		j = skip_space(parse->lines[i]);
		if (j == (int) ft_strlen(parse->lines[i]))
			;
		else if (first_line(parse, i) == 1)
		{
			return (1);
		}
		free_parse_args(parse, i);
		i++;
	}
	return (0);
}
