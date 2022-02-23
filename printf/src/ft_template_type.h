/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_template_type.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:44:06 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:12:23 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TEMPLATE_TYPE_H
# define FT_TEMPLATE_TYPE_H

# include <unistd.h>

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

enum t_template_type	ft_template_type_from_char(char c);

#endif