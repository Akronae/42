/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 18:34:59 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:02:10 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STACK_H
# define FT_STACK_H

# include "unistd.h"
# include "../libft/list/ft_list.h"

typedef struct t_stack
{
    struct t_list       *base;
    void		        (*free)(struct t_stack *self);
    struct t_stack		*(*push)(struct t_stack *self, struct t_stack *src);
    struct t_stack		*(*reverse_rotate)(struct t_stack *self);
    struct t_stack		*(*rotate)(struct t_stack *self);
    struct t_stack		*(*swap)(struct t_stack *self);
}	t_stack;

void		ft_stack_free(t_stack *self);
t_stack     *ft_stack_push(t_stack *self, t_stack *src);
t_stack     *ft_stack_reverse_rotate(t_stack *self);
t_stack     *ft_stack_rotate(t_stack *self);
t_stack		*ft_stack_swap(t_stack *self);
t_stack		*new_stack(void);

#endif
