/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umosse <umosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:51:43 by umosse            #+#    #+#             */
/*   Updated: 2023/11/22 16:11:55 by umosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*cs1 = (const unsigned char *)s1;
	const unsigned char	*cs2 = (const unsigned char *)s2;

	i = 0;
	if (n == 0)
		return (0);
	while (cs1[i] == cs2[i] && i < n - 1)
	{
		i++;
	}
	return (cs1[i] - cs2[i]);
}
