/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umosse <umosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 13:23:00 by umosse            #+#    #+#             */
/*   Updated: 2024/10/04 15:56:56 by umosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_destroy(t_game *game)
{
	mlx_loop_end(game->mlx);
	return (1);
}

void	ft_end(t_game *game, int j)
{
	int	i;

	i = 0;
	if (game->map)
	{
		while (i < game->maxmapy)
			free(game->map[i++]);
		free(game->map);
	}
	i = 0;
	if (game->maptest)
	{
		while (i < game->maxmapy)
			free(game->maptest[i++]);
		free(game->maptest);
	}
	if (j == 0)
		ft_destroyall(game);
	if (game->mlx)
		free(game->mlx);
}

int	ft_update(t_game *game)
{
	char	*charsteps;

	ft_frames(game);
	ft_movement(game);
	clear_screen(game, 0);
	ft_raycasting();
	if (game->dead == 0)
	{
		if (game->framecount < 31)
			draw_spritec(game, game->character, game->flipped);
		else
			draw_spritec(game, game->character2, game->flipped);
	}
	else
	{
		if (ft_isdead(game) == 1)
			ft_destroy(game);
	}
	mlx_put_image_to_window(game->mlx, game->win, game->screen, 0, 0);
	charsteps = ft_itoa(game->steps);
	mlx_string_put(game->mlx, game->win, 32, 32, 0xFFFFFFFF, charsteps);
	free(charsteps);
	return (0);
}

int	ft_xpm_to_image(t_game *game)
{
	int		width;
	int		height;

	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	game = (t_game){0};
	if (argc == 2)
	{
		if (!parsing)
		{
			write(2, "Error\n", 6);
			ft_end(&game, 1);
			return (1);
		}
		game.mlx = mlx_init();
		if (!game.mlx)
			return (1);
		game.win = mlx_new_window(game.mlx, 960, 540, "cub3d");
		ft_xpm_to_image(&game);
		game.screen = mlx_new_image(game.mlx, 960, 540);
		ft_hooks(&game);
	}
}