/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:14:17 by adaubric          #+#    #+#             */
/*   Updated: 2021/11/28 16:47:53 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_lower(int c)
{
	return (c >= 97 && c <= 122);
}

int	is_upper(int c)
{
	return (c >= 65 && c <= 90);
}

int	ft_isalpha(int c)
{
	return (is_lower(c) || is_upper(c));
}