//
// Created by Alexandre DAUBRICOURT on 7/17/21.
//

#include "number_dict.h"
#include "dict_entry.h"
#include "file_utils.h"
#include "array_utils.h"
#include "string_utils.h"
#include <stdlib.h>
#include <stdio.h>

struct s_dict_entry	*build_number_dict(char *dict_path)
{
	char **dict_lines = str_split(read_file(dict_path), "\n");
	struct s_dict_entry *dict = new_array(sizeof(struct s_dict_entry), get_array_size((void **) dict_lines));
	int i = -1;
	int dict_i = -1;
	char **split;

	while (++i < get_array_size((void **) dict_lines))
	{
		split = str_split(dict_lines[i], ":");
		if (get_array_size((void **) split) < 2)
			continue;
		dict[++dict_i] = new_dict_entry(str_trim(split[0]), str_trim(split[1]));
	}
	dict[++dict_i] = new_dict_entry(NULL, NULL);
	return (dict);
}

char	*number_dict_find(char *key, struct s_dict_entry *dict)
{
	int	i;

	i = -1;
	while (++i < get_array_size((void **) dict))
	{
		if (dict[i].key == NULL || dict[i].value == NULL)
			break ;
		if (str_compare(dict[i].key, key) == 0)
		{
			return (dict[i].value);
		}
	}

	return (NULL);
}