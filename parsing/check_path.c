/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:51:13 by aroualid          #+#    #+#             */
/*   Updated: 2024/12/16 16:08:04 by aroualid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "parsing.h"

char	*new_string(char *str, int taille)
{
	char	*res;
	int		k;
	int		len;

	res = ft_calloc(sizeof(char *), ft_strlen(str));
	if (!res)
		return (res = NULL);
	k = 0;
	len = (int) ft_strlen(str);
	while (taille < len)
	{
		res[k] = str[taille];
		k++;
		taille++;
	}
	if (res && skip_space(res) == (int) ft_strlen(res))
		return (free(res), res = NULL);
	return (res);
}

int	check_no(char *str, t_parse *parse, t_info *info)
{
	int		j;
	char	*res;
	int		k;
	int		i;

	k = 0;
	j = 2;
	if (parse->info->no_ok == 1)
		free_and_exit(parse, 1, "Error\ntoo many NO \n");
	res = new_string(str, 2);
	if (res == NULL)
		free_and_exit(parse, 1, "Error\nError in NO\n");
	info->no_ok = 1;
	i = skip_space(res);
	j = i;
	parse->info->no_path = ft_calloc(sizeof(char *), ft_strlen(res));
	while (k < (int)ft_strlen(res))
	{
		parse->info->no_path[k] = res[j];
		k++;
		j++;
	}
	free(res);
	return (1);
}

int	check_so(char *str, t_parse *parse, t_info *info)
{
	int		j;
	char	*res;
	int		k;
	int		i;

	k = 0;
	j = 2;
	if (parse->info->so_ok == 1)
		free_and_exit(parse, 1, "Error\ntoo many SO \n");
	res = new_string(str, 2);
	if (res == NULL)
		free_and_exit(parse, 1, "Error\nError in SO\n");
	info->so_ok = 1;
	i = skip_space(res);
	j = i;
	parse->info->so_path = ft_calloc(sizeof(char *), ft_strlen(res));
	while (k < (int)ft_strlen(res))
	{
		parse->info->so_path[k] = res[j];
		k++;
		j++;
	}
	free(res);
	return (1);
}

int	check_we(char *str, t_parse *parse, t_info *info)
{
	int		j;
	char	*res;
	int		k;
	int		i;

	k = 0;
	j = 2;
	if (parse->info->we_ok == 1)
		free_and_exit(parse, 1, "Error\ntoo many WE \n");
	res = new_string(str, 2);
	if (res == NULL)
		free_and_exit(parse, 1, "Error\nError in WE\n");
	info->we_ok = 1;
	i = skip_space(res);
	j = i;
	parse->info->we_path = ft_calloc(sizeof(char *), ft_strlen(res));
	while (k < (int)ft_strlen(res))
	{
		parse->info->we_path[k] = res[j];
		k++;
		j++;
	}
	free(res);
	return (1);
}

int	check_ea(char *str, t_parse *parse, t_info *info)
{
	int		j;
	char	*res;
	int		k;
	int		i;

	k = 0;
	j = 2;
	if (parse->info->ea_ok == 1)
		free_and_exit(parse, 1, "Error\ntoo many EA \n");
	res = new_string(str, 2);
	if (res == NULL)
		free_and_exit(parse, 1, "Error\nError in EA\n");
	info->ea_ok = 1;
	i = skip_space(res);
	j = i;
	parse->info->ea_path = ft_calloc(sizeof(char *), ft_strlen(res));
	while (k < (int)ft_strlen(res))
	{
		parse->info->ea_path[k] = res[j];
		k++;
		j++;
	}
	free(res);
	return (1);
}
