/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formatted_element.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 15:09:59 by adaubric          #+#    #+#       	  */
/*   Updated: 2022/02/21 14:58:44 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FORMATTED_ELEMENT_H
# define FT_FORMATTED_ELEMENT_H

# include <unistd.h>
# include <stdarg.h>
# include "libft/link/ft_link.h"
# include "ft_template_type.h"

typedef struct t_formatted_element {
	size_t	length;
	char	*value;
}	t_formatted_element;

struct t_formatted_element	*new_formatted_element(void);
void						ft_formatted_list_free_elem(t_link *elem);
struct t_formatted_element	*ft_arg_to_formatted_elem(va_list args,
								enum t_template_type type);
struct t_formatted_element	*ft_char_to_formatted_elem(char c);
#endif