/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umosse <umosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 15:44:01 by umosse            #+#    #+#             */
/*   Updated: 2024/10/24 18:04:49 by umosse           ###   ########.fr       */
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
	else if (keysym == 65307)
		ft_destroy(game);
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
	// ft_printf("Steps : %d\n", game->steps);
	return (0);
}

void	ft_movement(t_game *game)
{
	if (game->w == 1)
	{
		if (game->map[(int)(game->playerx + game->dirx * game->movespeed)][(int)game->playery] == false)
			game->playerx += game->dirx * game->movespeed;
		if (game->map[(int)game->playerx][(int)(game->playery + game->dirx * game->movespeed)] == false)
			game->playery += game->diry * game->movespeed;
	}
}
