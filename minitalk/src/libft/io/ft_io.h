/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_io.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 11:26:11 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:02:10 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_IO_H
# define FT_IO_H

# define ANSI_COLOR_RED   "\x1B[31m"
# define ANSI_COLOR_GREEN   "\x1B[32m"
# define ANSI_COLOR_YELLOW   "\x1B[33m"
# define ANSI_COLOR_BLUE   "\x1B[34m"
# define ANSI_COLOR_MAGENTA   "\x1B[35m"
# define ANSI_COLOR_CYAN   "\x1B[36m"
# define ANSI_COLOR_WHITE   "\x1B[37m"
# define ANSI_COLOR_RESET "\x1B[0m"

# include "printf/ft_printf.h"

void	*ft_exit_err(t_str msg, ...);
void	*ft_check_index_out_of_range_error(t_str callee, size_t index,
			size_t arr_size);
void	*ft_index_out_of_range_error(t_str callee, size_t index,
			size_t arr_size);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(t_str s, int fd);
void	ft_putendl_fd(t_str s, int fd);
void	ft_putnbr_fd(t_llong n, int fd);
t_str	ft_ansi_color_format(t_str str);

#endif
