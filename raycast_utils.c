/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umosse <umosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:00:11 by umosse            #+#    #+#             */
/*   Updated: 2024/10/28 13:09:02 by umosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_raycast_calcs(t_game *game)
{
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
}

void	ft_drawsize(t_game *game)
{
	if (game->side == 0)
		game->perpwalldist = (game->sidedistx - game->deltadistx);
	else
		game->perpwalldist = (game->sidedisty - game->deltadisty);
	game->lineheight = (int)(W_HEIGHT / game->perpwalldist);
	game->drawstart = -1 * game->lineheight / 2 + W_HEIGHT / 2;
	if (game->drawstart < 0)
		game->drawstart = 0;
	game->drawend = game->lineheight / 2 + W_HEIGHT / 2;
	if (game->drawend >= W_HEIGHT)
		game->drawend = W_HEIGHT - 1;
}

void	ft_drawcolor(t_game *game)
{
	if (game->map[game->mapy][game->mapx] == '1')
	{
		if (game->side == 1 && game->raydiry > 0) //north
			game->color = P_BLACK;
		if (game->side == 1 && game->raydiry <= 0) //south
			game->color = P_MAGENTA;
		if (game->side == 0 && game->raydirx > 0) //west
			game->color = P_YELLOW;
		if (game->side == 0 && game->raydirx <= 0) //east
			game->color = P_BLUE;
	}
}
