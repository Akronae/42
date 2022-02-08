//
// Created by alexr on 7/11/2021.
//

#include "int_utils.h"
#include "char_utils.h"

int	ft_atoi(char *str)
{
	int					sign;
	unsigned long int	result;

	sign = 1;
	result = 0;
	while (is_whitespace(*str))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while ((*str != '\0') && is_digit(*str))
	{
		result = (result * 10) + (*str - '0');
		str++;
	}
	return ((int)(result * sign));
}
