/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binary.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:44:06 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:12:23 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARY_H
# define BINARY_H

# include "../string/ft_string.h"

typedef t_bool	t_bit;
typedef char	t_byte;

t_str ft_binary_byte_to_str(t_byte byte);
t_bit	ft_binary_get_bit(t_byte byte, int index);
t_byte ft_binary_set_bit(t_byte byte, int index, t_bool value);

#endif
