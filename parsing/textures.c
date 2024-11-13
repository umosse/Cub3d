/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:07:40 by aroualid          #+#    #+#             */
/*   Updated: 2024/11/13 18:12:10 by aroualid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "parsing.h"

t_img	*load_sprite(void *img, char *filename)
{
	int	width;
	int	height;

	if (!img || !filename)
		return (NULL);
	return (mlx_xpm_file_to_image(img, filename, &width, &height));
}

int	load_no(t_game *game, t_parse *parse)
{
	t_img	**ptr;

	ptr = malloc(sizeof(t_img *) * 1);
	if (!ptr)
		return (0);
	ptr[0] = load_sprite(game->mlx, parse->info->no_path);
	game->t_north = ptr[0];
	if (ptr[0] == NULL)
		return (0);
	return (1);
}

int	load_so(t_game *game, t_parse *parse)
{
	t_img	**ptr;

	ptr = malloc(sizeof(t_img *) * 1);
	if (!ptr)
		return (0);
	ptr[0] = load_sprite(game->mlx, parse->info->so_path);
	game->t_south = ptr[0];
	if (ptr[0] == NULL)
		return (0);
	return (1);
}

int	load_we(t_game *game, t_parse *parse)
{
	t_img	**ptr;

	ptr = malloc(sizeof(t_img *) * 1);
	if (!ptr)
		return (0);
	ptr[0] = load_sprite(game->mlx, parse->info->we_path);
	game->t_west = ptr[0];
	if (ptr[0] == NULL)
		return (0);
	return (1);
}

int	load_ea(t_game *game, t_parse *parse)
{
	t_img	**ptr;

	ptr = malloc(sizeof(t_img *) * 1);
	if (!ptr)
		return (0);
	ptr[0] = load_sprite(game->mlx, parse->info->ea_path);
	game->t_east = ptr[0];
	if (ptr[0] == NULL)
		return (0);
	return (1);
}


