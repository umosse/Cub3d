/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3dutils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:12:24 by aroualid          #+#    #+#             */
/*   Updated: 2024/12/11 14:02:31 by aroualid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	load_door(t_game *game)
{
	int		width;
	int		height;

	game->t_door = mlx_xpm_file_to_image(game->mlx, T_DOOR, &width, &height);
	if (game->t_door == NULL)
		free_game(game, game->parse, 1, "Error\nInvalid Door texture\n");
	game->t_door2 = mlx_xpm_file_to_image(game->mlx, T_DOOR2, &width, &height);
	if (game->t_door2 == NULL)
		free_game(game, game->parse, 1, "Error\nInvalid Door texture\n");
	game->t_door3 = mlx_xpm_file_to_image(game->mlx, T_DOOR3, &width, &height);
	if (game->t_door3 == NULL)
		free_game(game, game->parse, 1, "Error\nInvalid Door texture\n");
	game->t_door4 = mlx_xpm_file_to_image(game->mlx, T_DOOR4, &width, &height);
	if (game->t_door4 == NULL)
		free_game(game, game->parse, 1, "Error\nInvalid Door texture\n");
}

int	ft_xpm_to_image(t_game *game)
{
	if (load_no(game, game->parse) == 0)
		free_game(game, game->parse, 1, "Error\nInvalid NO texture\n");
	if (load_so(game, game->parse) == 0)
		free_game(game, game->parse, 1, "Error\nInvalid SO texture\n");
	if (load_we(game, game->parse) == 0)
		free_game(game, game->parse, 1, "Error\nInvalid WE texture\n");
	if (load_ea(game, game->parse) == 0)
		free_game(game, game->parse, 1, "Error\nInvalid EA texture\n");
	load_door(game);
	return (0);
}
