/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umosse <umosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:41:49 by umosse            #+#    #+#             */
/*   Updated: 2023/11/14 17:26:15 by umosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char *str, char to_find)
{
	size_t	i;

	i = 0;
	while (1)
	{
		if (to_find == '\0' && str[i] == '\0')
			return (&str[i]);
		else if (str[i] == '\0')
			break ;
		if (str[i] == to_find)
		{
			return (&str[i]);
		}
		i++;
	}
	return (NULL);
}

/*#include <stdio.h>
#include <bsd/string.h>

int	main(void)
{
	char	str[] = "vertbleublancrouge";
	char	b = 'z';

	printf("%s\n", strchr(str, b));
	printf("%s", ft_strchr(str, b));
	return (0);
}*/