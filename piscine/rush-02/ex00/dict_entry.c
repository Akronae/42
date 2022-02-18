//
// Created by Alexandre DAUBRICOURT on 7/17/21.
//
#include "dict_entry.h"

struct s_dict_entry	new_dict_entry(char *key, char *value)
{
	struct s_dict_entry s = {.key = key, .value = value};
	return (s);
}

