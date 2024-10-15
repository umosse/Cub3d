/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umosse <umosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 14:49:07 by umosse            #+#    #+#             */
/*   Updated: 2024/10/15 14:50:00 by umosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_topdown(t_game *game)
{
	const int	s = game->screen->width * game->screen->height;
	int			i;
	

	game->sky = 0x00FF0000;
	game->floor = 0x0000FF00;
	i = -1;
	while (++i < s)
	{
		while (i < s/2)
		{
			*(((unsigned int *)game->screen->data + i)) = game->sky;
			i++;
		}
		*(((unsigned int *)game->screen->data + i)) = game->floor;
	}
}
