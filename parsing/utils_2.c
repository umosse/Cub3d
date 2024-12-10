/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 10:20:14 by aroualid          #+#    #+#             */
/*   Updated: 2024/12/10 15:02:13 by aroualid         ###   ########.fr       */
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

int	check_empty_line(t_parse *parse, int i, int l)
{
	if (l == (int) ft_strlen(parse->lines[i]))
	{
		i++;
		while (parse->lines[i])
		{
			l = skip_space(parse->lines[i]);
			if (l == (int) ft_strlen(parse->lines[i]))
				i++;
		}
		if (i + parse->first_line == get_line(parse->av))
			return (1);
	}
	printf("%i %i\n", get_line(parse->av), i + parse->first_line);
	return (0);
}
