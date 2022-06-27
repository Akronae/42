/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 16:07:53 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:02:10 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define INDEX_NOT_FOUND -1

# ifndef ENV_DEV
#  define ENV_DEV 0
# endif

# ifndef USE_COLOR_OUTPUT
#  define USE_COLOR_OUTPUT 1
# endif

typedef unsigned int	uint;
typedef unsigned long int	ulong;
typedef long long int	llong;
typedef unsigned long long int	ullong;
typedef enum bool { false = 0, true = !false }	t_bool;
typedef char*	t_str;

#endif //LIBFT_H
