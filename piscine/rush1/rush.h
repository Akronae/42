/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namrane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 21:52:13 by namrane           #+#    #+#             */
/*   Updated: 2021/07/11 23:02:36 by namrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_H
# define RUSH_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int		ft_strlen(char *str);
int		ft_sqrt(int nb);
int		ft_check_number(char *str);
char	*ft_newstr(char *str);
char	**init_table(char *newstr);
int		ft_init_place(char **table, char *newstr, int index);

#endif
