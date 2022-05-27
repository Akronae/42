/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 17:08:36 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:02:10 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MEMORY_H
# define FT_MEMORY_H

# include <unistd.h>
# include "../list/ft_list.h"

# define PERSISTENT_PTR_ARR_SIZE 10
# define PERSISTENT_PTR_INITIATED (int *) 0x7fabc4108040
typedef enum	t_persistent_ptr_op
{
	WRITE,
	READ,
}	t_persistent_ptr_op;

void	*ft_memset(void *dst, int copied_char, size_t len);
void	ft_init_persistent_ptr();
void	*ft_get_persistent_ptr(size_t index);
void	*ft_set_persistent_ptr(size_t index, void *ptr);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_calloc(size_t size);
void	ft_bzero(void *dst, size_t n);
void	ft_safe_free(void *ptr);
void	ft_safe_free_null(void **ptr);
void	*ft_safe_malloc(size_t malloc_size);
void	ft_swap_long(long *ptr1, long *ptr2);

#endif