/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:07:40 by aroualid          #+#    #+#             */
/*   Updated: 2024/11/13 16:27:46 by aroualid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_img	*load_sprite(void *img, char *filename)
{
	int	width;
	int	height;

	if (!img || !filename)
		return (NULL);
	return (mlx_xpm_file_to_image(img, filename, &width, &height));
}
