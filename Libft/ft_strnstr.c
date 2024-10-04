/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umosse <umosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:16:23 by umosse            #+#    #+#             */
/*   Updated: 2023/11/16 13:27:29 by umosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (to_find[0] == '\0')
		return ((char *)str);
	while (str[i] != '\0' && i < n)
	{
		j = 0;
		while (str[i + j] != '\0' && str[i + j] == to_find[j]
			&& n - i >= ft_strlen(to_find))
		{
			if (to_find[j + 1] == '\0')
			{
				return ((char *)&str[i]);
			}
			j++;
		}
		i++;
	}
	return (0);
}

/*#include <stdio.h>
#include <bsd/string.h>

int	main(void)
{
	char	str[] = "vertbleublancrouge";
	char	to_find[] = "bleu";
	int	n;
	
	n = 7;
	printf("%s\n", strnstr(str, to_find, n));
	printf("%s", ft_strnstr(str, to_find, n));
	return (0);
}*/