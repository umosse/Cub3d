/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 11:24:49 by aroualid          #+#    #+#             */
/*   Updated: 2024/12/11 12:30:14 by aroualid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int	skip_space(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] && (s[i] == ' ' || (s[i] >= '\t' && s[i] <= '\r')))
		i++;
	return (i);
}

int	skip_space_reverse(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = ft_strlen(s)- 1;
	if (i <= 0)
		return (0);
	while (i >= 0 && s[i] && (s[i] == ' ' || (s[i] >= '\t' && s[i] <= '\r')))
		i--;
	return (i);
}

char	*fill_space(char *res, int k)
{
	int	j;

	j = 0;
	while (j < 4)
	{
		res[k] = ' ';
		j++;
		k++;
	}
	return (res);
}

char	*replace_tab_by_space(char *str)
{
	int		i;
	int		k;
	char	*res;

	res = ft_calloc(sizeof(char),
			(ft_strlen(str) + (count_symbol(str, '\t') * 4) + 1));
	i = 0;
	k = 0;
	while (str[i])
	{
		if (str[i] == '\t')
		{
			res = fill_space(res, k);
			k += 4;
		}
		else
		{
			res[k] = str[i];
			k++;
		}
		i++;
	}
	return (res);
}
