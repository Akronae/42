/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:38:25 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:02:10 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H

# define STRING_EMPTY ""

# include <unistd.h>
# include "../libft.h"

t_str	ft_char_to_str(char c);
void	ft_str_append(t_str dst, t_str src);
void	ft_str_append_char(t_str dst, char src);
void	ft_string_to_upper(t_str str);
t_str	*ft_split(t_str s, char c);
t_llong	ft_str_index_of(t_str str, t_str to_find);
t_llong	ft_str_index_of_char(t_str str, char to_find);
t_bool	ft_str_ends_with(t_str str, t_str with);
t_llong	ft_str_index_past(t_str str, t_str to_find);
int		ft_str_is_numeric(t_str s);
t_bool	ft_str_starts_with(t_str str, t_str with);
int		ft_str_equal(t_str s1, t_str s2);
size_t	ft_strlen(t_str s);
size_t	ft_strlcpy(t_str dst, t_str src, size_t size);
size_t	ft_strlcat(t_str dst, t_str src, size_t size);
t_str	ft_strchr(t_str s, int c);
t_str	ft_strrchr(t_str s, int c);
int		ft_strncmp(t_str s1, t_str s2, int n);
t_str	ft_strnstr(t_str haystack, t_str needle, size_t len);
t_str	ft_strdup(t_str s1);
t_str	ft_substr(t_str s, long start, long len);
t_str	ft_strjoin(t_str s1, t_str s2);
t_str	ft_strtrim(t_str s1, t_str set);
t_str	*ft_split(t_str s, char c);
t_str	ft_strmapi(t_str s, char (*f)(t_uint, char));
void	ft_striteri(t_str s, void (*f)(t_uint, t_str));
t_str	ft_str_replace(t_str s, t_str find, t_str replacement);

#endif
