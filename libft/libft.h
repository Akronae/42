/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 16:07:53 by adaubric          #+#    #+#             */
/*   Updated: 2022/01/11 12:28:09 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>

# define INDEX_NOT_FOUND -1
# define TRUE 1
# define FALSE 0

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_strlen(const char *s);
void	*ft_memmove(void *dst, const void *src, int len);
void	*ft_memset(void *dst, int copied_char, int len);
void	ft_bzero(void *dst, int n);
void	*ft_memcpy(void *dst, const void *src, int n);
int		ft_isprint(int c);
void	*ft_memchr(const void *s, int c, int n);
int		ft_memcmp(const void *s1, const void *s2, int n);
char	*ft_strchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, int n);
char	*ft_strrchr(const char *s, int c);
int		ft_tolower(int c);
int		ft_toupper(int c);
int		ft_strlcat(char *dst, const char *src, int size);
int		ft_strlcpy(char *dst, const char *src, int size);
char	*ft_strnstr(const char *haystack, const char *needle, int len);
int		ft_atoi(const char *str);
void	*ft_calloc(int count, int size);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, int len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);

#endif //LIBFT_H
