/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 18:34:59 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/21 14:47:15 by adaubric         ###   ########.fr       */
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
	void				(*push)(struct t_list *self);
	void				(*push_malloc)(struct t_list *self, int malloc_size);
	void				(*push_char)(struct t_list *self, char c);
	void				(*push_str)(struct t_list *self, char *str);
	void				(*reverse)(struct t_list *self);
	struct t_iterator	*(*get_iterator)(struct t_list *self);
	char				*(*join)(struct t_list *self, char *delimiter);
}	t_list;

void				ft_list_free(struct t_list *self);
void				ft_list_push(struct t_list *self);
void				ft_list_push_malloc(struct t_list *self, int malloc_size);
void				ft_list_push_char(struct t_list *self, char c);
void				ft_list_push_str(struct t_list *self, char *str);
void				ft_list_reverse(struct t_list *self);
struct t_iterator	*ft_list_get_iterator(struct t_list *self);
char				*ft_list_join(struct t_list *self, char *delimiter);
struct t_list		*new_list(void);

#endif
