/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:46:12 by aroualid          #+#    #+#             */
/*   Updated: 2024/12/10 13:35:56 by aroualid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "../cub3d.h"

void	find_player_pos(t_parse *parse)
{
	int		i;
	int		j;
	char	*str;

	j = 0;
	i = 0;
	while (i < parse->max_y)
	{
		str = parse->map[i];
		while (str[j] != '\n')
		{
			if (str[j] == 'N' || str[j] == 'S' || str[j] == 'E'
				|| str[j] == 'W')
			{
				parse->player_x = j;
				parse->player_y = i;
				parse->orientation = str[j];
				parse->map[i][j] = '0';
			}
			j++;
		}
		i++;
		j = 0;
	}
}

void	max_map(t_parse *parse)
{
	int		taille;
	int		i;

	taille = 0;
	i = 0;
	while (i < get_line(parse->av) - parse->first_line && parse->map[i])
	{
		if ((parse->map[i]) && (taille < (int)ft_strlen(parse->map[i])))
			taille = (int)ft_strlen(parse->map[i]);
		i++;
	}
	parse->max_x = taille;
	parse->max_y = i;
}

int	check_first_last_wall(t_parse *parse)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (i < parse->max_y)
	{
		j = skip_space(parse->map_square[i]);
		k = skip_space_reverse(parse->map_square[i]);
		if (parse->map_square[i][j] == '1' && parse->map_square[i][k] == '1')
		{
			i++;
		}
		else
			return (0);
	}
	return (1);
}

int	check_around(t_parse *parse, int j, int i)
{
	if (check_first_last_wall(parse) == 0)
		return (6);
	if ((i > 0 && i < parse->max_y) && (j > 0 && j < parse->max_x))
	{
		if (parse->map_square[i][j + 1] && parse->map_square[i][j + 1] == ' ')
			return (2);
		if (parse->map_square[i][j - 1] && parse->map_square[i][j - 1] == ' ')
			return (3);
		if (parse->map_square[i + 1][j] && parse->map_square[i + 1][j] == ' ')
			return (4);
		if (parse->map_square[i - 1][j] && parse->map_square[i - 1][j] == ' ')
			return (5);
	}
	return (1);
}

int	check_map_ok(t_parse *parse)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (i < parse->max_y)
	{
		j = skip_space(parse->map_square[i]);
		k = skip_space_reverse(parse->map_square[i]);
		while (j < k)
		{
			if (parse->map_square[i][j] == '0'
			|| parse->map_square[i][j] == 'D'
			|| (j == parse->player_x && i == parse->player_y))
			{
				if (check_around(parse, j, i) != 1)
					return (check_around(parse, j, i));
			}
			j++;
		}
		i++;
	}
	return (1);
}
