/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 18:34:59 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/17 13:48:20 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

# include "unistd.h"
# include "ft_link.h"
# include "ft_iterator.h"

typedef struct t_list
{
	t_link	*first_element;
	t_link	*last_element;
	size_t	length;
	void	(*free)(struct t_list *self);
	void	(*push)(struct t_list *self);
	void	(*push_malloc)(struct t_list *self, int malloc_size);
	void	(*push_char)(struct t_list *self, char c);
	void	(*push_str)(struct t_list *self, char *str);
	void	(*reverse)(struct t_list *self);
	struct t_iterator	*(*get_iterator)(struct t_list *self);
	char	*(*join)(struct t_list *self, char *delimiter);
}	t_list;

t_list	*new_list();

#endif
