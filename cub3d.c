/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umosse <umosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 13:23:00 by umosse            #+#    #+#             */
/*   Updated: 2024/10/15 15:30:07 by umosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// int	ft_destroy(t_game *game)
// {
// 	mlx_loop_end(game->mlx);
// 	return (1);
// }

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
	//ft_frames(game);
	//ft_movement(game);
	ft_clear_screen(game, 0);
	ft_topdown(game);
	//ft_raycasting();
	mlx_put_image_to_window(game->mlx, game->win, game->screen, 0, 0);
	return (0);
}

// int	ft_xpm_to_image(t_game *game)
// {
// 	int		width;
// 	int		height;

// 	return (0);
// }

int	main(int argc, char **argv)
{
	t_game	game;
	(void)argv;
	
	game = (t_game){0};
	if (argc == 2)
	{
		// if (!parsing)
		// {
		// 	write(2, "Error\n", 6);
		// 	ft_end(&game, 1);
		// 	return (1);
		// }
		game.mlx = mlx_init();
		if (!game.mlx)
			return (1);
		game.win = mlx_new_window(game.mlx, 960, 540, "cub3d");
		//ft_xpm_to_image(&game);
		game.screen = mlx_new_image(game.mlx, 960, 540);
		ft_hooks(&game);
	}
}