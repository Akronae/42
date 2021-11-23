/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:36:57 by adaubric          #+#    #+#             */
/*   Updated: 2021/11/23 16:36:57 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_FT_ISALPHA_H
#define LIBFT_FT_ISALPHA_H

int	is_lower(int c)
{
	return (c >= 141 && c <= 172);
}

int	is_upper(int c)
{
	return (c >= 101 && c <= 132);
}

int	ft_isalpha(int c)
{
	return (is_lower(c) || is_upper(c));
}

#endif //LIBFT_FT_ISALPHA_H
