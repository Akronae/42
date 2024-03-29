/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:44:06 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:12:23 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAP_H
# define FT_MAP_H

# include "../list/ft_list.h"
# include "../kv_pair/ft_kv_pair.h"

typedef struct t_map
{
	t_list		*entries;
	t_kv_pair	*(*add)(struct t_map *self, t_typed_ptr *key,
			t_typed_ptr *value);
	void		(*free)(struct t_map *self);
	t_typed_ptr	*(*get)(struct t_map *self, t_typed_ptr *key);
	t_typed_ptr	*(*get_lld)(struct t_map *self, t_llong key_lld);
	t_typed_ptr	*(*get_str)(struct t_map *self, t_str key_str);
}	t_map;

t_kv_pair	*ft_map_add(t_map *self, t_typed_ptr *key,
				t_typed_ptr *value);
void		ft_map_free(t_map *self);
t_typed_ptr	*ft_map_get(t_map *self, t_typed_ptr *key);
t_typed_ptr	*ft_map_get_lld(t_map *self, t_llong key_lld);
t_typed_ptr	*ft_map_get_str(t_map *self, t_str key_str);
t_map		*new_map(void);
#endif
