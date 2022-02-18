//
// Created by Alexandre DAUBRICOURT on 7/17/21.
//

#ifndef DICT_ENTRY_H
# define DICT_ENTRY_H

struct	s_dict_entry
{
	char	*key;
	char	*value;
};

struct s_dict_entry	new_dict_entry(char *key, char *value);

#endif // DICT_ENTRY_H
