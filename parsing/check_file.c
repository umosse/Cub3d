/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:51:10 by aroualid          #+#    #+#             */
/*   Updated: 2024/11/13 16:00:56 by aroualid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	extension(char *av)
{
	int	i;

	i = ft_strlen(av);
	if (i > 4)
	{
		if (ft_strncmp(av + i - 4, ".cub", 4) != 0)
			return (0);
		else
		{
			if (av[i - 5] == '/')
				return (0);
			return (1);
		}
		return (1);
	}
	else if (i <= 4)
		return (0);
	return (0);
}

int	check_file(char *av)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (extension (av) == 1)
	{
		i = open(av, O_RDONLY);
		j = open(av, O_DIRECTORY);
		if (i != -1 && j == -1)
			return (1);
		else
			return (0);
	}
	else
		return (0);
}
