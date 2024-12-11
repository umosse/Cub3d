/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:26:22 by aroualid          #+#    #+#             */
/*   Updated: 2024/12/11 13:38:26 by aroualid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parsing/parsing.h"

int	ft_destroy(t_game *game)
{
	mlx_loop_end(game->mlx);
	return (1);
}

int	ft_update(t_game *game)
{
	ft_movement(game);
	ft_frames(game);
	ft_clear_screen(game, 0);
	ft_topdown(game);
	ft_raycasting(game);
	ft_minimap(game);
	mlx_put_image_to_window(game->mlx, game->win, game->data.img, 0, 0);
	return (0);
}

void	ft_setup(t_game *game)
{
	game->movespeed = 0.01;
	game->rotspeed = 0.005;
	game->dirx = 0;
	game->diry = -1;
	game->planex = 0.85;
	game->planey = 0;
	game->playerx = game->parse->player_x + 0.5;
	game->playery = game->parse->player_y + 0.5;
	if (game->parse->orientation == 'S')
	{
		game->olddirx = game->dirx;
		game->dirx = game->dirx * cos(-1 * M_PI)
			- game->diry * sin(-1 * M_PI);
		game->diry = game->olddirx * sin(-1 * M_PI)
			+ game->diry * cos(-1 * M_PI);
		game->oldplanex = game->planex;
		game->planex = game->planex * cos(-1 * M_PI)
			- game->planey * sin(-1 * M_PI);
		game->planey = game->oldplanex * sin(-1 * M_PI)
			+ game->planey * cos(-1 * M_PI);
	}
	ft_setup_e(game);
	ft_setup_w(game);
}

void	start_game(t_game game, char **av)
{
	game.parse->av = ft_strdup(av[1]);
	game.parse->lines = ft_calloc(sizeof(char **), get_line(av[1]));
	game.parse->fd = open(av[1], O_RDONLY);
	if (game.parse->fd == -1)
		free_game(&game, game.parse, 1, "Error\nWrong File 2\n");
	if (parse_args(game.parse, game.parse->fd, av) == 0)
	{
		free_game(&game, game.parse, 1, "Error\nMap Invalid\n");
		if (game.parse->fd != -1)
			close(game.parse->fd);
	}
	ft_setup(&game);
	close (game.parse->fd);
	ft_mapread(av[1], &game);
	game.mlx = mlx_init();
	if (!game.mlx)
		free_and_exit(game.parse, 1, "Error\nInvalid Mlx pointer\n");
	ft_xpm_to_image(&game);
	game.win = mlx_new_window(game.mlx, W_LENGTH, W_HEIGHT, "cub3d");
	game.data.img = mlx_new_image(game.mlx, W_LENGTH, W_HEIGHT);
	game.data.addr = mlx_get_data_addr(game.data.img,
			&game.data.bits_per_pixel,
			&game.data.line_length, &game.data.endian);
	ft_hooks(&game);
	free_game(&game, game.parse, 0, "");
}

int	main(int ac, char **av)
{
	t_game	game;

	game = (t_game){0};
	game.parse = ft_calloc(sizeof(t_parse), 1);
	game.parse->info = ft_calloc(sizeof(t_info), 1);
	if (ac == 2)
	{
		if (check_file(av[1]) == 1)
			start_game(game, av);
		else
			free_and_exit(game.parse, 1, "Error \nWrong file\n");
	}
	else
		free_and_exit(game.parse, 1, "Error \nWrong number of arg\n");
	return (1);
}
