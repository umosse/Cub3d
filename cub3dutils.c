/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3dutils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umosse <umosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 13:28:29 by umosse            #+#    #+#             */
/*   Updated: 2024/12/09 14:02:28 by umosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_setup_e(t_game *game)
{
	if (game->parse->orientation == 'E')
	{
		game->olddirx = game->dirx;
		game->dirx = game->dirx * cos(-1 * M_PI / 2)
			- game->diry * sin(-1 * M_PI / 2);
		game->diry = game->olddirx * sin(-1 * M_PI / 2)
			+ game->diry * cos(-1 * M_PI / 2);
		game->oldplanex = game->planex;
		game->planex = game->planex * cos(-1 * M_PI / 2)
			- game->planey * sin(-1 * M_PI / 2);
		game->planey = game->oldplanex * sin(-1 * M_PI / 2)
			+ game->planey * cos(-1 * M_PI / 2);
	}
}

void	ft_setup_w(t_game *game)
{
	if (game->parse->orientation == 'W')
	{
		game->olddirx = game->dirx;
		game->dirx = game->dirx * cos(-1 * 3 * M_PI / 2)
			- game->diry * sin(-1 * 3 * M_PI / 2);
		game->diry = game->olddirx * sin(-1 * 3 * M_PI / 2)
			+ game->diry * cos(-1 * 3 * M_PI / 2);
		game->oldplanex = game->planex;
		game->planex = game->planex * cos(-1 * 3 * M_PI / 2)
			- game->planey * sin(-1 * 3 * M_PI / 2);
		game->planey = game->oldplanex * sin(-1 * 3 * M_PI / 2)
			+ game->planey * cos(-1 * 3 * M_PI / 2);
	}
}

void	ft_frames(t_game *game)
{
	game->framecount++;
	if (game->framecount > 60)
		game->framecount = 0;
}

void	ft_hooks(t_game *game)
{
	mlx_hook(game->win, KeyPress, KeyPressMask, &ft_key_pressed, game);
	mlx_hook(game->win, DestroyNotify, StructureNotifyMask, &ft_destroy, game);
	mlx_loop_hook(game->mlx, ft_update, game);
	mlx_hook(game->win, KeyRelease, KeyReleaseMask, &ft_key_released, game);
	mlx_loop(game->mlx);
}

void	ft_clear_screen(t_game *game, unsigned int color)
{
	const int	s = W_LENGTH * W_HEIGHT;
	int			i;

	i = -1;
	while (++i < s)
		*(((unsigned int *)game->data.addr + i)) = color;
}
