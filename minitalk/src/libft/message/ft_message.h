/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_message.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 18:34:59 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:02:10 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MESSAGE_H
# define FT_MESSAGE_H

# include "unistd.h"
# include "../libft.h"
# include "../map/ft_map.h"
# include "../buffer/ft_buffer.h"
# include "../logic/ft_logic.h"

typedef struct t_message
{
	t_bool		is_complete;
	llong		expected_size_bit;
	t_buffer	*data;
	t_map		*fields;
	void	(*receive_bit)(struct t_message *self, t_bit bit);
	void	(*serialize)(struct t_message *self);
	void	(*free)(struct t_message *self);
} t_message;

t_message *new_message();
void	ft_message_receive_bit(t_message *self, t_bit bit);
void	ft_message_serialize(t_message *self);
void ft_message_free(t_message *self);

#endif
