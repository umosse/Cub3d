/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 10:05:56 by aroualid          #+#    #+#             */
/*   Updated: 2024/12/05 12:49:46 by aroualid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_case (t_game *game, int x, int y, int color)
{
	int	x_max;
	int	y_max;
	int	x_print;
	int	y_print;

	x_print = x;
	y_print = y;
	x_max = x_print + 10;
	y_max = y_print + 10;

	if (y < 0 || y > 150 || x < W_LENGTH - 150 || x > W_LENGTH || (y_max < 0 || y_max > 150 || x_max < W_LENGTH - 150 || x_max > W_LENGTH))
	{
		return;
	}

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

static void draw_dir(t_game *game, int color)
{
	int x;
	int y;
	int	i;

	(void) color;
	x = W_LENGTH - 75;
	y = 75;
	i = 0;
	while (i < 15)
	{
		my_mlx_pixel_put(&game->data, x + i * game->diry, y + i * game->dirx, color);
		i++;
	}
}

void	ft_read_minimap(t_game *game)
{
	int	x;
	int	y;
	
	x = game->playerx;
	y = game->playery;
	int	y_min = y - 10;
	int	y_max = y + 10;
	while (y_min <= y_max)
	{
		int	x_min = x - 10;
		int	x_max = x + 10;
		while (x_min <= x_max)
		{
			if ((x_min >= 0 && x_min <= game->parse->max_x) && (y_min >= 0 && y_min <= game->parse->max_y))
			{
				if (x_min == x && y_min == y)
				{
					draw_case(game, W_LENGTH - 75 - 5, 75 - 5, 0x2fffff);
				}
				else if (game->map[y_min][x_min] == '1')
					draw_case(game, W_LENGTH - 150 + y_min * 10 - y * 10 + 75 - 5, x_min * 10 - x * 10 + 75 - 5, 0xbd1526);
				else if (game->map[y_min][x_min] == 'D')
					draw_case(game, W_LENGTH - 150 + y_min * 10 - y * 10 + 75 - 5, x_min * 10 - x * 10 + 75 - 5, 0x7e22f0);
			}

			x_min++;
		}
		y_min++;
	}
	draw_dir(game, 0x2fffff);
}
	//while (if (game->map[x][y + 1] == '1' && game->map[x][y + 1] != ' ')
	//{
	//	printf("A\n");
	//	draw_case (game, 20, 20, 0Xfffff);
	//}


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
