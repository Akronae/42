/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brigitte.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 15:09:47 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:02:10 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRIGITTE_H
# define BRIGITTE_H

# include "mlx/game_object.h"
# include "mlx/game.h"

void			ft_brigitte_on_update(t_game_object *self, t_game *game);
t_game_object	*new_brigitte(t_game *game);

#endif