/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 15:09:59 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/04 15:18:01 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TYPE_H
# define FT_TYPE_H

typedef enum	t_type {
	CHAR,
	STRING,
	POINTER,
	DECIMAL,
	INT,
	U_DECIMAL,
	HEXADECIMAL,
	FLOAT,
	DOUBLE
} t_type;

#endif