# ************************************************************************** #
#                                                                            #
#                                                        :::      ::::::::   #
#   Makefile                                           :+:      :+:    :+:   #
#                                                    +:+ +:+         +:+     #
#   By: adaubric <adaubric@student.42.fr>          +#+  +:+       +#+        #
#                                                +#+#+#+#+#+   +#+           #
#   Created: 2021/11/28 15:39:56 by adaubric          #+#    #+#             #
#   Updated: 202#   Updated: 2022/03/23 13:52:15 by adaubric         ###   ########.fr       #                                                              #
# ************************************************************************** #

SRCS			=	src/get_next_line.c src/get_next_line_utils.c

HEADERS			=	src/get_next_line.h

OBJS			= $(SRCS:.c=.o)

CC				= clang
RM				= rm -r -f
#CFLAGS			= -Wall -Wextra -Werror -fsanitize=address -g3 -D BUFFER_SIZE=3
CFLAGS			= -Wall -Wextra -Werror -ggdb3 -D BUFFER_SIZE=3

NAME			= get_next_line.a

$(NAME):		$(OBJS) $(HEADERS)
				ar rcs $(NAME) $(OBJS)

all:			$(NAME)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

bonus:			$(OBJS)
				ar rcs $(NAME) $(OBJS)

.PHONY:			all clean fclean re bonus
