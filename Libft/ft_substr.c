/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umosse <umosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 08:44:54 by umosse            #+#    #+#             */
/*   Updated: 2023/11/15 16:59:27 by umosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;

	i = 0;
	if (str == 0)
		return (NULL);
	if (start > ft_strlen(str))
		return (ft_calloc(1, 1));
	if (len > (ft_strlen(str) - start))
		dest = ft_calloc(1, sizeof(char) * (ft_strlen(str) - start + 1));
	else
		dest = ft_calloc(1, sizeof(char) * (len + 1));
	if (!dest)
		return (0);
	while (str[start + i] != '\0' && i < len)
	{
		dest[i] = str[start + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/*#include <stdio.h>

int	main(void)
{
	char	str[] = "1";
	int	start;
	size_t	len;

	start = 0;
	len = 0;
	printf("%s\n", ft_substr(str, start, len));
	return (0);
}*/