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
# include "../typed_ptr/ft_typed_ptr.h"
# include "../type/ft_type.h"
# include "../link/ft_link.h"
# include "../iterator/ft_iterator.h"

typedef struct t_list
{
	t_link				*first;
	t_link				*last;
	struct t_iterator	*i;
	size_t				length;
	struct t_list		*(*clone)(struct t_list *self);
	int					(*contains)(struct t_list *self, t_typed_ptr *data);
	unsigned long		(*count)(struct t_list *self, t_typed_ptr *data);
	t_link				*(*find)(struct t_list *self, t_typed_ptr *data);
	long				(*find_index)(struct t_list *self, t_typed_ptr *data);
	t_link				*(*find_max)(struct t_list *self, t_type of_type);
	struct t_list		*(*find_maxes)(struct t_list *self, t_type of_type,
			size_t count);
	t_link				*(*find_min)(struct t_list *self, t_type of_type);
	struct t_list		*(*find_mins)(struct t_list *self, t_type of_type,
			size_t count);
	void				(*free)(struct t_list *self);
	void				(*free_by_data)(struct t_list *self,
			t_typed_ptr *data);
	struct t_list		*(*from_str_arr)(struct t_list *self, char **arr,
			size_t from, size_t to);
	void				(*on_elem_free)(t_link *elem);
	t_link				*(*push)(struct t_list *self, t_link *link);
	void				(*push_malloc)(struct t_list *self, int malloc_size);
	struct t_list		*(*push_range)(struct t_list *self,
			struct t_list*to_push, long from, long to);
	void				(*push_char)(struct t_list *self, char c);
	void				(*push_data)(struct t_list *self, t_typed_ptr *data);
	void				(*push_long)(struct t_list *self, long long l);
	void				(*push_str)(struct t_list *self, char*str);
	t_link				*(*remove_at)(struct t_list *self, long remove_index);
	t_link				*(*remove_by_data)(struct t_list *self,
			t_typed_ptr *data);
	t_link				*(*get_elem)(struct t_list *self, long at_index);
	struct t_list		*(*reverse)(struct t_list *self);
	struct t_list		*(*sort)(struct t_list *self, t_type of_type);
	struct t_list		*(*sub)(struct t_list *self, long long from,
			long long to);
	void				(*swap)(struct t_list *self, long from_index,
			long to_index);
	struct t_iterator	*(*get_iterator)(struct t_list *self);
	long				(*index_of)(struct t_list *self, t_link*elem);
	t_link				*(*insert_at)(struct t_list *self, size_t insert_index,
			t_link*insert_elem);
	char				*(*join)(struct t_list *self, char*delimiter);
	struct t_list		*(*map)(struct t_list *self, t_link*(*action)(t_link*));
	t_link				*(*pop)(struct t_list *self);
	void				(*for_each)(struct t_list *self, void (*action)
			(t_link*elem));
}	t_list;

t_list				*ft_list_clone(t_list *self);
int					ft_list_contains(t_list *self, t_typed_ptr *data);
size_t				ft_list_count(t_list *self, t_typed_ptr *value);
t_link				*ft_list_find(t_list *self, t_typed_ptr *find_data);
long				ft_list_find_index(t_list *self, t_typed_ptr *find_data);
t_link				*ft_list_find_max(t_list *self, t_type of_type);
t_list				*ft_list_find_maxes(t_list *self, t_type of_type,
						size_t count);
t_link				*ft_list_find_min(t_list *self, t_type of_type);
t_list				*ft_list_find_mins(t_list *self, t_type of_type,
						size_t count);
void				ft_list_free(t_list *self);
void				ft_list_free_by_data(t_list *self,
						t_typed_ptr *data);
t_list				*ft_list_from_str_arr(struct t_list *self, char **arr,
						size_t from, size_t to);
t_link				*ft_list_push(t_list *self, t_link *link);
void				ft_list_push_char(t_list *self, char c);
void				ft_list_push_data(t_list *self, t_typed_ptr *data);
void				ft_list_push_long(t_list *self, long long l);
t_list				*ft_list_push_range(t_list *self, t_list *to_push,
						long from, long to);
void				ft_list_push_malloc(t_list *self, int malloc_size);
void				ft_list_push_str(t_list *self, char *str);
t_link				*ft_list_remove_at(t_list *self, long remove_index);
t_link				*ft_list_remove_by_data(t_list *self, t_typed_ptr *data);
t_link				*ft_list_get_elem(t_list *self, long at_index);
t_list				*ft_list_reverse(t_list *self);
t_list				*ft_list_sort(t_list *self, t_type of_type);
t_list				*ft_list_sub(t_list *self, long long from, long long to);
void				ft_list_swap(t_list *self, long from_index, long to_index);
struct t_iterator	*ft_list_get_iterator(t_list *self);
long				ft_list_index_of(t_list *self, t_link *elem);
t_link				*ft_list_insert_at(t_list *self, size_t insert_index,
						t_link *insert_elem);
char				*ft_list_join(t_list *self, char *delimiter);
t_list				*ft_list_map(t_list *self, t_link *(*action)(t_link*));
t_link				*ft_list_pop(t_list *self);
void				ft_list_for_each(t_list *self,
						void (*action)(t_link*elem));
t_list				*new_list(void);

#endif
