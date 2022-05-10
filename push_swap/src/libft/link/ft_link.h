/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_link.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 15:09:47 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:02:10 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LINK_H
# define FT_LINK_H

# include "../type/ft_type.h"

typedef struct t_link
{
	void			*data;
	long long		*as_long;
	char			*as_str;
	enum t_type		data_type;
	struct t_link	*prev;
	struct t_link	*next;
	struct t_link	*(*clone)(struct t_link *self);
	void			(*free)(struct t_link *self);
	struct t_link	*(*get_first)(struct t_link *self);
	struct t_link	*(*get_last)(struct t_link *self);
	struct t_link	*(*insert)(struct t_link *self, struct t_link *to_insert);
	struct t_link	*(*remove)(struct t_link *self);
	struct t_link	*(*reverse)(struct t_link *self);
	struct t_link	*(*set_data)(struct t_link *self, t_type data_type, void *data);
	void			(*for_each)(struct t_link *self,
			void (action)(struct t_link *elem));
}	t_link;

t_link	*ft_link_clone(t_link *self);
void	ft_link_free(t_link *self);
t_link	*ft_link_get_first(t_link *self);
t_link	*ft_link_get_last(t_link *self);
t_link	*ft_link_insert(t_link *self, t_link *to_insert);
t_link	*ft_link_remove(t_link *self);
t_link	*ft_link_reverse(t_link *self);
t_link	*ft_link_set_data(t_link *self, t_type data_type, void *data);
void	ft_link_for_each(t_link *self, void (*action)(t_link *elem));
t_link	*new_link(void);

#endif