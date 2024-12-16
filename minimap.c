/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 10:05:56 by aroualid          #+#    #+#             */
/*   Updated: 2024/12/16 13:41:40 by aroualid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_case(t_game *game, int x, int y, int color)
{
	int	x_max;
	int	y_max;
	int	x_print;
	int	y_print;

	x_print = x;
	y_print = y;
	x_max = x_print + 10;
	y_max = y_print + 10;
	if (y < 0 || y > 150 || x < W_LENGTH - 150 || x > W_LENGTH || (y_max < 0
			|| y_max > 150 || x_max < W_LENGTH - 150 || x_max > W_LENGTH))
		return ;
	while (y_print < y_max)
	{
		x_print = x;
		while (x_print < x_max)
		{
			my_mlx_pixel_put(&game->data, x_print, y_print, color);
			x_print++;
		}
		y_print++;
	}
}

static void	draw_dir(t_game *game, int color)
{
	int	x;
	int	y;
	int	i;

	x = W_LENGTH - 75;
	y = 75;
	i = 0;
	while (i < 15)
	{
		my_mlx_pixel_put(&game->data, x + i * game->dirx,
			y + i * game->diry, color);
		i++;
	}
}

void	minimap_utils(t_game *game, int player_x, int player_y, int x_min)
{
	int	y_min;
	int	y_max;
	int	map_x;
	int	map_y;

	y_min = player_y - 10;
	y_max = player_y + 10;
	while (y_min <= y_max)
	{
		if ((x_min >= 0 && x_min < game->parse->max_x)
			&& (y_min >= 0 && y_min < game->parse->max_y))
		{
			map_x = W_LENGTH - 150 + (75 - 5) + (x_min - player_x) * 10;
			map_y = (75 - 5) + (y_min - player_y) * 10;
			if (x_min == player_x && y_min == player_y)
				draw_case(game, map_x, map_y, 0x2fffff);
			else if (game->parse->map_square[y_min][x_min] == '1')
				draw_case(game, map_x, map_y, 0xbd1526);
			else if (game->parse->map_square[y_min][x_min] == 'D')
				draw_case(game, map_x, map_y, 0x7e22f0);
		}
		y_min++;
	}
}

void	ft_read_minimap(t_game *game)
{
	int	player_x;
	int	player_y;
	int	x_min;
	int	x_max;

	player_x = game->playerx;
	player_y = game->playery;
	x_min = player_x - 10;
	x_max = player_x + 10;
	while (x_min <= x_max)
	{
		minimap_utils(game, player_x, player_y, x_min);
		x_min++;
	}
	draw_dir(game, 0x2fffff);
}

void	ft_minimap(t_game *game)
{
	int	y;
	int	x;

	y = W_LENGTH - 150;
	while (y < W_LENGTH)
	{
		x = 0;
		while (x < 150)
		{
			my_mlx_pixel_put(&game->data, y, x, 000000);
			x++;
		}
		y++;
	}
	ft_read_minimap(game);
}
