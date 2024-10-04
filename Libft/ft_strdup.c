/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umosse <umosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:50:05 by umosse            #+#    #+#             */
/*   Updated: 2024/01/26 16:20:47 by umosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	size_t	i;
	char	*dest;

	i = 0;
	dest = (char *)ft_calloc(sizeof(char), (ft_strlen(src) + 1));
	if (!dest)
		return (NULL);
	while (i < ft_strlen(src))
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}
