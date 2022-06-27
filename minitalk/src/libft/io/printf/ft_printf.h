/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 15:09:47 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:02:10 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# ifdef __APPLE__
#  define NULL_PTR_DISPLAY "0x0"
# else
#  define NULL_PTR_DISPLAY "(nil)"
# endif

# define FLAG_FREE "{.free()}"

# include <unistd.h>
# include <stdarg.h>
# include "../../link/ft_link.h"
# include "../../string/ft_string.h"

typedef struct t_formatted_element {
	size_t	length;
	t_str 	value;
	int		should_be_freed;
}	t_formatted_element;

typedef enum t_template_type {
	CHAR,
	STRING,
	POINTER,
	DECIMAL,
	INT,
	LONGLONG,
	U_DECIMAL,
	HEXADECIMAL,
	UPPER_HEXADECIMAL,
	PERCENT
}	t_template_type;

struct t_list				*ft_printf_parse_args(va_list args, t_str input);
int							ft_print(t_str input, va_list args);
int							ft_printf(t_str input, ...);
int							ft_printfl(t_str input, ...);
char						*ft_str_format(t_str input, ...);
char						*ft_str_format_handle_args(t_str input,
								va_list args);
char						*ft_arg_str_to_str(t_str str);
char						*ft_arg_ptr_to_str(ullong ptr);
char						*ft_arg_hex_to_str(uint val,
								t_template_type type);
struct t_formatted_element	*new_formatted_element(void);
void						ft_formatted_list_free_elem(t_link *elem);
struct t_formatted_element	*ft_arg_to_formatted_elem(
								va_list args, enum t_template_type type,
								int free_arg);
void						ft_arg_to_formatted_elem2(
								va_list args, enum t_template_type type,
								t_formatted_element *elem);
struct t_formatted_element	*ft_char_to_formatted_elem(char c);
enum t_template_type		ft_template_type_from_char(t_str s);
enum t_template_type		ft_template_type_from_str(t_str s, size_t *i);

#endif