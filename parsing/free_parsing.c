/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:31:20 by aroualid          #+#    #+#             */
/*   Updated: 2024/12/05 15:24:06 by aroualid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	free_parse_args(t_parse *parse, int i)
{
	free (parse->temp);
	parse->temp = NULL;
	(void) i;
	return (0);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	free_info(t_info *info)
{
	if (info->c_rgb != NULL)
		free_split (info->c_rgb);
	if (info->f_rgb != NULL)
		free_split (info->f_rgb);
	if (info->no_path != NULL)
		free (info->no_path);
	if (info->so_path != NULL)
		free (info->so_path);
	if (info->we_path != NULL)
		free (info->we_path);
	if (info->ea_path != NULL)
		free (info->ea_path);
	if (info->f_color != NULL)
		free (info->f_color);
	if (info->c_color != NULL)
		free (info->c_color);
	free(info);
}

void	free_lines(t_parse *parse)
{
	int	i;

	i = 0;
	while (i < get_line(parse->av))
	{
		if (parse->lines[i] != NULL)
		{
			free (parse->lines[i]);
			parse->lines[i] = NULL;
		}
		i++;
	}
	free(parse->lines);
}

void	free_and_exit(t_parse *parse, int print, char *str)
{
	if (parse->lines != NULL)
		free_lines(parse);
	if (parse->map_square != NULL)
		free_split(parse->map_square);
	if (parse->map != NULL)
		free_split(parse->map);
	if (parse->temp != NULL)
		free (parse->temp);
	if (parse->info != NULL)
		free_info(parse->info);
	if (parse->av != NULL)
		free (parse->av);
	if (parse->fd != -1)
		close (parse->fd);
	free(parse);
	if (print == 1)
		printf("%s", str);
	exit (0);
}
