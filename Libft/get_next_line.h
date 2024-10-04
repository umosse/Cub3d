/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umosse <umosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 12:23:15 by umosse            #+#    #+#             */
/*   Updated: 2024/04/11 15:04:31 by umosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <stddef.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <sys/stat.h>
# include <fcntl.h>

size_t	ft_strlen(const char *str);
char	*ft_strchr(char *str, char to_find);
void	*ft_bzero(void *str, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strjoin2(char *s1, char *s2);
char	*ft_readfile(int fd, char *line);
char	*ft_cutline(char *line);
char	*ft_linecomp(char *line);
char	*get_next_line(int fd);

#endif