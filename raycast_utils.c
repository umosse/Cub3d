/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umosse <umosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:00:11 by umosse            #+#    #+#             */
/*   Updated: 2024/11/27 16:34:53 by aroualid         ###   ########.fr       */
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

void	ft_drawtextures(t_game *game, int x)
{
	int	y;

	if (game->side == 0)
		game->wallx = game->playery + game->perpwalldist * game->raydiry;
	else
		game->wallx = game->playerx + game->perpwalldist * game->raydirx;
	game->wallx -= floor(game->wallx);
	game->textx = (int)(game->wallx * (double)game->t_north->width);
	if (game->side == 0 && game->raydirx > 0)
		game->textx = game->t_north->width - game->textx - 1;
	if (game->side == 1 && game->raydiry < 0)
		game->textx = game->t_north->width - game->textx - 1;
	game->step = 1.0 * game->t_north->height / game->lineheight;
	game->textpos = (game->drawstart - W_HEIGHT / 2
			+ game->lineheight / 2) * game->step;
	y = game->drawstart;
	while (y <= game->drawend)
	{
		game->texty = (int)game->textpos & (game->t_north->height - 1);
		game->textpos += game->step;
		ft_colortextures(game);
		my_mlx_pixel_put(&game->data, x, y, game->color);
		y++;
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

void	ft_animdoor(t_game *game)
{
	if (game->map[game->mapy][game->mapx] == 'D' && game->framecount <= 15)
		game->color = ((unsigned int *)game->t_door->data)[game->t_door->width
			* game->texty + game->textx];
	else if (game->map[game->mapy][game->mapx] == 'D' && game->framecount <= 30)
		game->color = ((unsigned int *)game->t_door2->data)[game->t_door2->width
			* game->texty + game->textx];
	else if (game->map[game->mapy][game->mapx] == 'D' && game->framecount <= 45)
		game->color = ((unsigned int *)game->t_door3->data)[game->t_door3->width
			* game->texty + game->textx];
	else if (game->map[game->mapy][game->mapx] == 'D')
		game->color = ((unsigned int *)game->t_door4->data)[game->t_door4->width
			* game->texty + game->textx];
}

void	ft_colortextures(t_game *game)
{
	if (game->map[game->mapy][game->mapx] == 'D')
		ft_animdoor(game);
	else if (game->map[game->mapy][game->mapx] == '1')
	{
		if (game->side == 1 && game->raydiry > 0)
			game->color = ((unsigned int *)game->t_north->data)
			[game->t_north->width * game->texty + game->textx];
		if (game->side == 1 && game->raydiry <= 0)
			game->color = ((unsigned int *)game->t_south->data)
			[game->t_south->width * game->texty + game->textx];
		if (game->side == 0 && game->raydirx > 0)
			game->color = ((unsigned int *)game->t_west->data)
			[game->t_west->width * game->texty + game->textx];
		if (game->side == 0 && game->raydirx <= 0)
			game->color = ((unsigned int *)game->t_east->data)
			[game->t_east->width * game->texty + game->textx];
	}
}
