# ************************************************************************** #
#                                                                            #
#                                                        :::      ::::::::   #
#   Makefile                                           :+:      :+:    :+:   #
#                                                    +:+ +:+         +:+     #
#   By: adaubric <adaubric@student.42.fr>          +#+  +:+       +#+        #
#                                                +#+#+#+#+#+   +#+           #
#   Created: 2021/11/28 15:39:56 by adaubric          #+#    #+#             #
#   Updated: 202#   Updated: 2022/02/04 14:42:30 by adaubric         ###   ########.fr       #                                                              #
# ************************************************************************** #

SRCS			=	ft_isalpha.c ft_bzero.c ft_isalnum.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memcpy.c \
					ft_memmove.c ft_memset.c ft_strlen.c ft_memchr.c ft_memcmp.c ft_strchr.c ft_strncmp.c \
					ft_strrchr.c ft_tolower.c ft_toupper.c ft_strlcpy.c ft_strlcat.c ft_strnstr.c ft_atoi.c ft_calloc.c \
					ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c \
					ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_striteri.c

HEADERS			=	libft.h

OBJS			= $(SRCS:.c=.o)

CC				= clang
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

NAME			= libft.a

all:			$(NAME)

$(NAME):		$(OBJS) $(HEADERS)
				ar rcs $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

bonus:			$(OBJS)
				ar rcs $(NAME) $(OBJS)

.PHONY:			all clean fclean re bonus
