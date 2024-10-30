/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umosse <umosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 15:44:01 by umosse            #+#    #+#             */
/*   Updated: 2024/10/30 23:08:59 by umosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_key_pressed(int keysym, t_game *game)
{
	if (keysym == 'w')
		game->w = 1;
	else if (keysym == 's')
		game->s = 1;
	else if (keysym == 'a')
		game->a = 1;
	else if (keysym == 'd')
		game->d = 1;
	else if (keysym == XK_Right)
		game->r = 1;
	else if (keysym == XK_Left)
		game->l = 1;
	else if (keysym == XK_Escape)
		ft_destroy(game);
	ft_movement(game);
	return (0);
}

int	ft_key_released(int keysym, t_game *game)
{
	if (keysym == 'w')
		game->w = 0;
	else if (keysym == 's')
		game->s = 0;
	else if (keysym == 'a')
		game->a = 0;
	else if (keysym == 'd')
		game->d = 0;
	else if (keysym == XK_Right)
		game->r = 0;
	else if (keysym == XK_Left)
		game->l = 0;
	return (0);
}

void	ft_rotate(t_game *game)
{
	if (game->r == 1)
	{
		game->olddirx = game->dirx;
		game->dirx = game->dirx * cos(-1 * game->rotspeed) - game->diry * sin(-1 * game->rotspeed);
		game->diry = game->olddirx * sin(-1 * game->rotspeed) + game->diry * cos(-1 * game->rotspeed);
		game->oldplanex = game->planex;
		game->planex = game->planex * cos(-1 * game->rotspeed) - game->planey * sin(-1 * game->rotspeed);
		game->planey = game->oldplanex * sin(-1 * game->rotspeed) + game->planey * cos(-1 * game->rotspeed);
	}
	if (game->l == 1)
	{
		game->olddirx = game->dirx;
		game->dirx = game->dirx * cos(game->rotspeed) - game->diry * sin(game->rotspeed);
		game->diry = game->olddirx * sin(game->rotspeed) + game->diry * cos(game->rotspeed);
		game->oldplanex = game->planex;
		game->planex = game->planex * cos(game->rotspeed) - game->planey * sin(game->rotspeed);
		game->planey = game->oldplanex * sin(game->rotspeed) + game->planey * cos(game->rotspeed);
	}
}

void	ft_movement(t_game *game)
{
	if (game->w == 1)
	{
		if (game->map[(int)game->playery][(int)(game->playerx + game->dirx * game->movespeed)] == '0')
			game->playerx += game->dirx * game->movespeed;
		if (game->map[(int)(game->playery + game->diry * game->movespeed)][(int)game->playerx] == '0')
			game->playery += game->diry * game->movespeed;
	}
	if (game->s == 1)
	{
		if (game->map[(int)game->playery][(int)(game->playerx - game->dirx * game->movespeed)] == '0')
			game->playerx -= game->dirx * game->movespeed;
		if (game->map[(int)(game->playery - game->dirx * game->movespeed)][(int)game->playerx] == '0')
			game->playery -= game->diry * game->movespeed;
	}
	if (game->a == 1)
	{
		if (game->map[(int)game->playery][(int)(game->playerx - game->diry * game->movespeed)] == '0')
			game->playerx -= game->diry * game->movespeed;
		if (game->map[(int)(game->playery + game->dirx * game->movespeed)][(int)game->playerx] == '0')
			game->playery += game->dirx * game->movespeed;
	}
	if (game->d == 1)
	{
		if (game->map[(int)game->playery][(int)(game->playerx + game->diry * game->movespeed)] == '0')
			game->playerx += game->diry * game->movespeed;
		if (game->map[(int)(game->playery - game->dirx * game->movespeed)][(int)game->playerx] == '0')
			game->playery -= game->dirx * game->movespeed;
	}
	ft_rotate(game);
}
