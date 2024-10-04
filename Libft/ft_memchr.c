/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umosse <umosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:41:14 by umosse            #+#    #+#             */
/*   Updated: 2023/11/14 17:30:30 by umosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_memchr(const void *str, int c, size_t n)
{
	size_t		i;
	const char	*ptr;

	i = 0;
	ptr = str;
	while (i < n)
	{
		if (ptr[i] == (char) c)
		{
			return ((void *)(ptr + i));
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
	char	b = 'z';

	printf("%s\n", strchr(str, b));
	printf("%s", ft_strchr(str, b));
	return (0);
}*/