/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umosse <umosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:50:14 by umosse            #+#    #+#             */
/*   Updated: 2023/11/24 15:46:40 by umosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strtrim1(char const *s1, char const *set)
{
	size_t	k;
	size_t	j;
	size_t	old_i;

	k = ft_strlen(s1) - 1;
	j = 0;
	old_i = k;
	while (s1[k])
	{
		while ((s1[k] != set[j]) && set[j] != '\0')
			j++;
		if (s1[k] == set[j])
		{
			k--;
			j = 0;
		}
		else
		{
			old_i = old_i - k;
			break ;
		}
	}
	return (old_i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s1 == 0 || set == NULL)
		return (NULL);
	while (s1[i])
	{
		while ((s1[i] != set[j]) && set[j] != '\0')
			j++;
		if (s1[i] == set[j])
		{
			i++;
			j = 0;
		}
		else
			break ;
	}
	return (ft_substr(s1, i,
			(ft_strlen(s1) - i - ft_strtrim1(s1, set))));
}
/*#include <stdio.h>
#include <bsd/string.h>

int	main(void)
{
	char	str[] = "tripouille   xxx";
	char	to_find[] = " x";
	char	*join;

	join = ft_strtrim("tripouille   xxx", " x");
	printf("%d", !strcmp(join, "tripouille"));
	free(join);
	return (0);
}*/