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

SRCS			=
SRCS_CLIENT		=	src/client.c
SRCS_SERVER		=	src/server.c

HEADERS			=	src/minitalk.h

OBJS			= $(SRCS:.c=.o)

CC				= gcc
RM				= rm -r -f
CFLAGS			= -Wall -Wextra -Werror -g -D ENV_DEV=1 -D USE_COLOR_OUTPUT=0 #-fsanitize=address -g3

NAME			= push_swap
NAME_CLIENT		= client
NAME_SERVER		= server

$(NAME):		$(OBJS) $(HEADERS)
				make all CFLAGS="$(CFLAGS)" CC="$(CC)" -C $(LIBFT_DIR)/
				$(CC) $(CFLAGS) $(SRCS) $(SRCS_CLIENT) $(LIBFT_DIR)/$(LIBFT_NAME) -o $(NAME_CLIENT)
				$(CC) $(CFLAGS) $(SRCS) $(SRCS_SERVER) $(LIBFT_DIR)/$(LIBFT_NAME) -o $(NAME_SERVER)

all:			$(NAME)

clean:
				$(RM) $(OBJS)
				make clean -C $(LIBFT_DIR)

fclean:			clean
				$(RM) $(NAME_CLIENT)
				$(RM) $(NAME_SERVER)
				$(RM) $(LIBFT_DIR)/$(LIBFT_NAME)
				make clean -C $(LIBFT_DIR)

re:				fclean $(NAME)

.PHONY:			all clean fclean re bonus
