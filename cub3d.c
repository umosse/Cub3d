/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umosse <umosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 13:23:00 by umosse            #+#    #+#             */
/*   Updated: 2024/11/20 13:33:22 by aroualid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parsing/parsing.h"

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
	ft_movement(game);
	ft_frames(game);
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

	load_no(game, game->parse);
	load_so(game, game->parse);
	load_we(game, game->parse);
	load_ea(game, game->parse);
	game->t_door = mlx_xpm_file_to_image(game->mlx, T_DOOR, &width, &height);
	game->t_door = mlx_xpm_file_to_image(game->mlx, T_DOOR, &width, &height);
	game->t_door = mlx_xpm_file_to_image(game->mlx, T_DOOR, &width, &height);
	game->t_door = mlx_xpm_file_to_image(game->mlx, T_DOOR, &width, &height);
	game->t_door2 = mlx_xpm_file_to_image(game->mlx, T_DOOR2, &width, &height);
	game->t_door3 = mlx_xpm_file_to_image(game->mlx, T_DOOR3, &width, &height);
	game->t_door4 = mlx_xpm_file_to_image(game->mlx, T_DOOR4, &width, &height);
	return (0);
}

void	ft_setup(t_game *game)
{
	game->movespeed = 0.01;
	game->rotspeed = 0.005;
	game->dirx = 0;
	game->diry = 1;
	game->planex = 0.85;
	game->planey = 0;
	game->playerx = game->parse->player_x + 0.5;
	game->playery = game->parse->player_y + 0.5;
}

int	main(int ac, char **av)
{
	int		fd;
	t_game	game;
	
	game = (t_game){0};
	game.parse = ft_calloc(sizeof(t_parse), 1);
	game.parse->info = ft_calloc(sizeof(t_info), 1);
	if (ac == 2)
	{
		if (check_file(av[1]) == 1)
		{
			game.parse->lines = ft_calloc(sizeof(char **), get_line(av[1]));
			fd = open(av[1], O_RDONLY);
			if (parse_args(game.parse, fd, av) == 0)
			{
				close(fd);
				return (0);
			}
			ft_setup(&game);
			close (fd);
			ft_mapread(av[1], &game);
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
		else
		{
			printf("Error \nWrong file\n");
			return  (0);
		}
	}
	else
	{
		printf("Error \nWrong number of arg\n");
		return (0);
	}
	return (1);
}
