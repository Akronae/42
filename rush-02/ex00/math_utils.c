//
// Created by alexr on 7/11/2021.
//

#include "math_utils.h"

int	val_max(int value, int max)
{
	if (value > max)
		return (value);
	return (max);
}

int	val_min(int value, int min)
{
	if (value < min)
		return (value);
	return (min);
}
