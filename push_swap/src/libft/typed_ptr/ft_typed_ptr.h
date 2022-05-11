/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_typed_ptr.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 18:34:59 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:02:10 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TYPED_PTR_H
# define FT_TYPED_PTR_H

# include "unistd.h"
# include "../type/ft_type.h"

typedef struct t_typed_ptr
{
	void 		*value;
	char		*as_str;
	long long	*as_long;
	t_type	type;
	struct t_typed_ptr 	*(*clone)(struct t_typed_ptr *self);
	void 	(*free)(struct t_typed_ptr *self);
	void 	(*set_value)(struct t_typed_ptr *self, void *value);
	int 	(*value_equals)(struct t_typed_ptr *self, struct t_typed_ptr *to);
}	t_typed_ptr;

t_typed_ptr *ft_typed_ptr_clone(t_typed_ptr *self);
void			ft_typed_ptr_free(t_typed_ptr *self);
void			ft_typed_ptr_set_value(t_typed_ptr *self, void *value);
int ft_typed_ptr_value_equals(t_typed_ptr *self, t_typed_ptr *to);
t_typed_ptr		*new_typed_ptr(t_type type, void *data);
t_typed_ptr		*new_typed_ptr_decimal(long long decimal);
t_typed_ptr		*ft_d(long long decimal);
t_typed_ptr		*new_typed_ptr_str(char *str);
t_typed_ptr		*ft_s(char *str);

#endif
