//
// Created by alexr on 7/11/2021.
//

#ifndef STRING_UTILS_H
# define STRING_UTILS_H

int		str_len(char *str);
int		str_index_of(char *str, char *substr);
char	*substr(char *str, int from, int to);
char	**str_split(char *str, char *separator);

#endif //STRING_UTILS_H
