/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:44:06 by adaubric          #+#    #+#             */
/*   Updated: 2022/03/23 14:56:45 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# define INDEX_NOT_FOUND -1
# define TRUE 1
# define FALSE 0

# include <unistd.h>

typedef struct t_env
{
	char	*text_read;
	size_t	last_byte;
}	t_env;

int		str_index_of(char *to_find, char *in_str);
void	*ft_calloc(size_t size);
char	*str_join(char *s1, char *s2, int free_s1, int free_s2);
char	*sub_str(char *s, long from, long to);
char	*get_next_line(int fd);
void	safe_free(void *ptr);

#endif