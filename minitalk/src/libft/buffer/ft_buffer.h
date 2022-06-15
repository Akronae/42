/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:44:06 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:12:23 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARY_BUFFER_H
# define BINARY_BUFFER_H

# include <stdlib.h>
# include "../logic/ft_logic.h"
# include "../list/ft_list.h"
# include "../binary/ft_binary.h"

typedef struct t_buffer
{
	t_list	*data;
	size_t	size_bits;
	size_t	index;
	void 	(*free)(struct t_buffer *self);
	t_bit 	(*get_bit)(struct t_buffer *self, size_t bit_index);
	t_typed_ptr *(*read)(struct t_buffer *self, t_type type);
	t_bit 	(*read_bit)(struct t_buffer *self);
	t_byte	(*read_byte)(struct t_buffer *self);
	void 	(*set_bit)(struct t_buffer *self, size_t bit_index, t_bit value);
	char 	*(*to_str)(struct t_buffer *self);
	void 	(*write)(struct t_buffer *self, t_typed_ptr *data);
	void 	(*write_bit)(struct t_buffer *self, t_bit data);
	void	(*write_byte)(struct t_buffer *self, t_byte data);
}	t_buffer;

void			ft_buffer_free(t_buffer *self);
t_bit			ft_buffer_get_bit(t_buffer *self, size_t bit_index);
t_typed_ptr *ft_buffer_read(t_buffer *self, t_type type);
t_bit	ft_buffer_read_bit(t_buffer *self);
t_byte	ft_buffer_read_byte(t_buffer *self);
void			ft_buffer_set_bit(t_buffer *self, size_t bit_index, t_bool value);
char			*ft_buffer_to_str(t_buffer *self);
void	ft_buffer_write(t_buffer *self, t_typed_ptr *data);
void	ft_buffer_write_bit(t_buffer *self, t_bit data);
void	ft_buffer_write_byte(t_buffer *self, t_byte data);
t_buffer	*new_buffer();

#endif
