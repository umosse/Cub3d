/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_rgb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:51:07 by aroualid          #+#    #+#             */
/*   Updated: 2024/11/13 13:53:02 by aroualid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		return (printf("Error\ntoo many F \n"), 0);
	res = new_string(str, 1);
	parse->info->f_ok = 1;
	i = skip_space(res);
	j = i;
	parse->info->f_color = ft_calloc(sizeof(char *), ft_strlen(res));
	while (k < ft_strlen(res))
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
		return (printf("Error\ntoo many C \n"), 0);
	res = new_string(str, 1);
	parse->info->c_ok = 1;
	i = skip_space(res);
	j = i;
	parse->info->c_color = ft_calloc(sizeof(char *), ft_strlen(res));
	while (k < ft_strlen(res))
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
			if ((r >= 0 && r <= 255)
				&& (g >= 0 && g <= 255) && (b >= 0 && g <= 255))
			info->f = get_color(r, g, b);
		}
		else
			return (printf("Error\nBad args in F\n"), 0);
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
			if ((r >= 0 && r <= 255)
				&& (g >= 0 && g <= 255) && (b >= 0 && g <= 255))
				info->c = get_color(r, g, b);
		}
		else
			return (printf("Error\nBad args in C\n"), 0);
	}
	else
		return (0);
	return (1);
}
