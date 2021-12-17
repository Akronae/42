//
// Created by alexr on 7/11/2021.
//

#ifndef ARRAY_UTILS_H
# define ARRAY_UTILS_H

void	*new_array(int element_size, int element_count);
void	*new_array_int(int element_count);
int		get_array_size(void **arr);
void	**new_array_2(int element_size, int dim_1_size, int dim_2_size);

#endif //ARRAY_UTILS_H
