/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umosse <umosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:17:25 by umosse            #+#    #+#             */
/*   Updated: 2023/11/22 16:11:47 by umosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_memcpy(char *dest, const void *src, unsigned int n)
{
	unsigned int		i;
	const unsigned char	*ptr;

	i = 0;
	ptr = src;
	while (i < n)
	{
		dest[i] = ptr[i];
		i++;
	}
	return (dest);
}
