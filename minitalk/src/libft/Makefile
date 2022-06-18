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

SRCS			=	binary/ft_binary_byte_to_str.c binary/ft_binary_get_bit.c binary/ft_binary_set_bit.c \
					buffer/ft_buffer_free.c buffer/ft_buffer_get_bit.c buffer/ft_buffer_read.c \
					buffer/ft_buffer_read_bit.c buffer/ft_buffer_read_byte.c \
					buffer/ft_buffer_set_bit.c buffer/ft_buffer_to_str.c \
					buffer/ft_buffer_write.c buffer/ft_buffer_write_bit.c buffer/ft_buffer_write_byte.c \
					buffer/new_buffer.c \
					memory/ft_bzero.c char/ft_isalnum.c char/ft_isdigit.c char/ft_isprint.c \
					memory/ft_memcpy.c memory/ft_memmove.c memory/ft_memset.c memory/ft_persistent_ptr.c \
					memory/ft_safe_free.c \
					memory/ft_safe_malloc.c string/ft_strlen.c \
					memory/ft_memchr.c \
					memory/ft_memcmp.c memory/ft_swap_long.c \
					string/ft_strchr.c string/ft_strncmp.c string/ft_strrchr.c \
					string/ft_strlcpy.c string/ft_strlcat.c string/ft_strnstr.c memory/ft_calloc.c string/ft_strdup.c \
					string/ft_substr.c string/ft_strjoin.c string/ft_strtrim.c string/ft_split.c list/ft_split_list.c \
					string/ft_str_equal.c \
					string/ft_str_index_of.c string/ft_str_index_of_char.c \
					string/ft_str_is_numeric.c string/ft_str_starts_with.c \
					io/printf/ft_arg_conversion.c io/printf/ft_formatted_element.c io/printf/ft_formatted_element2.c \
					io/printf/ft_printf.c io/printf/ft_str_format.c \
					io/printf/ft_template_type.c io/ft_exit_err.c io/ft_index_out_of_range_error.c io/ft_putchar_fd.c \
					io/ft_putstr_fd.c io/ft_putnbr_fd.c io/ft_putendl_fd.c string/ft_striteri.c char/ft_char_to_lower.c \
					string/ft_char_to_str.c char/ft_char_to_upper.c hex/ft_hex_str_from_nbr.c \
					iterator/ft_iterator_free.c iterator/ft_iterator_next.c iterator/ft_iterator_next_str.c \
					iterator/ft_iterator_next_char.c iterator/ft_iterator_next_long.c iterator/ft_iterator_reset.c \
					iterator/ft_iterator_skip.c iterator/new_iterator.c \
					key_value_pair/ft_key_value_pair_free.c key_value_pair/new_key_value_pair.c \
					link/ft_link_for_each.c link/ft_link_clone.c link/ft_link_free.c link/ft_link_get_first.c \
					link/ft_link_get_last.c link/ft_link_insert.c link/ft_link_remove.c link/ft_link_reverse.c \
					link/ft_link_set_data.c \
					link/new_link.c \
					list/ft_list_clone.c list/ft_list_contains.c list/ft_list_count.c list/ft_list_find.c \
					list/ft_list_find_index.c \
					list/ft_list_find_max.c list/ft_list_find_min.c list/ft_list_find_mins.c list/ft_list_for_each.c \
					list/ft_list_free.c \
					list/ft_list_free_by_data.c \
					list/ft_list_free_by_data.c list/ft_list_from_str_arr.c \
					list/ft_list_get_elem.c \
					list/ft_list_get_iterator.c list/ft_list_index_of.c list/ft_list_insert_at.c \
					list/ft_list_join.c list/ft_list_map.c list/ft_list_find_max.c list/ft_list_find_maxes.c \
					list/ft_list_pop.c \
					list/ft_list_swap.c \
					list/ft_list_push.c \
					list/ft_list_push_char.c list/ft_list_push_data.c list/ft_list_push_llong.c \
					list/ft_list_push_malloc.c list/ft_list_push_range.c \
					list/ft_list_push_str.c list/ft_list_remove_at.c list/ft_list_remove_by_data.c \
					list/ft_list_reverse.c list/ft_list_sort.c list/ft_list_sub.c \
					list/new_list.c logic/ft_if_int.c logic/ft_if_ptr.c logic/ft_if_str.c \
					map/ft_map_add.c map/ft_map_free.c map/ft_map_get.c map/new_map.c \
					math/ft_math_abs.c math/ft_math_clamp.c math/ft_math_max.c math/ft_math_min.c \
					number/ft_number_to_str.c \
					number/ft_str_to_number_base.c \
					number/ft_str_to_number.c string/ft_str_append.c \
					ptr/ft_ptr_cast_ll.c \
					string/ft_str_append_char.c string/ft_string_to_upper.c \
					typed_ptr/ft_typed_ptr_clone.c typed_ptr/ft_typed_ptr_free.c typed_ptr/ft_typed_ptr_set_value.c \
					typed_ptr/ft_typed_ptr_to_str.c \
					typed_ptr/ft_typed_ptr_value_equals.c typed_ptr/new_typed_ptr.c \
					typed_ptr/new_typed_ptr_char.c typed_ptr/new_typed_ptr_llong.c typed_ptr/new_typed_ptr_long.c \
					typed_ptr/new_typed_ptr_str.c

HEADERS			=	libft.h binary/ft_binary.h buffer/ft_buffer.h char/ft_char.h hex/ft_hex.h io/ft_io.h io/printf/ft_printf.h \
					iterator/ft_iterator.h key_value_pair/ft_key_value_pair.h link/ft_link.h \
 					list/ft_list.h logic/ft_logic.h map/ft_map.h key_value_pair/ft_key_value_pair.h math/ft_math.h \
 					memory/ft_memory.h number/ft_number.h ptr/ft_ptr.h string/ft_string.h \
 					type/ft_type.h typed_ptr/ft_typed_ptr.h

OBJS			= $(SRCS:.c=.o)

CC				= clang
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -g

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
