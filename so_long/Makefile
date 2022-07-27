# ************************************************************************** #
#                                                                            #
#                                                        :::      ::::::::   #
#   Makefile                                           :+:      :+:    :+:   #
#                                                    +:+ +:+         +:+     #
#   By: adaubric <adaubric@student.42.fr>          +#+  +:+       +#+        #
#                                                +#+#+#+#+#+   +#+           #
#   Created: 2021/11/28 15:39:56 by adaubric          #+#    #+#             #
#   Updated: 2022/02/23 14:02:10 by adaubric         ###   ########.fr       #
#                                                                            #
# ************************************************************************** #

LIBFT_DIR		= ./src/libft
LIBFT_NAME		= libft.a
LIBX_DIR		= ./src/minilibx-linux
LIBX_NAME		= libmlx.a

SRCS			= src/so_long.c

HEADERS			= src/so_long.h

OBJS			= $(SRCS:.c=.o)

CC				= gcc
RM				= rm -r -f
CFLAGS			= -Wall -Wextra -Werror -g -D ENV_DEV=1 -D USE_COLOR_OUTPUT=0  #-fsanitize=address -g3
LFLAGS			= -L$(LIBX_DIR) -l:$(LIBX_NAME) -L$(LIBFT_DIR) -l:$(LIBFT_NAME) -lXext -lX11 -lm -lbsd

NAME			= so_long

$(NAME):		$(OBJS) $(HEADERS)
				make all CFLAGS="$(CFLAGS)" CC="$(CC)" -C $(LIBFT_DIR)/
				make all CFLAGS="$(CFLAGS)" CC="$(CC)" -C $(LIBX_DIR)/
				$(CC) -o $(NAME) $(OBJS) $(LFLAGS)

all:			$(NAME)

clean:
				$(RM) $(OBJS)
				make clean -C $(LIBFT_DIR)

fclean:			clean
				$(RM) $(NAME)
				$(RM) $(LIBFT_DIR)/$(LIBFT_NAME)
				make clean -C $(LIBFT_DIR)

re:				fclean $(NAME)

.PHONY:			all clean fclean re bonus
