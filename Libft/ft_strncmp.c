/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umosse <umosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:04:15 by umosse            #+#    #+#             */
/*   Updated: 2023/11/22 16:11:00 by umosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int		i;
	const unsigned char	*cs1 = (const unsigned char *)s1;
	const unsigned char	*cs2 = (const unsigned char *)s2;

	i = 0;
	if (n == 0)
		return (0);
	while (cs1[i] && cs1[i] == cs2[i] && i < n - 1)
	{
		i++;
	}
	return (cs1[i] - cs2[i]);
}
