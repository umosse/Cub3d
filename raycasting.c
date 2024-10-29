/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umosse <umosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 14:49:07 by umosse            #+#    #+#             */
/*   Updated: 2024/10/29 17:15:30 by umosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	ft_topdown(t_game *game)
{
	const int	s = W_LENGTH * W_HEIGHT;
	int			i;
	

	game->sky = P_CYAN;
	game->floor = P_GREEN;
	i = -1;
	while (++i < s)
	{
		while (i < s/2)
		{
			*(((unsigned int *)game->data.addr + i)) = game->sky;
			i++;
		}
		*(((unsigned int *)game->data.addr + i)) = game->floor;
	}
}

void	ft_dda(t_game *game)
{
	while (game->hit == 0)
	{
		if (game->mapx < 0 || game->mapx > W_LENGTH || game->mapy < 0 || game->mapy > W_HEIGHT)
			break ;
		if (game->sidedistx < game->sidedisty)
		{
			game->sidedistx += game->deltadistx;
			game->mapx += game->stepx;
			game->side = 0;
		}
		else
		{
			game->sidedisty += game->deltadisty;
			game->mapy += game->stepy;
			game->side = 1;
		}
		if (game->map[game->mapy][game->mapx] > '0')
			game->hit = 1;
	}
}

void	ft_raycasting(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < W_LENGTH)
	{
		game->camerax = 2 * x / (double)W_LENGTH - 1;
		game->raydirx = game->dirx + game->planex * game->camerax;
		game->raydiry = game->diry + game->planey * game->camerax;
		game->mapx = (int)game->playerx;
		game->mapy = (int)game->playery;
		game->deltadistx = fabs(1 / game->raydirx);
		game->deltadisty = fabs(1 / game->raydiry);
		game->hit = 0;
		
		ft_raycast_calcs(game);
		ft_dda(game);
		ft_drawsize(game);
		//ft_drawcolor(game);
		// y = game->drawstart;
		// while (y < game->drawend)
		// {
		// 	my_mlx_pixel_put(&game->data, x, y, game->color);
		// 	y++;
		// }

		game->textnum = game->map[game->mapy][game->mapx];
		if (game->side == 0)
			game->wallx = game->playery + game->perpwalldist * game->raydiry;
		else
			game->wallx = game->playerx + game->perpwalldist * game->raydirx;
		game->wallx = floor(game->wallx);
		game->textx = (int)(game->wallx * (double)textwidth);
		if (game->side == 0 && game->raydirx > 0)
			game->textx = textwidth - game->textx - 1;
		if (game->side == 1 && game->raydiry < 0)
			game->textx = textwidth - game->textx - 1;
		game->step = 1.0 * textheight / game->lineheight;
		x++;
	}
}
