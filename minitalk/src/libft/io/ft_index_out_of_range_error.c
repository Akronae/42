/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index_out_of_range_error.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 11:23:58 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:02:10 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_io.h"

void	*ft_index_out_of_range_error(t_string callee, size_t index,
			size_t arr_size)
{
	return (ft_exit_err("%s: index %d is outside the bounds"
			" of the array [0, %d].", callee, index, arr_size - 1));
}

void	*ft_check_index_out_of_range_error(t_string callee, size_t index,
			size_t arr_size)
{
	if (index > arr_size - 1)
		return (ft_index_out_of_range_error(callee, index, arr_size));
	return (NULL);
}
