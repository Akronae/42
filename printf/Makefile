# ************************************************************************** #
#                                                                            #
#                                                        :::      ::::::::   #
#   Makefile                                           :+:      :+:    :+:   #
#                                                    +:+ +:+         +:+     #
#   By: adaubric <adaubric@student.42.fr>          +#+  +:+       +#+        #
#                                                +#+#+#+#+#+   +#+           #
#   Created: 2021/11/28 15:39:56 by adaubric          #+#    #+#             #
#   Updated: 202#   Updated: 2022/02/17 14:57:31 by adaubric         ###   ########.fr       #                                                              #
# ************************************************************************** #

LIBFT_DIR		= ./src/libft
LIBFT_NAME		= libft.a

SRCS			=	src/math/ft_math_abs.c src/ft_char.c src/ft_hex.c src/ft_link.c src/ft_list.c src/ft_long.c \
					src/ft_iterator.c src/ft_printf.c src/ft_str.c

HEADERS			=	src/math/ft_math.h src/ft_boolean.h src/ft_char.h src/ft_hex.h src/ft_link.h src/ft_link.h \
					src/ft_list.h src/ft_long.h src/ft_iterator.h src/ft_printf.h src/ft_str.c src/ft_type.h

OBJS			= $(SRCS:.c=.o)

CC				= clang
RM				= rm -r -f
CFLAGS			= -Wall -Wextra -Werror -fsanitize=address -g3

NAME			= libftprintf.a

$(NAME):		$(OBJS) $(HEADERS)
				make all -C $(LIBFT_DIR)/
				cp $(LIBFT_DIR)/$(LIBFT_NAME) $(NAME)
				ar rcs $(NAME) $(OBJS)

all:			$(NAME)

clean:
				$(RM) $(OBJS)
				make clean -C $(LIBFT_DIR)

fclean:			clean
				$(RM) $(NAME)
				make clean -C $(LIBFT_DIR)

re:				fclean $(NAME)

bonus:			$(OBJS)
				ar rcs $(NAME) $(OBJS)

.PHONY:			all clean fclean re bonus
