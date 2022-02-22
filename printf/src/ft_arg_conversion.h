/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formatted_element.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 15:09:59 by adaubric          #+#    #+#       	  */
/*   Updated: 2022/02/21 14:58:44 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ARG_CONVERSION_H
# define FT_ARG_CONVERSION_H

# include <unistd.h>
# include "ft_template_type.h"

char	*ft_arg_str_to_str(char *str);
char	*ft_arg_ptr_to_str(unsigned long long ptr);
char	*ft_arg_hex_to_str(unsigned int val, t_template_type type);

#endif