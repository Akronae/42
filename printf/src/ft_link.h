/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_link.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 15:09:47 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/17 11:14:22 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LINK_H
# define FT_LINK_H

typedef struct t_link
{
	void			*data;
	struct t_link	*prev;
	struct t_link	*next;
	void 	(*free)(struct t_link *self);
	struct t_link 	*(*get_first)(struct t_link *self);
	struct t_link 	*(*get_last)(struct t_link *self);
	struct t_link 	*(*insert)(struct t_link *self);
	struct t_link 	*(*reverse)(struct t_link *self);
}	t_link;

t_link	*new_link();

#endif