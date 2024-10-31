/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umosse <umosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 13:23:24 by umosse            #+#    #+#             */
/*   Updated: 2024/10/31 15:49:58 by umosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H

# define CUB3D_H

# include "Libft/libft.h"
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include <stddef.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdarg.h>
# include <limits.h>
# include <math.h>
# include <stdbool.h>

//WINDOW
# define W_HEIGHT 540
# define W_LENGTH 960

//COLORS
# define P_WHITE 0xFFFFFFFF
# define P_RED 0x00FF0000
# define P_CYAN 0x0000FFFF
# define P_MAGENTA 0x00FF00FF
# define P_YELLOW 0x00FFFF00
# define P_GREEN 0x0000FF00
# define P_BLUE 0x000000FF
# define P_BLACK 0x00000000

//TEXTURES
# define T_NORTH "textures/north.xpm"
# define T_SOUTH "textures/south.xpm"
# define T_WEST "textures/west.xpm"
# define T_EAST "textures/east.xpm"
# define T_DOOR "textures/door.xpm"
# define T_DOOR2 "textures/door2.xpm"
# define T_DOOR3 "textures/door3.xpm"
# define T_DOOR4 "textures/door4.xpm"

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_game
{
	void			*mlx;
	void			*win;
	char			**map;
	double			playerx;
	double			playery;
	double			dirx;
	double			diry;
	double			olddirx;
	double			planex;
	double			planey;
	double			oldplanex;
	double			camerax;
	double			raydirx;
	double			raydiry;
	double			deltadistx;
	double			deltadisty;
	double			sidedistx;
	double			sidedisty;
	double			perpwalldist;
	int				stepx;
	int				stepy;
	int				hit;
	int				side;
	int				mapx;
	int				mapy;
	int				lineheight;
	int				drawstart;
	int				drawend;
	int				sky;
	int				floor;
	t_img			*screen;
	int				w;
	int				a;
	int				s;
	int				d;
	int				r;
	int				l;
	int				e;
	int				maxmapx;
	int				maxmapy;
	char			**maptest;
	unsigned int	color;
	double			movespeed;
	double			rotspeed;
	t_data			data;
	int				textnum;
	double			wallx;
	int				textx;
	int				texty;
	double			step;
	double			textpos;
	t_img			*t_north;
	t_img			*t_south;
	t_img			*t_west;
	t_img			*t_east;
	t_img			*t_door;
	t_img			*t_door2;
	t_img			*t_door3;
	t_img			*t_door4;
	int				framecount;
}	t_game;

//cub3d.c
int		ft_destroy(t_game *game);
int		ft_update(t_game *game);

//cub3dutils.c
void	ft_clear_screen(t_game *game, unsigned int color);
void	ft_hooks(t_game *game);

//movement.c
void	ft_lateral(t_game *game);
void	ft_rotate(t_game *game);
void	ft_door(t_game *game);
void	ft_movement2(t_game *game);
void	ft_movement(t_game *game);

//movementutils.c
int		ft_key_pressed(int keysym, t_game *game);
int		ft_key_released(int keysym, t_game *game);

//raycasting.c
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	ft_topdown(t_game *game);
void	ft_dda(t_game *game);
void	ft_raycasting(t_game *game);

//raycast_utils
void	ft_raycast_calcs(t_game *game);
void	ft_drawsize(t_game *game);
void	ft_drawtextures(t_game *game, int x);
void	ft_animdoor(t_game *game);
void	ft_colortextures(t_game *game);

//commented
void	ft_destroyall(t_game *game);
void	ft_end(t_game *game, int j);
char	**ft_mapalloc(char *file, t_game *game);
int		ft_isdead(t_game *game);
void	ft_frames(t_game *game);
void	ft_mapread2(int fd, char *line);
void	ft_destroyall2(t_game *game);
int		ft_mapread3(char *line, t_game *game, int fd);

//maptest.c
char	**ft_mapalloc(char *file, t_game *game);
char	**ft_mapread(char *file, t_game *game);

#endif