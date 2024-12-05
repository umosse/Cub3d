/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 10:13:18 by aroualid          #+#    #+#             */
/*   Updated: 2024/12/05 10:13:32 by aroualid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_topdown(t_game *game)
{
	const int	s = W_LENGTH * W_HEIGHT;
	int			i;

	game->sky = game->parse->info->c;
	game->floor = game->parse->info->f;
	i = -1;
	while (++i < s)
	{
		while (i < (s / 2))
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
		if (game->map[game->mapy][game->mapx] == '1' ||
				game->map[game->mapy][game->mapx] == 'D')
			game->hit = 1;
	}
}

void	ft_raycasting(t_game *game)
{
	int	x;

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
		ft_drawtextures(game, x);
		x++;
	}
}
