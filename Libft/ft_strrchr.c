/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umosse <umosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:41:31 by umosse            #+#    #+#             */
/*   Updated: 2023/11/15 13:32:40 by umosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int n)
{
	size_t	i;

	i = ft_strlen(str) + 1;
	while (i > 0)
	{
		if (str[i - 1] == (unsigned char)n)
		{
			return ((char *)&str[i - 1]);
		}
		i--;
	}
	return (0);
}

/*#include <stdio.h>
#include <bsd/string.h>

int	main(void)
{
	char	str[] = "vertbleublancrouge";
	char	b = 98;

	printf("%s\n", strrchr(str, b));
	printf("%s", ft_strrchr(str, b));
	return (0);
}*/