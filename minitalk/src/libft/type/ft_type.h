/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:44:06 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:12:23 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TYPE_H
# define FT_TYPE_H

# define T_TYPE_UNKNOWN_STR "(type_unknown)"

typedef enum t_type
{
	T_TYPE_UNKNOWN,
	T_TYPE_CHAR,
	T_TYPE_STRING,
	T_TYPE_POINTER,
	T_TYPE_INT,
	T_TYPE_LONG,
	T_TYPE_LLONG,
	T_TYPE_TYPED_PTR,
	T_TYPE_LIST,
	T_TYPE_KEY_VALUE_PAIR,
	T_TYPE_MAP,
	T_TYPE_MESSAGE,
	T_TYPE_IPC_SOCKET,
}	t_type;

#endif
