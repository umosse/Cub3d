/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movementutils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umosse <umosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:04:54 by umosse            #+#    #+#             */
/*   Updated: 2024/12/09 14:50:54 by aroualid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_movement_p2(t_game *game)
{
	ft_movement2(game);
	ft_lateral(game);
	ft_rotate(game);
	if (game->mouse == 1 && game->framecount == 60)
	{
		mlx_mouse_move(game->mlx, game->win, W_LENGTH / 2, W_HEIGHT / 2);
		game->l = 0;
		game->r = 0;
	}
}

void	ft_lateral_a(t_game *game)
{
	if (game->a == 1)
	{
		if (game->map[(int)game->playery][(int)(game->playerx + game->diry
			* game->movespeed * 10)] == '0' ||
				game->map[(int)game->playery][(int)(game->playerx + game->diry
				* game->movespeed * 10)] == 'O')
			game->playerx += game->diry * game->movespeed;
		if (game->map[(int)(game->playery - game->dirx
				* game->movespeed * 10)][(int)game->playerx] == '0' ||
				game->map[(int)(game->playery - game->dirx
				* game->movespeed * 10)][(int)game->playerx] == 'O')
			game->playery -= game->dirx * game->movespeed;
	}
}

void	ft_rotate_r(t_game *game)
{
	if (game->r == 1)
	{
		game->olddirx = game->dirx;
		game->dirx = game->dirx * cos(game->rotspeed)
			- game->diry * sin(game->rotspeed);
		game->diry = game->olddirx * sin(game->rotspeed)
			+ game->diry * cos(game->rotspeed);
		game->oldplanex = game->planex;
		game->planex = game->planex * cos(game->rotspeed)
			- game->planey * sin(game->rotspeed);
		game->planey = game->oldplanex * sin(game->rotspeed)
			+ game->planey * cos(game->rotspeed);
	}
}
