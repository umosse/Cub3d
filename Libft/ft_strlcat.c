/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umosse <umosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:03:05 by umosse            #+#    #+#             */
/*   Updated: 2023/11/22 16:25:00 by umosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, unsigned int size)
{
	size_t	sizedest;
	size_t	sizesrc;
	size_t	i;

	i = 0;
	sizedest = ft_strlen(dest);
	sizesrc = ft_strlen(src);
	if (size == 0 || sizedest > size)
	{
		return (sizesrc + size);
	}
	while (src[i] && (sizedest + i < size - 1))
	{
		dest[sizedest + i] = src[i];
		i++;
	}
	dest[sizedest + i] = '\0';
	return (sizedest + sizesrc);
}
