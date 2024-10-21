/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umosse <umosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 14:49:07 by umosse            #+#    #+#             */
/*   Updated: 2024/10/21 17:18:28 by umosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_topdown(t_game *game)
{
	const int	s = game->screen->width * game->screen->height;
	int			i;
	

	game->sky = 0x00FF0000;
	game->floor = 0x0000FF00;
	i = -1;
	while (++i < s)
	{
		while (i < s/2)
		{
			*(((unsigned int *)game->screen->data + i)) = game->sky;
			i++;
		}
		*(((unsigned int *)game->screen->data + i)) = game->floor;
	}
}

void	ft_dda(t_game *game)
{
	while (game->hit == 0)
	{
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
		if (game->map[game->mapx][game->mapy] > 0)
			game->hit = 1;
	}
}

void	ft_raycasting(t_game *game)
{
	int	x;

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
		if (game->side == 0)
			game->perpwalldist = (game->sidedisty - game->sidedistx);
		else
			game->perpwalldist = (game->sidedisty - game->sidedistx);
		game->lineheight = (int)(540 / game->perpwalldist);
		game->drawstart = -game->lineheight / 2 + 270;
		if (game->drawstart < 0)
			game->drawstart = 0;
		game->drawend = game->lineheight / 2 + 270;
		if (game->drawend >= 540)
			game->drawend = 539;
	}
}
