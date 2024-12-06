/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_rgb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:51:07 by aroualid          #+#    #+#             */
/*   Updated: 2024/12/06 11:51:12 by aroualid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../cub3d.h"
#include "parsing.h"

int	check_f(char *str, t_parse *parse, t_info *info)
{
	int		j;
	char	*res;
	int		k;
	int		i;

	k = 0;
	j = 1;
	if (parse->info->f_ok == 1)
		free_and_exit(parse, 1, "Error\ntoo many F \n");
	res = new_string(str, 1);
	parse->info->f_ok = 1;
	i = skip_space(res);
	j = i;
	info->f_color = ft_calloc(sizeof(char *), ft_strlen(res));
	while (k < (int)ft_strlen(res))
	{
		parse->info->f_color[k] = res[j];
		k++;
		j++;
	}
	free(res);
	return (1);
}

int	check_c(char *str, t_parse *parse, t_info *info)
{
	int		j;
	char	*res;
	int		k;
	int		i;

	k = 0;
	j = 1;
	if (parse->info->c_ok == 1)
		free_and_exit(parse, 1, "Error\ntoo many C \n");
	res = new_string(str, 1);
	parse->info->c_ok = 1;
	i = skip_space(res);
	j = i;
	info->c_color = ft_calloc(sizeof(char *), ft_strlen(res));
	while (k < (int)ft_strlen(res))
	{
		parse->info->c_color[k] = res[j];
		k++;
		j++;
	}
	free(res);
	return (1);
}

unsigned int	get_color(int red, int green, int blue)
{
	unsigned int	color;

	color = 0;
		color = (color << 8) | red;
		color = (color << 8) | green;
		color = (color << 8) | blue;
	return (color);
}

int	convert_f(char *str, t_parse *parse, t_info *info)
{
	int	r;
	int	g;
	int	b;

	if (check_f(str, parse, info) == 1)
	{
		info->f_rgb = ft_split(info->f_color, ',');
		if (info->f_rgb[0] != NULL && (info->f_rgb[1] != NULL)
			&& (info->f_rgb[2] != NULL) && (info->f_rgb[3] == NULL)
			&& count_symbol(info->f_color, ',') == 2)
		{
			r = ft_atoi(info->f_rgb[0]);
			g = ft_atoi(info->f_rgb[1]);
			b = ft_atoi(info->f_rgb[2]);
			if (r >= 0 && r <= 255 && g >= 0 && g <= 255 && b >= 0 && b <= 255)
				return (info->f = get_color(r, g, b));
			free_and_exit(parse, 1, "Error\nBad args in F\n");
		}
		else
			free_and_exit(parse, 1, "Error\nBad args in F\n");
	}
	else
		return (0);
	return (1);
}

int	convert_c(char *str, t_parse *parse, t_info *info)
{
	int	r;
	int	g;
	int	b;

	if (check_c(str, parse, info) == 1)
	{
		info->c_rgb = ft_split(info->c_color, ',');
		if (info->c_rgb[0] != NULL && (info->c_rgb[1] != NULL)
			&& (info->c_rgb[2] != NULL) && (info->c_rgb[3] == NULL)
			&& count_symbol(info->c_color, ',') == 2)
		{
			r = ft_atoi(info->c_rgb[0]);
			g = ft_atoi(info->c_rgb[1]);
			b = ft_atoi(info->c_rgb[2]);
			if (r >= 0 && r <= 255 && g >= 0 && g <= 255 && b >= 0 && b <= 255)
				return (info->c = get_color(r, g, b));
			free_and_exit(parse, 1, "Error\nBad args in C\n");
		}
		else
			free_and_exit(parse, 1, "Error\nBad args in C\n");
	}
	else
		return (0);
	return (1);
}
