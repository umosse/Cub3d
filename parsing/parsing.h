/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:13:05 by aroualid          #+#    #+#             */
/*   Updated: 2024/11/25 16:25:33 by aroualid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

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

typedef struct s_info
{
	int				no_ok;
	int				so_ok;
	int				we_ok;
	int				ea_ok;
	int				f_ok;
	int				c_ok;
	char			*no_path;
	char			*so_path;
	char			*we_path;
	char			*ea_path;
	char			*f_color;
	char			*c_color;
	char			**f_rgb;
	char			**c_rgb;
	unsigned int	f;
	unsigned int	c;
}	t_info;

typedef struct s_parse
{
	char	*av;
	char	**lines;
	char	*temp;
	int		last;
	int		first_line;
	char	**map;
	char	**map_square;
	int		max_x;
	int		max_y;
	double	player_x;
	double	player_y;
	char	orientation;
	int		fd;
	t_info	*info;
}			t_parse;

int		skip_space(char *s);
int		skip_space_reverse(char *s);
int		ft_strcmp(char *s1, char *s2);
int		ft_strncmp( const char *first, const char *second, size_t length);
int		free_parse_args(t_parse *parse, int i);
int		check_no(char *str, t_parse *parse, t_info *info);
int		check_so(char *str, t_parse *parse, t_info *info);
int		check_we(char *str, t_parse *parse, t_info *info);
int		check_ea(char *str, t_parse *parse, t_info *info);
int		convert_c(char *str, t_parse *parse, t_info *info);
int		convert_f(char *str, t_parse *parse, t_info *info);
char	*new_string(char *str, int taille);
char	**ft_split(char const *s, char c);
int		ft_atoi(const char *str);
int		count_symbol(char *str, char symbol);
int		check_file(char *av);
int		get_line(char *file);
int		parse_args(t_parse *parse, int fd, char **av);
int		check_map(t_parse *parse, int fd, char *av);
int		is_all_fill(t_parse *parse);
int		is_space(int c);
int		is_ok(char str);
void	fill_map(t_parse *parse, int max, int fd);		
void	max_map(t_parse *parse);
int		check_first_last_wall(t_parse *parse);
int		find_direction(t_parse *parse);
void	find_player_pos(t_parse *parse);
void	new_map(t_parse *parse);
void	free_split(char **split);
int		check_map_ok(t_parse *parse);
char	*replace_tab_by_space(char *str);
void	free_and_exit(t_parse *parse, int print, char *str);
void	free_info(t_info *info);
void	free_lines(t_parse *parse);

#endif
