/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:44:06 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:12:23 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BUFFER_H
# define FT_BUFFER_H

# include <stdlib.h>
# include "../libft.h"
# include "../logic/ft_logic.h"
# include "../list/ft_list.h"
# include "../binary/ft_binary.h"
# include "../kv_pair/ft_kv_pair.h"
# include "../map/ft_map.h"

typedef struct t_buffer
{
	t_str		data;
	size_t		size_bits;
	size_t		used_bits;
	size_t		index_read;
	size_t		index_write;
	void		(*free)(struct t_buffer *self);
	t_bit		(*get_bit)(struct t_buffer *self, size_t bit_index);
	t_typed_ptr	*(*read)(struct t_buffer *self, t_type type);
	t_bit		(*read_bit)(struct t_buffer *self);
	t_byte		(*read_byte)(struct t_buffer *self);
	void		*(*read_bytes)(struct t_buffer *self, size_t len_bytes);
	char		(*read_char)(struct t_buffer *self);
	int			(*read_int)(struct t_buffer *self);
	t_kv_pair	*(*read_kv_pair)(struct t_buffer *self);
	t_list		*(*read_list)(struct t_buffer *self);
	t_llong		(*read_llong)(struct t_buffer *self);
	long		(*read_long)(struct t_buffer *self);
	t_map		*(*read_map)(struct t_buffer *self);
	t_llong		(*read_number)(struct t_buffer *self, int bytes_len);
	char		*(*read_str)(struct t_buffer *self);
	t_typed_ptr	*(*read_typed_ptr)(struct t_buffer *self);
	void		(*write_char)(struct t_buffer *self, char data);
	void		(*write_int)(struct t_buffer *self, int data);
	void		(*write_kv_pair)(struct t_buffer *self,
			t_kv_pair *data);
	void		(*write_list)(struct t_buffer *self, t_list *data);
	void		(*write_llong)(struct t_buffer *self, t_llong data);
	void		(*write_long)(struct t_buffer *self, long data);
	void		(*write_map)(struct t_buffer *self, t_map *data);
	void		(*write_buffer)(struct t_buffer *self, struct t_buffer *buff);
	void		(*write_byte)(struct t_buffer *self, t_byte data);
	void		(*write_bytes)(struct t_buffer *self, void *data,
			size_t len_bytes);
	void		(*write_str)(struct t_buffer *self, t_str data);
	void		(*write_typed_ptr)(struct t_buffer *self, t_typed_ptr *data);
	void		(*set_bit)(struct t_buffer *self, size_t bit_index,
			t_bit value);
	char		*(*to_str)(struct t_buffer *self);
	void		(*write)(struct t_buffer *self, t_typed_ptr *data);
	void		(*write_bit)(struct t_buffer *self, t_bit data);
}	t_buffer;

void		ft_buffer_free(t_buffer *self);
t_bit		ft_buffer_get_bit(t_buffer *self, size_t bit_index);
t_typed_ptr	*ft_buffer_read(t_buffer *self, t_type type);
t_bit		ft_buffer_read_bit(t_buffer *self);
t_byte		ft_buffer_read_byte(t_buffer *self);
void		*ft_buffer_read_bytes(t_buffer *self, size_t len_bytes);
void		ft_buffer_set_bit(t_buffer *self, size_t bit_index, t_bool value);
char		*ft_buffer_to_str(t_buffer *self);
void		ft_buffer_write(t_buffer *self, t_typed_ptr *data);
void		ft_buffer_write_bit(t_buffer *self, t_bit data);
void		ft_buffer_write_byte(t_buffer *self, t_byte data);
char		ft_buffer_read_char(struct t_buffer *self);
int			ft_buffer_read_int(struct t_buffer *self);
t_kv_pair	*ft_buffer_read_kv_pair(struct t_buffer *self);
t_list		*ft_buffer_read_list(struct t_buffer *self);
t_llong		ft_buffer_read_llong(struct t_buffer *self);
long		ft_buffer_read_long(struct t_buffer *self);
t_map		*ft_buffer_read_map(struct t_buffer *self);
t_llong		ft_buffer_read_number(struct t_buffer *self, int bytes_len);
t_byte		ft_buffer_read_byte(struct t_buffer *self);
t_str		ft_buffer_read_str(struct t_buffer *self);
t_typed_ptr	*ft_buffer_read_typed_ptr(struct t_buffer *self);
void		ft_buffer_write_char(struct t_buffer *self, char data);
void		ft_buffer_write_int(struct t_buffer *self, int data);
void		ft_buffer_write_kv_pair(struct t_buffer *self, t_kv_pair *data);
void		ft_buffer_write_list(struct t_buffer *self, t_list *data);
void		ft_buffer_write_llong(struct t_buffer *self, t_llong data);
void		ft_buffer_write_long(struct t_buffer *self, long data);
void		ft_buffer_write_map(struct t_buffer *self, t_map *data);
void		ft_buffer_write_buffer(t_buffer *self, t_buffer *buff);
void		ft_buffer_write_byte(struct t_buffer *self, t_byte data);
void		ft_buffer_write_bytes(struct t_buffer *self, void *data,
				size_t len_bytes);
void		ft_buffer_write_str(struct t_buffer *self, t_str data);
void		ft_buffer_write_typed_ptr(struct t_buffer *self,
				t_typed_ptr *data);
t_buffer	*new_buffer(void);

#endif
