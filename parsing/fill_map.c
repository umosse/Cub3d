/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:37:57 by aroualid          #+#    #+#             */
/*   Updated: 2024/11/14 17:45:04 by aroualid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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

void	check_map(t_parse *parse, int fd, char *av)
{
	int	i;
	int	j;
	int k;

	i = parse->last;
	while (i < get_line(av))
	{
		k = 0;
		parse->lines[i] = get_next_line(fd);
		j = skip_space(parse->lines[i]);
		if (j == (int) ft_strlen(parse->lines[i]))
		{
			i++;
			free_parse_args(parse, i);
		}
		else
		{
			while (parse->lines[i] && (parse->lines[i][k] == '1'
				|| isspace(parse->lines[i][k]) == 1))
				k++;
			printf("%s\n", parse->lines[i]);
			return ;
		}
	}

}
