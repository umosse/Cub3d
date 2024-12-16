/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3dutils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:12:24 by aroualid          #+#    #+#             */
/*   Updated: 2024/12/16 15:04:45 by aroualid         ###   ########.fr       */
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

int	check_args_for_rgb(int r, int g, int b, char **rgb)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 3)
	{
		while (rgb[i][j])
		{
			if (rgb[i][j] >= '0' && rgb[i][j] <= '9')
				j++;
			else
				return (0);
		}
		j = 0;
		i++;
	}
	if (r >= 0 && r <= 255 && g >= 0 && g <= 255 && b >= 0 && b <= 255)
		return (1);
	return (0);
}
