/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_if_int.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 15:09:47 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:02:10 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_logic.h"

t_llong	ft_if_int(t_bool condition, t_llong if_true, t_llong if_false)
{
	if (condition)
		return (if_true);
	return (if_false);
}
