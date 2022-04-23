/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 18:34:59 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:02:10 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

# include "unistd.h"
# include "../link/ft_link.h"
# include "../iterator/ft_iterator.h"

typedef struct t_list
{
	t_link				*first_element;
	t_link				*last_element;
	size_t				length;
	void				(*free)(struct t_list *self);
	struct t_list		*(*from_str_arr)(struct t_list *self, char **arr, size_t from, size_t to);
	void				(*on_elem_free)(t_link *elem);
	t_link				*(*push)(struct t_list *self, t_link *link);
	void				(*push_malloc)(struct t_list *self, int malloc_size);
	void				(*push_char)(struct t_list *self, char c);
	void				(*push_data)(struct t_list *self, t_type data_type, void *data);
	void				(*push_long)(struct t_list *self, long long l);
	void				(*push_str)(struct t_list *self, char *str);
	t_link				*(*get_elem)(struct t_list *self, size_t at_index);
	void				(*reverse)(struct t_list *self);
	struct t_iterator	*(*get_iterator)(struct t_list *self);
	char				*(*join)(struct t_list *self, char *delimiter);
	struct t_list		*(*map)(struct t_list *self, t_link *(*action)(t_link *));
	void				(*for_each)(struct t_list *self, void (*action)
			(t_link *elem));
}	t_list;

void		ft_list_free(t_list *self);
t_list		*ft_list_from_str_arr(struct t_list *self, char **arr, size_t from, size_t to);
t_link		*ft_list_push(t_list *self, t_link *link);
void		ft_list_push_char(t_list *self, char c);
void		ft_list_push_data(t_list *self, t_type data_type, void *data);
void		ft_list_push_long(t_list *self, long long l);
void		ft_list_push_malloc(t_list *self, int malloc_size);
void		ft_list_push_str(t_list *self, char *str);
t_link		*ft_list_get_elem(t_list *self, size_t at_index);
void		ft_list_reverse(t_list *self);
struct t_iterator	*ft_list_get_iterator(t_list *self);
char		*ft_list_join(t_list *self, char *delimiter);
t_list		*ft_list_map(t_list *self, t_link *(*action)(t_link *));
void		ft_list_for_each(t_list *self, void (*action)(t_link *elem));
t_list		*new_list(void);

#endif
