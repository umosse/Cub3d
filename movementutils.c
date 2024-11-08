/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movementutils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umosse <umosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:16:15 by umosse            #+#    #+#             */
/*   Updated: 2024/11/08 15:13:18 by umosse           ###   ########.fr       */
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
	else if (keysym == 'e')
		game->e = 1;
	else if (keysym == XK_Escape)
		ft_destroy(game);
	else if (keysym == ' ' && game->mouse == 1)
		game->mouse = 0;
	else if (keysym == ' ')
		game->mouse = 1;
	ft_door(game);
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
	else if (keysym == 'e')
		game->e = 0;
	return (0);
}

void	ft_mouse(t_game *game)
{
	mlx_mouse_get_pos(game->mlx, game->win, &game->mousex, &game->mousey);
	if (game->mousex < W_LENGTH / 2)
		game->l = 1;
	if (game->mousex > W_LENGTH / 2)
		game->r = 1;
}
