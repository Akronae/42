/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:00:41 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:02:10 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NUMBER_H
# define FT_NUMBER_H

# define BASE_10 "0123456789"
# define BASE_HEX "0123456789abcdef"

# include "../string/ft_string.h"

t_str	ft_number_to_str(t_llong ll);
t_llong	ft_str_to_number_base(t_str s, t_str base);
t_llong	ft_str_to_number(t_str s);

#endif
