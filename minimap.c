/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umosse <umosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:35:19 by aroualid          #+#    #+#             */
/*   Updated: 2024/12/09 14:11:16 by umosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_case (t_game *game, int x, int y, int color)
{
	int	x_max;
	int	y_max;
	int	i;
	int	j;

	i = 0;
	j = 0;
	x_max = x + 10;
	y_max = y + 10;
	
	while (i < x_max)
	{
		j = 0;
		while (j < y_max)
		{
			my_mlx_pixel_put(&game->data, i, j, color);
			j++;
		}
		i++;
	}
}

void	ft_minimap(t_game *game)
{
	int	i;
	int	j;

	i = W_LENGTH - 150;
	while (i < W_LENGTH)
	{
		j =  0;
		while (j < 150)
		{
			my_mlx_pixel_put(&game->data, i, j, 000000);
			j++;
		}
		i++;
	}
}
