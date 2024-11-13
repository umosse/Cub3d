/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:36:01 by aroualid          #+#    #+#             */
/*   Updated: 2024/11/13 16:02:53 by aroualid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include <stdio.h>

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
		return (printf("Error \nNo north texture\n"), 0);
	if (parse->info->so_path == NULL)
		return (printf("Error \nNo south texture\n"), 0);
	if (parse->info->we_path == NULL)
		return (printf("Error \nNo west texture\n"), 0);
	if (parse->info->ea_path == NULL)
		return (printf("Error \nNo east texture\n"), 0);
	if (parse->info->f_color == NULL)
		return (printf("Error \nNo floor color\n"), 0);
	if (parse->info->c_color == NULL)
		return (printf("Error \nNo ceiling color\n"), 0);
	return (1);
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
		while (parse->lines[i][j] && parse->lines[i][j] != '\n')
		{
			parse->temp[k] = parse->lines[i][j];
			j++;
			k++;
		}
		if (check_id(parse->temp, parse) == 0)
			return (free_parse_args(parse, i));
		free_parse_args(parse, i);
		i++;
	}
	return (check_fill(parse));
}

int	main(int ac, char **av)
{
	int		fd;
	t_parse	*parse;

	parse = (t_parse *){0};
	parse = ft_calloc(sizeof(t_parse), 1);
	parse->info = ft_calloc(sizeof(t_info), 1);
	if (ac == 2)
	{
		if (check_file(av[1]) == 1)
		{
			parse->lines = ft_calloc(sizeof(char **), get_line(av[1]));
			fd = open(av[1], O_RDONLY);
			if (parse_args(parse, fd, av) == 0)
			{
				close(fd);
				return (0);
			}
			close(fd);
			printf("NO = %s\n", parse->info->no_path);
			printf("SO = %s\n", parse->info->so_path);
			printf("WE = %s\n", parse->info->we_path);
			printf("EA = %s\n", parse->info->ea_path);
			printf("F = %i\n", parse->info->f);
			printf("C = %i\n", parse->info->c);
		}
		else
		{
			printf("Error \nWrong file\n");
			return  (0);
		}
	}
	else
	{
		printf("Error \nWrong number of arg\n");
		return (0);
	}
	return (1);
}
