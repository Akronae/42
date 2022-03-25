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

# include <unistd.h>
# include <stdarg.h>
# include "../../link/ft_link.h"

typedef struct t_formatted_element {
	size_t	length;
	char	*value;
}	t_formatted_element;

typedef enum t_template_type {
	CHAR,
	STRING,
	POINTER,
	DECIMAL,
	INT,
	U_DECIMAL,
	HEXADECIMAL,
	UPPER_HEXADECIMAL,
	PERCENT
}	t_template_type;

int		ft_printf(const char *input, ...);
int		ft_printfl(const char *input, ...);
char	*ft_arg_str_to_str(char *str);
char	*ft_arg_ptr_to_str(unsigned long long ptr);
char	*ft_arg_hex_to_str(unsigned int val, t_template_type type);
struct t_formatted_element	*new_formatted_element(void);
void						ft_formatted_list_free_elem(t_link *elem);
struct t_formatted_element	*ft_arg_to_formatted_elem(va_list args,
														enum t_template_type type);
struct t_formatted_element	*ft_char_to_formatted_elem(char c);
enum t_template_type	ft_template_type_from_char(char c);

#endif