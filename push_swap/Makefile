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

SRCS			=	src/stacks_op/ft_stack_at.c src/stacks_op/ft_stacks_op_free.c \
					src/stacks_op/ft_stacks_op_set_stack.c src/stacks_op/ft_stack_push.c \
					src/stacks_op/ft_stack_reverse_rotate.c \
					src/stacks_op/ft_stack_rotate.c src/stacks_op/ft_stack_swap.c src/stacks_op/new_stacks_op.c \
					src/push_swap.c

HEADERS			=	src/push_swap.h

OBJS			= $(SRCS:.c=.o)

CC				= clang
RM				= rm -r -f
CFLAGS			= -Wall -Wextra -Werror -g

NAME			= push_swap

$(NAME):		$(OBJS) $(HEADERS)
				make all -C $(LIBFT_DIR)/
				cp $(LIBFT_DIR)/$(LIBFT_NAME) $(NAME)
				$(CC) $(CFLAGS) $(SRCS) $(LIBFT_DIR)/$(LIBFT_NAME) -o $(NAME)

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
