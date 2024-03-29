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
	enum t_type		data_type;
	struct t_link	*prev;
	struct t_link	*next;
	void			(*free)(struct t_link *self);
	struct t_link	*(*get_first)(struct t_link *self);
	struct t_link	*(*get_last)(struct t_link *self);
	struct t_link	*(*insert)(struct t_link *self);
	struct t_link	*(*reverse)(struct t_link *self);
	void			(*for_each)(struct t_link *self,
			void (*action)(struct t_link *elem));
}	t_link;

void			ft_link_free(struct t_link *self);
struct t_link	*ft_link_get_first(struct t_link *self);
struct t_link	*ft_link_get_last(struct t_link *self);
struct t_link	*ft_link_insert(struct t_link *self);
struct t_link	*ft_link_reverse(struct t_link *self);
void			ft_link_for_each(struct t_link *self,
					void (*action)(struct t_link *elem));
struct t_link	*new_link(void);

#endif