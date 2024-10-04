/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umosse <umosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:29:05 by umosse            #+#    #+#             */
/*   Updated: 2023/11/17 15:26:41 by umosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_swap(char *a, char *b)
{
	char	swap;

	swap = *a;
	*a = *b;
	*b = swap;
}

static void	ft_sort(char *tab)
{
	int	i;
	int	j;

	i = ft_strlen(tab) - 1;
	j = 0;
	if (tab[0] == '-')
		j++;
	while (j < i)
		ft_swap(&tab[i--], &tab[j++]);
}

static int	ft_calsize(int n)
{
	long	nbr;
	int		i;

	i = 0;
	nbr = n;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		nbr *= -1;
		i++;
	}
	while (nbr > 0)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*tab;
	int		i;
	long	nbr;

	nbr = n;
	tab = ft_calloc(1, ft_calsize(n) + 1);
	if (!tab)
		return (0);
	if (nbr == 0)
		tab[0] = '0';
	i = 0;
	if (nbr < 0)
	{
		tab[i++] = '-';
		nbr *= -1;
	}
	while (nbr > 0)
	{
		tab[i++] = nbr % 10 + '0';
		nbr /= 10;
	}
	ft_sort(tab);
	return (tab);
}
/*int	main(void)
{
	printf("%s", ft_itoa(12));
	return (0);
}*/