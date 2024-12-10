/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:37:57 by aroualid          #+#    #+#             */
/*   Updated: 2024/12/10 13:19:56 by aroualid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "parsing.h"

int	is_space(int c)
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
	parse->map_square = ft_calloc(sizeof(char *), parse->max_y + 2);
	while (i < parse->max_y)
	{
		parse->map_square[i] = ft_calloc(sizeof(char), parse->max_x);
		ft_memset(parse->map_square[i], ' ', parse->max_x - 1);
		ft_memcpy(parse->map_square[i], parse->map[i],
			ft_strlen(parse->map[i]) - 1);
		i++;
	}
	parse->map_square[i] = ft_calloc(sizeof(char), parse->max_x);
	ft_memset(parse->map_square[parse->max_y], ' ', parse->max_x);
	if (check_map_ok(parse) != 1)
		free_and_exit(parse, 1, "Error\nMap Invalid 3\n");
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
			|| is_space(parse->lines[i][k]) == 1)
			j++;
		k++;
	}
	if (j == (int)ft_strlen(parse->lines[i]))
	{
		parse->first_line = i;
		return (1);
	}
	else
	{
		free_and_exit(parse, 1, "Error\nMap Error\n");
		return (0);
	}
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
			return (1);
		i++;
	}
	return (0);
}
