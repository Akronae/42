/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_logic.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 15:09:47 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:02:10 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LOGIC_H
# define FT_LOGIC_H

# include "../libft.h"

llong	ft_if_int(t_bool condition, llong if_true, llong if_false);
void	*ft_if_ptr(t_bool condition, void *if_true, void *if_false);
t_str 	ft_if_str(t_bool condition, t_str if_true, t_str if_false);

#endif