/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:44:06 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:02:10 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/io/ft_io.h"
#include "libft/list/ft_list.h"
#include "libft/string/ft_string.h"
#include "libft/map/ft_map.h"
#include "stacks_op/ft_stacks_op.h"
#include "sort_stack.h"
#include "push_swap.h"

t_map	*ft_get_commands_map(void)
{
	t_map		*map;

	map = new_map();
	map->add(map, ft_d(SA), ft_s("sa"));
	map->add(map, ft_d(SB), ft_s("sb"));
	map->add(map, ft_d(SS), ft_s("ss"));
	map->add(map, ft_d(PA), ft_s("pa"));
	map->add(map, ft_d(PB), ft_s("pb"));
	map->add(map, ft_d(PP), ft_s("pp"));
	map->add(map, ft_d(RA), ft_s("ra"));
	map->add(map, ft_d(RB), ft_s("rb"));
	map->add(map, ft_d(RR), ft_s("rr"));
	map->add(map, ft_d(RRA), ft_s("rra"));
	map->add(map, ft_d(RRB), ft_s("rrb"));
	map->add(map, ft_d(RRR), ft_s("rrr"));
	return (map);
}

char	*ft_commands_to_str(t_list *commands)
{
	t_list		*to_str;
	t_iterator	*i;
	char		*str;
	t_map		*map;

	to_str = new_list();
	i = commands->get_iterator(commands);
	map = ft_get_commands_map();
	while (i->next(i))
		to_str->push_str(to_str, ft_strdup(map->get(map, i->curr->data)
				->as_str));
	i->free(i);
	str = to_str->join(to_str, "\n");
	to_str->free(to_str);
	map->free(map);
	return (str);
}

t_list	*ft_args_to_input(int argc, char **argv)
{
	t_list	*input;
	t_list	*split;
	int		i;

	input = new_list();
	i = 0;
	while (i < argc)
	{
		split = ft_split_list(argv[i], ' ');
		input->push_range(input, split, 0, -1);
		split->free(split);
		i++;
	}
	return (input);
}

int	main(int argc, char **argv)
{
	t_list		*input;
	t_stacks_op	*op;

	input = ft_args_to_input(argc, argv);
	op = ft_sort_stack(ft_stack_from_input(input));
	if (op->operations->length > 0)
		ft_printfl("%s{.free()}", ft_commands_to_str(op->operations));
	op->free(op);
	input->free(input);
}
