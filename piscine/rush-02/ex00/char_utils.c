//
// Created by alexr on 7/11/2021.
//

#include "char_utils.h"

int	is_digit(int c)
{
	return (c >= '0' && c <= '9');
}

int	is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r');
}
