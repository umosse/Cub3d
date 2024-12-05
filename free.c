/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:15:03 by aroualid          #+#    #+#             */
/*   Updated: 2024/12/05 16:20:39 by aroualid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parsing/parsing.h"

void	free_sprite(t_img *ptr, t_game *game)
{
	mlx_destroy_image(game->mlx, ptr);
	ptr = NULL;
	free(ptr);
	ptr = NULL;
}

void	free_no_exit(t_parse *parse, int print, char *str)
{
	if (parse->lines != NULL)
		free_lines(parse);
	if (parse->map_square != NULL)
		free_split(parse->map_square);
	if (parse->map != NULL)
		free_split(parse->map);
	if (parse->temp != NULL)
		free (parse->temp);
	if (parse->info != NULL)
		free_info(parse->info);
	if (parse->av != NULL)
		free (parse->av);
	if (parse->fd != -1)
		close (parse->fd);
	free(parse);
	if (print == 1)
		printf("%s", str);
	exit (0);
}

void	free_doors(t_game *game)
{
	if (game->t_door)
		free_sprite(game->t_door, game);
	if (game->t_door2)
		free_sprite(game->t_door2, game);
	if (game->t_door3)
		free_sprite(game->t_door3, game);
	if (game->t_door4)
		free_sprite(game->t_door4, game);
}

void	free_game(t_game *game, t_parse *parse, int print, char *str)
{
	if (game->t_north)
		free_sprite(game->t_north, game);
	if (game->t_south)
		free_sprite(game->t_south, game);
	if (game->t_west)
		free_sprite(game->t_west, game);
	if (game->t_east)
		free_sprite(game->t_east, game);
	free_doors(game);
	if (game->data.img && game->mlx)
		mlx_destroy_image(game->mlx, game->data.img);
	if (game->mlx && game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx && game->screen)
		mlx_destroy_image(game->mlx, game->screen);
	if (game->mlx)
		mlx_destroy_display(game->mlx);
	free(game->mlx);
	free_no_exit(parse, print, str);
}
