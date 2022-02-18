//
// Created by Alexandre DAUBRICOURT on 7/17/21.
//

#ifndef NUMBER_DICT_H
# define NUMBER_DICT_H

struct s_dict_entry	*build_number_dict(char *dict_path);
char	*number_dict_find(char *key, struct s_dict_entry *dict);

#endif //NUMBER_DICT_H
