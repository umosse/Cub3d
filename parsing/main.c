/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:36:01 by aroualid          #+#    #+#             */
/*   Updated: 2024/11/28 13:59:46 by aroualid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	get_line(char *file)
{
	char	*str;
	int		infile;
	int		i;

	i = 0;
	infile = open(file, O_RDONLY);
	str = get_next_line(infile);
	while (str)
	{
		i++;
		free(str);
		str = get_next_line(infile);
	}
	close(infile);
	free(str);
	return (i);
}

int	check_id(char *str, t_parse *parse)
{
	if (ft_strncmp(str, "NO ", 3) == 0)
		return (check_no(str, parse, parse->info));
	if (ft_strncmp(str, "SO ", 3) == 0)
		return (check_so(str, parse, parse->info));
	if (ft_strncmp(str, "WE ", 3) == 0)
		return (check_we(str, parse, parse->info));
	if (ft_strncmp(str, "EA ", 3) == 0)
		return (check_ea(str, parse, parse->info));
	if (ft_strncmp(str, "F ", 2) == 0)
		return (convert_f(str, parse, parse->info));
	if (ft_strncmp(str, "C ", 2) == 0)
		return (convert_c(str, parse, parse->info));
	return (1);
}

int	check_fill(t_parse *parse)
{
	if (parse->info->no_path == NULL)
		free_and_exit(parse, 1,"Error \nNo north texture\n");
	if (parse->info->so_path == NULL)
		free_and_exit(parse, 1,"Error \nNo south texture\n");
	if (parse->info->we_path == NULL)
		free_and_exit(parse, 1,"Error \nNo west texture\n");
	if (parse->info->ea_path == NULL)
		free_and_exit(parse, 1,"Error \nNo east texture\n");
	if (parse->info->f_color == NULL)
		free_and_exit(parse, 1,"Error \nNo floor color\n");
	if (parse->info->c_color == NULL)
		free_and_exit(parse, 1,"Error \nNo ceiling color\n");
	return (1);
}

void	check_line(t_parse *parse, int i, int j, int k)
{
	while (parse->lines[i][j] && parse->lines[i][j] != '\n')
	{	
		parse->temp[k] = parse->lines[i][j];
		j++;
		k++;
	}
}

//					printf("max x = %d\n", parse->max_x);
//					printf("max y = %i\n", parse->max_y);
//					for (int l = 0; parse->map_square[l]; l++)
//					{
//						printf("%s\n", parse->map_square[l]);
//					}

int	fill_ok(t_parse *parse, int fd, char *av, int i)
{
	if (is_all_fill(parse) == 1)
	{
		parse->last = i + 1;
		if (check_map(parse, fd, av) == 1)
		{
			fill_map(parse, get_line(av), fd);
			new_map(parse);
		parse->map[(int)parse->player_y][(int)parse->player_x] = '0';
		}
		return (1);
	}
	return (0);
}

int	parse_args(t_parse *parse, int fd, char **av)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (i < get_line(av[1]))
	{
		k = 0;
		parse->lines[i] = get_next_line(fd);
		j = skip_space(parse->lines[i]);
		parse->temp = ft_calloc(sizeof(char), ft_strlen(parse->lines[i]) + 1);
		check_line(parse, i, j, k);
		if (check_id(parse->temp, parse) == 0)
			return (free_parse_args(parse, i));
		else
		{
			if (fill_ok(parse, fd, av[1], i) == 1)
				return (1);
		}
		free_parse_args(parse, i);
		i++;
	}
	return (0);
}
