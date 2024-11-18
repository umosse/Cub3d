/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:17:22 by aroualid          #+#    #+#             */
/*   Updated: 2024/11/18 16:26:00 by aroualid         ###   ########.fr       */
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

	if (isspace(str) == 1 || str == '1' || str == '0'
		|| str == 'N' || str == 'S' || str == 'E' || str == 'W'
		|| str == 'D')
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

int	check_wall(t_parse *parse, int x, int y)
{
	if (x < 0 || x >= parse->max_x || y < 0 || y >= parse->max_y)
		return (0);
	if (parse->map_square[y][x] == '1' || parse->map_square[y][x] == '2')
		;
	if (parse->map_square[y][x] == ' ')
		return(0);
	else
		return (0);
	parse->map_square[y][x] = '2';
	check_wall(parse, x + 1, y);
	check_wall(parse, x - 1, y);
	check_wall(parse, x, y + 1);
	check_wall(parse, x, y - 1);
	return (1);
}
