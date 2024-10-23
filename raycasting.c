/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umosse <umosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 14:49:07 by umosse            #+#    #+#             */
/*   Updated: 2024/10/23 18:21:58 by umosse           ###   ########.fr       */
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
	const int	s = 960 * 540;
	int			i;
	

	game->sky = 0x00FF0000;
	game->floor = 0x0000FF00;
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
	printf("hit = %d\n", game->hit);
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
		if (game->map[game->mapy][game->mapx] > 0)
			game->hit = 1;
		printf("mapx = %d\n", game->mapx);
		printf("mapy = %d\n", game->mapy);
		printf("hit = %d\n", game->hit);
	}
}

void	ft_raycasting(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < 960)
	{
		game->camerax = 2 * x / 960.0 - 1;
		game->raydirx = game->dirx + game->planex * game->camerax;
		game->raydiry = game->diry + game->planey * game->camerax;
		game->mapx = (int)game->playerx;
		game->mapy = (int)game->playery;
		game->deltadistx = fabs(1 / game->raydirx);
		game->deltadisty = fabs(1 / game->raydiry);
		game->hit = 0;
		printf("raydirx = %f\n", game->raydirx);
		printf("playerx = %f\n", game->playerx);
		if (game->raydirx < 0)
		{
			game->stepx = -1;
			game->sidedistx = (game->playerx - game->mapx) * game->deltadistx;
		}
		else
		{
			game->stepx = 1;
			game->sidedistx = (game->mapx + 1.0 - game->playerx) * game->deltadistx;
		}
		if (game->raydiry < 0)
		{
			game->stepy = -1;
			game->sidedisty = (game->playery - game->mapy) * game->deltadisty;
		}
		else
		{
			game->stepy = 1;
			game->sidedisty = (game->mapy + 1.0 - game->playery) * game->deltadisty;
		}
		ft_dda(game);
		printf("sidedistx = %f\n", game->sidedistx);
		printf("deltadistx = %f\n", game->deltadistx);
		if (game->side == 0)
			game->perpwalldist = (game->sidedistx - game->deltadistx);
		else
			game->perpwalldist = (game->sidedisty - game->deltadisty);
		printf("perpwalldist = %f\n", game->perpwalldist);
		game->lineheight = (int)(W_HEIGHT / game->perpwalldist);
		printf("lineheight = %d\n", game->lineheight);
		game->drawstart = -1 * game->lineheight / 2 + W_HEIGHT / 2;
		if (game->drawstart < 0)
			game->drawstart = 0;
		printf("drawstart = %d\n", game->drawstart);
		game->drawend = game->lineheight / 2 + W_HEIGHT / 2;
		printf("drawend = %d\n", game->drawend);
		if (game->drawend >= W_HEIGHT)
			game->drawend = W_HEIGHT - 1;
		if (game->map[game->mapy][game->mapx] == '1')
			game->color = P_RED;
		if (game->side == 1)
			game->color = game->color / 2;
		y = game->drawstart;
		printf("y is = %d\n", y);
		while (y < game->drawend)
		{
			my_mlx_pixel_put(&game->data, x, y, P_CYAN);
			y++;
		}
		x++;
	}
}
