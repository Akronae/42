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

typedef char*	t_string;

t_string 	ft_char_to_str(char c);
void	ft_str_append(t_string dst, t_string src);
void	ft_str_append_char(t_string dst, char src);
void	ft_string_to_upper(t_string str);
t_string 	*ft_split(t_string s, char c);
int		ft_str_index_of(t_string to_find, t_string in_str);
int		ft_str_index_of_char(char to_find, t_string in_str);
int		ft_str_is_numeric(t_string s);
int		ft_str_starts_with(t_string str, t_string with);
int		ft_str_equal(t_string s1, t_string s2);
size_t	ft_strlen(t_string s);
size_t	ft_strlcpy(t_string dst, t_string src, size_t size);
size_t	ft_strlcat(t_string dst, t_string src, size_t size);
t_string 	ft_strchr(t_string s, int c);
t_string 	ft_strrchr(t_string s, int c);
int		ft_strncmp(t_string s1, t_string s2, int n);
t_string 	ft_strnstr(t_string haystack, t_string needle, size_t len);
t_string 	ft_strdup(t_string s1);
t_string 	ft_substr(t_string s, long start, long len);
t_string 	ft_strjoin(t_string s1, t_string s2);
t_string 	ft_strtrim(t_string s1, t_string set);
t_string 	*ft_split(t_string s, char c);
t_string 	ft_strmapi(t_string s, char (*f)(unsigned int, char));
void	ft_striteri(t_string s, void (*f)(unsigned int, t_string ));

#endif
