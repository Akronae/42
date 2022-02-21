/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_iterator.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 18:34:59 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/21 14:47:15 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ITERATOR_H
# define FT_ITERATOR_H

# include "unistd.h"
# include "../list/ft_list.h"
# include "../link/ft_link.h"
typedef struct t_iterator
{
	t_link 	*first;
	t_link	*current;
	void	*(*next)(struct t_iterator *self);
	char	*(*next_str)(struct t_iterator *self);
	char	(*next_char)(struct t_iterator *self);
	void	(*reset)(struct t_iterator *self);
	void	(*free)(struct t_iterator *self);
}	t_iterator;

void	*ft_iterator_next(struct t_iterator *self);
char	*ft_iterator_next_str(struct t_iterator *self);
char 	ft_iterator_next_char (struct t_iterator *self);
void	ft_iterator_reset(struct t_iterator *self);
void	ft_iterator_free(struct t_iterator *self);
t_iterator 	*new_iterator(t_link *first);

#endif
