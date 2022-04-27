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

SRCS			=	memory/ft_bzero.c char/ft_isalnum.c char/ft_isascii.c char/ft_isdigit.c char/ft_isprint.c \
					memory/ft_memcpy.c memory/ft_memmove.c memory/ft_memset.c memory/ft_safe_free.c \
					memory/ft_safe_malloc.c string/ft_strlen.c \
					memory/ft_memchr.c \
					memory/ft_memcmp.c string/ft_strchr.c string/ft_strncmp.c string/ft_strrchr.c \
					string/ft_strlcpy.c string/ft_strlcat.c string/ft_strnstr.c memory/ft_calloc.c string/ft_strdup.c \
					string/ft_substr.c string/ft_strjoin.c string/ft_strtrim.c string/ft_split.c string/ft_str_equal.c \
					string/ft_str_index_of.c string/ft_str_index_of_char.c \
					string/ft_str_is_numeric.c string/ft_str_starts_with.c \
					io/printf/ft_arg_conversion.c io/printf/ft_formatted_element.c io/printf/ft_formatted_element2.c \
					io/printf/ft_printf.c io/printf/ft_str_format.c \
					io/printf/ft_template_type.c io/ft_exit_err.c io/ft_putchar_fd.c \
					io/ft_putstr_fd.c io/ft_putendl_fd.c string/ft_striteri.c char/ft_char_to_lower.c \
					char/ft_char_to_str.c char/ft_char_to_upper.c hex/ft_hex_str_from_nbr.c \
					iterator/ft_iterator_free.c iterator/ft_iterator_next.c iterator/ft_iterator_next_str.c \
					iterator/ft_iterator_next_char.c iterator/ft_iterator_next_long.c iterator/ft_iterator_reset.c \
					iterator/ft_iterator_skip.c iterator/new_iterator.c \
					link/ft_link_for_each.c link/ft_link_free.c link/ft_link_get_first.c \
					link/ft_link_get_last.c link/ft_link_insert.c link/ft_link_remove.c link/ft_link_reverse.c \
					link/ft_link_set_data.c \
					link/new_link.c \
					list/ft_list_for_each.c list/ft_list_free.c list/ft_list_from_str_arr.c list/ft_list_get_elem.c \
					list/ft_list_get_iterator.c list/ft_list_insert_at.c \
					list/ft_list_join.c list/ft_list_map.c list/ft_list_swap.c \
					list/ft_list_push.c \
					list/ft_list_push_char.c list/ft_list_push_data.c list/ft_list_push_long.c \
					list/ft_list_push_malloc.c \
					list/ft_list_push_str.c list/ft_list_remove_at.c list/ft_list_reverse.c \
					list/new_list.c logic/ft_if_int.c math/ft_math_abs.c math/ft_math_clamp.c number/ft_number_to_str.c \
					number/ft_str_to_number_base.c \
					number/ft_str_to_number.c string/ft_str_append.c \
					string/ft_str_append_char.c string/ft_string_to_upper.c

HEADERS			=	libft.h logic/ft_logic.h char/ft_char.h hex/ft_hex.h io/ft_io.h io/printf/ft_printf.h \
					iterator/ft_iterator.h link/ft_link.h \
 					list/ft_list.h math/ft_math.h memory/ft_memory.h number/ft_number.h string/ft_string.h \
 					type/ft_type.h

OBJS			= $(SRCS:.c=.o)

CC				= clang
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -fsanitize=address -g3

NAME			= libft.a

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
