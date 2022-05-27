/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_persistent_ptr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 17:08:36 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:02:10 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include "../string/ft_string.h"
#include "../logic/ft_logic.h"
#include "../io/ft_io.h"
#include <unistd.h>
#include <stdio.h>

void	*ft_persistent_ptr_operation(enum t_persistent_ptr_op operation,
	size_t index, void *ptr)
{
	void	*a[PERSISTENT_PTR_ARR_SIZE];

	if (operation == WRITE)
	{
		a[index] = ptr;
	}
	return (a[index]);
}

void	ft_init_persistent_ptr(void)
{
	size_t	i;

	i = 0;
	while (i < PERSISTENT_PTR_ARR_SIZE)
	{
		ft_persistent_ptr_operation(WRITE, i,
			ft_if_ptr(i == 0, PERSISTENT_PTR_INITIATED, NULL));
		i++;
	}
}

void	*ft_get_persistent_ptr(size_t index)
{
	return (ft_persistent_ptr_operation(READ, index, NULL));
}

void	*ft_set_persistent_ptr(size_t index, void *ptr)
{
	return (ft_persistent_ptr_operation(WRITE, index, ptr));
}
