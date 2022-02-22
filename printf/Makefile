# ************************************************************************** #
#                                                                            #
#                                                        :::      ::::::::   #
#   Makefile                                           :+:      :+:    :+:   #
#                                                    +:+ +:+         +:+     #
#   By: adaubric <adaubric@student.42.fr>          +#+  +:+       +#+        #
#                                                +#+#+#+#+#+   +#+           #
#   Created: 2021/11/28 15:39:56 by adaubric          #+#    #+#             #
#   Updated: 202#   Updated: 2022/02/21 15:10:32 by adaubric         ###   ########.fr       #                                                              #
# ************************************************************************** #

LIBFT_DIR		= ./src/libft
LIBFT_NAME		= libft.a

SRCS			=	src/ft_printf.c src/ft_template_type.c

HEADERS			=	src/ft_printf.h src/ft_template_type.h

OBJS			= $(SRCS:.c=.o)

CC				= clang
RM				= rm -r -f
CFLAGS			= -Wall -Wextra -Werror #-fsanitize=address -g3

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
				$(RM) $(LIBFT_DIR)/$(LIBFT_NAME)
				make clean -C $(LIBFT_DIR)

re:				fclean $(NAME)

bonus:			$(OBJS)
				ar rcs $(NAME) $(OBJS)

.PHONY:			all clean fclean re bonus
