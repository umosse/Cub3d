/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:13:05 by aroualid          #+#    #+#             */
/*   Updated: 2024/11/13 16:02:21 by aroualid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "get_next_line.h"

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
	char	**lines;
	char	*temp;
	t_info	*info;
}			t_parse;

void	ft_bzero(void *s, size_t n);
int		skip_space(char *s);
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
#endif
