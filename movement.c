/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umosse <umosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 15:44:01 by umosse            #+#    #+#             */
/*   Updated: 2024/11/28 11:51:16 by umosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_lateral(t_game *game)
{
	if (game->a == 1)
	{
		if (game->map[(int)game->playery][(int)(game->playerx - game->diry
			* game->movespeed)] == '0' ||
				game->map[(int)game->playery][(int)(game->playerx - game->diry
				* game->movespeed)] == 'O')
			game->playerx -= game->diry * game->movespeed;
		if (game->map[(int)(game->playery + game->dirx
				* game->movespeed)][(int)game->playerx] == '0' ||
				game->map[(int)(game->playery + game->dirx
				* game->movespeed)][(int)game->playerx] == 'O')
			game->playery += game->dirx * game->movespeed;
	}
	if (game->d == 1)
	{
		if (game->map[(int)game->playery][(int)(game->playerx + game->diry
			* game->movespeed)] == '0')
			game->playerx += game->diry * game->movespeed;
		if (game->map[(int)(game->playery - game->dirx
				* game->movespeed)][(int)game->playerx] == '0')
			game->playery -= game->dirx * game->movespeed;
	}
}

void	ft_rotate(t_game *game)
{
	if (game->r == 1)
	{
		game->olddirx = game->dirx;
		game->dirx = game->dirx * cos(-1 * game->rotspeed)
			- game->diry * sin(-1 * game->rotspeed);
		game->diry = game->olddirx * sin(-1 * game->rotspeed)
			+ game->diry * cos(-1 * game->rotspeed);
		game->oldplanex = game->planex;
		game->planex = game->planex * cos(-1 * game->rotspeed)
			- game->planey * sin(-1 * game->rotspeed);
		game->planey = game->oldplanex * sin(-1 * game->rotspeed)
			+ game->planey * cos(-1 * game->rotspeed);
	}
	if (game->l == 1)
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

void	ft_door(t_game *game)
{
	if (game->e == 1)
	{
		if (game->map[(int)game->playery][(int)(game->playerx
			+ game->dirx * game->movespeed * 90)] == 'D')
			game->map[(int)game->playery][(int)(game->playerx
					+ game->dirx * game->movespeed * 90)] = 'O';
		else if (game->map[(int)(game->playery + game->diry
				* game->movespeed * 90)][(int)game->playerx] == 'D')
			game->map[(int)(game->playery + game->diry
					* game->movespeed * 90)][(int)game->playerx] = 'O';
		else if (game->map[(int)game->playery][(int)(game->playerx
			+ game->dirx * game->movespeed * 90)] == 'O')
			game->map[(int)game->playery][(int)(game->playerx
					+ game->dirx * game->movespeed * 90)] = 'D';
		else if (game->map[(int)(game->playery + game->diry
				* game->movespeed * 90)][(int)game->playerx] == 'O')
			game->map[(int)(game->playery + game->diry
					* game->movespeed * 90)][(int)game->playerx] = 'D';
	}
}

void	ft_movement2(t_game *game)
{
	if (game->s == 1)
	{
		if (game->map[(int)game->playery][(int)(game->playerx
			- game->dirx * game->movespeed - 0.1)] == '0' ||
				game->map[(int)game->playery][(int)(game->playerx
				- game->dirx * game->movespeed - 0.1)] == 'O')
			game->playerx -= game->dirx * game->movespeed;
		if (game->map[(int)(game->playery - game->diry
				* game->movespeed)][(int)game->playerx] == '0' ||
				game->map[(int)(game->playery - game->dirx
					* game->movespeed - 0.1)][(int)game->playerx] == 'O')
			game->playery -= game->diry * game->movespeed;
	}
}

void	ft_movement(t_game *game)
{
	if (game->mouse == 1)
	{
		if (game->framecount <= 59)
		ft_mouse(game);
	}
	if (game->w == 1)
	{
		if (game->map[(int)game->playery][(int)(game->playerx
			+ game->dirx * game->movespeed + 0.1)] == '0' ||
				game->map[(int)game->playery][(int)(game->playerx
					+ game->dirx * game->movespeed  + 0.1)] == 'O')
			game->playerx += game->dirx * game->movespeed;
		if (game->map[(int)(game->playery + game->diry
				* game->movespeed + 0.1)][(int)game->playerx] == '0' ||
				game->map[(int)(game->playery + game->diry
					* game->movespeed + 0.1)][(int)game->playerx] == 'O')
			game->playery += game->diry * game->movespeed;
	}
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
