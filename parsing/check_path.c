/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:51:13 by aroualid          #+#    #+#             */
/*   Updated: 2024/11/13 13:48:37 by aroualid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char	*new_string(char *str, int taille)
{
	char	*res;
	int		k;

	res = ft_calloc(sizeof(char *), ft_strlen(str));
	k = 0;
	while (taille < ft_strlen(str))
	{
		res[k] = str[taille];
		k++;
		taille++;
	}
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
		return (printf("Error\ntoo many NO \n"), 0);
	res = new_string(str, 2);
	parse->info->no_ok = 1;
	i = skip_space(res);
	j = i;
	parse->info->no_path = ft_calloc(sizeof(char *), ft_strlen(res));
	while (k < ft_strlen(res))
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
		return (printf("Error\ntoo many SO \n"), 0);
	res = new_string(str, 2);
	parse->info->so_ok = 1;
	i = skip_space(res);
	j = i;
	parse->info->so_path = ft_calloc(sizeof(char *), ft_strlen(res));
	while (k < ft_strlen(res))
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
		return (printf("Error\ntoo many WE \n"), 0);
	res = new_string(str, 2);
	parse->info->we_ok = 1;
	i = skip_space(res);
	j = i;
	parse->info->we_path = ft_calloc(sizeof(char *), ft_strlen(res));
	while (k < ft_strlen(res))
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
		return (printf("Error\ntoo many EA \n"), 0);
	res = new_string(str, 2);
	parse->info->ea_ok = 1;
	i = skip_space(res);
	j = i;
	parse->info->ea_path = ft_calloc(sizeof(char *), ft_strlen(res));
	while (k < ft_strlen(res))
	{
		parse->info->ea_path[k] = res[j];
		k++;
		j++;
	}
	free(res);
	return (1);
}
