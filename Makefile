# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: umosse <umosse@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/04 12:53:11 by umosse            #+#    #+#              #
#    Updated: 2024/10/22 14:05:48 by umosse           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
NAME = cub3d
NAME_BONUS = 
SRCS = cub3d.c cub3dutils.c movement.c raycasting.c maptest.c
SRCS_BONUS = 
OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)
CFLAGS = -Wall -Werror -Wextra -g3
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS) minilibx-linux/libmlx.a Libft/libft.a
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -Lminilibx-linux -lmlx_Linux -lmlx -lX11 -lXext -lm Libft/libft.a

minilibx-linux/libmlx.a:
	make -C minilibx-linux

bonus: $(OBJS_BONUS) Libft/libft.a
	cc $(CFLAGS) -o $(NAME_BONUS) $(OBJS_BONUS) Libft/libft.a

Libft/libft.a:
	make -C Libft

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)
	cd Libft && make clean

fclean : clean
	$(RM) $(NAME) $(NAME_BONUS)
	cd Libft && make fclean

re: fclean all

.PHONY : all clean fclean re