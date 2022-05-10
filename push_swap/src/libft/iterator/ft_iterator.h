/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterator.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 18:34:59 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:02:10 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ITERATOR_H
# define FT_ITERATOR_H

# include "unistd.h"
# include "../list/ft_list.h"
# include "../link/ft_link.h"

typedef struct t_iterator
{
	struct t_list	*list;
	t_link	*curr;
	long	index;
	t_link	*(*next)(struct t_iterator *self);
	char	*(*next_str)(struct t_iterator *self);
	char	(*next_char)(struct t_iterator *self);
	long	(*next_long)(struct t_iterator *self);
	void	(*reset)(struct t_iterator *self);
	void	(*skip)(struct t_iterator *self, size_t skip_count);
	void	(*free)(struct t_iterator *self);
}	t_iterator;

t_link		*ft_iterator_next(struct t_iterator *self);
char		*ft_iterator_next_str(struct t_iterator *self);
char		ft_iterator_next_char(struct t_iterator *self);
long		ft_iterator_next_long(t_iterator *self);
void		ft_iterator_reset(struct t_iterator *self);
void		ft_iterator_skip(t_iterator *self, size_t skip_count);
void		ft_iterator_free(struct t_iterator *self);
t_iterator	*new_iterator(struct t_list *first);

#endif
