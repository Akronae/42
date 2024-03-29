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

# define FALSE 0
# define TRUE 1

typedef enum bool { false = 0, true = !false }	t_bool;

long long	ft_if_int(t_bool condition, long long if_true, long long if_false);
void		*ft_if_ptr(t_bool condition, void *if_true, void *if_false);
char		*ft_if_str(t_bool condition, char *if_true, char *if_false);

#endif