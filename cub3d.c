/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umosse <umosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 13:23:00 by umosse            #+#    #+#             */
/*   Updated: 2024/10/30 15:35:00 by umosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_destroy(t_game *game)
{
	mlx_loop_end(game->mlx);
	return (1);
}

// void	ft_end(t_game *game, int j)
// {
// 	int	i;

// 	i = 0;
// 	if (game->map)
// 	{
// 		while (i < game->maxmapy)
// 			free(game->map[i++]);
// 		free(game->map);
// 	}
// 	i = 0;
// 	if (game->maptest)
// 	{
// 		while (i < game->maxmapy)
// 			free(game->maptest[i++]);
// 		free(game->maptest);
// 	}
// 	if (j == 0)
// 		ft_destroyall(game);
// 	if (game->mlx)
// 		free(game->mlx);
// }

int	ft_update(t_game *game)
{
	ft_clear_screen(game, 0);
	ft_topdown(game);
	ft_raycasting(game);
	mlx_put_image_to_window(game->mlx, game->win, game->data.img, 0, 0);
	return (0);
}

int	ft_xpm_to_image(t_game *game)
{
	int		width;
	int		height;

	game->t_north = mlx_xpm_file_to_image(game->mlx, T_NORTH, &width, &height);
	game->t_south = mlx_xpm_file_to_image(game->mlx, T_SOUTH, &width, &height);
	game->t_west = mlx_xpm_file_to_image(game->mlx, T_WEST, &width, &height);
	game->t_east = mlx_xpm_file_to_image(game->mlx, T_EAST, &width, &height);
	game->t_door = mlx_xpm_file_to_image(game->mlx, T_DOOR, &width, &height);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	(void)argv;
	game = (t_game){0};
	game.movespeed = 0.1;
	game.rotspeed = 0.05;
	game.dirx = 0;
	game.diry = 1;
	game.planex = 0.85;
	game.planey = 0;
	game.playerx = 15.5;
	game.playery = 4.5;
	if (argc == 2)
	{
		ft_mapread(argv[1], &game);
		game.mlx = mlx_init();
		if (!game.mlx)
			return (1);
		game.win = mlx_new_window(game.mlx, W_LENGTH, W_HEIGHT, "cub3d");
		ft_xpm_to_image(&game);
		game.data.img = mlx_new_image(game.mlx, W_LENGTH, W_HEIGHT);
		game.data.addr = mlx_get_data_addr(game.data.img,
				&game.data.bits_per_pixel,
				&game.data.line_length, &game.data.endian);
		ft_hooks(&game);
	}
}
