/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroualid <aroualid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:36:19 by aroualid          #+#    #+#             */
/*   Updated: 2024/01/12 15:05:02 by aroualid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdio.h>
# include <limits.h>
# include <strings.h>
# include <ctype.h>
# include <string.h>
# include <sys/select.h>
# include <bits/posix2_lim.h>
# include <sys/types.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

size_t		ft_strlen(const char *s);
void		*ft_calloc(size_t nmemb, size_t size);
char		*ft_strchr(const char *s, int c);
void		*ft_memcpy(void *dest, const void *src, size_t n);
char		*get_next_line(int fd);

#endif
