/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umosse <umosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:19:13 by umosse            #+#    #+#             */
/*   Updated: 2023/11/22 16:11:37 by umosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strncpy(char *dest, const char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src [i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static char	**ft_error(char **stock)
{
	int		i;

	i = 0;
	if (stock == 0)
		return (NULL);
	while (stock[i])
	{
		free (stock[i]);
		i++;
	}
	free(stock);
	return (NULL);
}

static int	ft_countwords(char *str, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (c == str[i])
		{
			i++;
			continue ;
		}
		count++;
		while (c != str[i] && str[i] != '\0')
			i++;
	}
	return (count);
}

static char	*ft_cpyword(const char *str, char c, int *len)
{
	const char	*start = str;
	char		*ptr;
	int			length;

	length = 0;
	while (*str && c != *str)
		str++;
	length = str - start;
	*len = length;
	ptr = ft_calloc(sizeof(char), length + 1);
	if (!ptr)
		return (NULL);
	ft_strncpy(ptr, start, length);
	return (ptr);
}

char	**ft_split(const char *str, char c)
{
	char	**stock;
	int		i;
	int		len;

	if (str == NULL)
		return (NULL);
	i = 0;
	stock = ft_calloc(sizeof(char *), (ft_countwords((char *)str, c) + 1));
	if (!stock)
		return (NULL);
	while (*str)
	{
		len = 1;
		if (c != *str)
		{
			stock[i] = ft_cpyword(str, c, &len);
			if (!stock[i])
				return (ft_error(stock));
			i++;
		}
		str += len;
	}
	return (stock);
}

/*int	main(void)
{
	char	**tab;
	char	charset = ' ';
	char	*str = "Le saint Lamasticot descendra pour purifier le monde";
	int		i;

	i = 0;
	tab = ft_split(str, charset);
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
	return (0);
}*/
