/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:17:22 by aroualid          #+#    #+#             */
/*   Updated: 2024/11/22 15:43:25 by aroualid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../cub3d.h"
#include "parsing.h"

int	ft_atoi(const char *str)
{
	int				i;
	int				signe;
	unsigned int	resultat;

	i = 0;
	signe = 1;
	resultat = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n' || str[i] == '\r'
		|| str[i] == '\t' || str[i] == '\v')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			signe *= -1;
		}
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		resultat *= 10;
		resultat += str[i] - '0';
		i++;
	}
	return (resultat * signe);
}

int	count_symbol(char *str, char symbol)
{
	int	i;
	int	res;

	res = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == symbol)
			res++;
		i++;
	}
	return (res);
}

int	is_ok(char str)
{
	if (is_space(str) == 1 || str == '1' || str == '0'
		|| str == 'N' || str == 'S' || str == 'E' || str == 'W'
		|| str == 'D' || str == 'O')
		return (1);
	return (0);
}

int	find_direction(t_parse *parse)
{
	int		i;
	int		j;
	int		res;
	char	*str;

	j = 0;
	i = 0;
	res = 0;
	while (i < parse->max_y)
	{
		str = parse->map[i];
		while (str[j] != '\n')
		{
			if (str[j] == 'N' || str[j] == 'S' || str[j] == 'E'
				|| str[j] == 'W')
				res++;
			j++;
		}
		i++;
		j = 0;
	}
	return (res);
}

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
	size_t	taille;
	int		i;
	int		res;

	res = 0;
	taille = 0;
	i = 0;
	while (parse->map[i])
	{
		if (taille < ft_strlen(parse->map[i]))
		{
			taille = ft_strlen(parse->map[i]);
			res = i;
		}
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
		if (parse->map_square[i][j] == '1')
		{
			if (parse->map_square[i][k] == '1')
				i++;
			else
				return (0);
		}
		else
			return (0);
	}
	return (1);
}

int	check_around(t_parse *parse, int j, int i)
{
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
