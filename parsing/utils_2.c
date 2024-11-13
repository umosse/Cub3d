/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:17:22 by aroualid          #+#    #+#             */
/*   Updated: 2024/11/13 13:56:17 by aroualid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"parsing.h"

int	ft_atoi(const char *str)
{
	int				i;
	int				signe;
	unsigned int	resultat;

	i = 0;
	signe = 1;
	resultat = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n' || str[i] == '\r'
		|| str[i] == '\t' || str[i] == '\v')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			signe *= -1;
		}
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		resultat *= 10;
		resultat += str[i] - '0';
		i++;
	}
	return (resultat * signe);
}

int	count_symbol(char *str, char symbol)
{
	int	i;
	int	res;

	res = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == symbol)
			res++;
		i++;
	}
	return (res);
}
