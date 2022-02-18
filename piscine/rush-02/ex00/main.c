#include <stdio.h>
#include "dict_entry.h"
#include <stdlib.h>
#include "string_utils.h"
#include "number_dict.h"
#include "string_utils2.h"
#include "io_utils.h"

void	translate_number(char *str, struct s_dict_entry *dict)
{
	int	i = 0;
	char *to_find;
	char *found;
	char *str_part;

	while (str[i])
	{
		if (i == 0 && str_len(str) % 3 != 0)
			i += str_len(str) % 3;
		else
			i += 3;

		str_part = substr(str, i - 3, i);
		to_find = str_part;
		found = number_dict_find(to_find, dict);
		if (found == NULL)
		{
			if (str_len(to_find) == 3)
			{
				translate_number(substr(to_find, 0, 1), dict);
				translate_number(str_catn("1", str_repeat("0", str_len(to_find) - 1)), dict);
			}
			else
			{
				translate_number(str_catn(substr(to_find, 0, 1), str_repeat("0", str_len(to_find) - 1)), dict);
			}
			translate_number(substr(to_find, 1, 3), dict);
		}
		else
		{
//			printf("to_find: %s, found: %s\n", to_find, found);
			putstr(found);
			putstr(" ");
		}
		if (str_len(str) - i > 2)
		{
			putstr(number_dict_find(str_catn("1", str_repeat("0", str_len(str) - i)), dict));
			putstr(" ");
//			printf("****%s\n", number_dict_find(str_catn("1", str_repeat("0", str_len(str) - i)), dict));
		}
	}
}

int	main(void)
{
	char *input = "548954584954895489";
	struct s_dict_entry *dict = build_number_dict("/Users/adaubric/proj/rush-02/ex00/numbers.dict");
	translate_number(input, dict);
	putstr("\b");
	return (0);
}
