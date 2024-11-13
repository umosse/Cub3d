/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:31:20 by aroualid          #+#    #+#             */
/*   Updated: 2024/11/13 17:42:22 by aroualid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	free_parse_args(t_parse *parse, int i)
{
	parse->temp = NULL;
	free (parse->temp);
	free(parse->lines[i]);
	return (0);
}
