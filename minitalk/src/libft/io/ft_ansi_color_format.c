/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ansi_color_format.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 11:23:13 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:02:10 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../string/ft_string.h"
#include "../memory/ft_memory.h"
#include "../map/ft_map.h"
#include "../logic/ft_logic.h"
#include "ft_io.h"
#include "../libft.h"

t_str	ft_replace_free(t_str str, t_str to_find, t_str replacement)
{
	t_str	replaced;

	if (ft_str_index_of(str, to_find) == INDEX_NOT_FOUND)
		return (str);
	replaced = ft_str_replace(str, to_find, replacement);
	ft_safe_free(str);
	return (replaced);
}

t_str	ft_ansi_color_format(t_str str)
{
	if (ft_str_index_of(str, "<") == INDEX_NOT_FOUND)
		return (ft_strdup(str));
	t_map *colors = new_map();
	colors->add(colors, ft_s("<red>"), ft_s(ANSI_COLOR_RED));
	colors->add(colors, ft_s("</red>"), ft_s(ANSI_COLOR_RESET));
	colors->add(colors, ft_s("<yellow>"), ft_s(ANSI_COLOR_YELLOW));
	colors->add(colors, ft_s("</yellow>"), ft_s(ANSI_COLOR_RESET));
	colors->add(colors, ft_s("<green>"), ft_s(ANSI_COLOR_GREEN));
	colors->add(colors, ft_s("</green>"), ft_s(ANSI_COLOR_RESET));
	colors->add(colors, ft_s("<blue>"), ft_s(ANSI_COLOR_BLUE));
	colors->add(colors, ft_s("</blue>"), ft_s(ANSI_COLOR_RESET));
	colors->add(colors, ft_s("<magenta>"), ft_s(ANSI_COLOR_MAGENTA));
	colors->add(colors, ft_s("</magenta>"), ft_s(ANSI_COLOR_RESET));
	colors->add(colors, ft_s("<cyan>"), ft_s(ANSI_COLOR_CYAN));
	colors->add(colors, ft_s("</cyan>"), ft_s(ANSI_COLOR_RESET));
	colors->add(colors, ft_s("<white>"), ft_s(ANSI_COLOR_WHITE));
	colors->add(colors, ft_s("</white>"), ft_s(ANSI_COLOR_RESET));
	t_key_value_pair *pair;
	str = ft_strdup(str);
	t_iterator *i = colors->entries->get_iterator(colors->entries);
	while (i->next(i))
	{
		pair = i->curr->data->value;
		str = ft_replace_free(str, pair->key->as_str, ft_if_str(USE_COLOR_OUTPUT, pair->value->as_str, ""));
	}
	i->free(i);
	colors->free(colors);
	return (str);
}
