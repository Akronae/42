TEMPLATE='
#include <stdio.h>
#include "{{dir}}/{{file_name}}"

#define p(x) {\
printf(_Generic(x, unsigned: "%u\n", signed: "%d\n", double: "%g\n", char *: "%s\n"), x);\
}
#define p_nonl(x) {\
printf(_Generic(x, unsigned: "%u", signed: "%d", double: "%g", char *: "%s"), x);\
}
#define parr(my_array) {\
int index;\
p_nonl("[");\
for( index = 0; index < (sizeof( my_array ) / sizeof( my_array[0] )); index++){\
        p_nonl(my_array[index]);\
p_nonl(", ");\
}\
p_nonl("]");\
}

int	main()
{
	  {{function_name}}();

    return 0;
}
'

norminette

for ex_dir in ex*; do
    if [ -d "$ex_dir" ]; then
        for code_file in $ex_dir/*; do
            if [ -f "$code_file" ]; then
                FUNCTION_NAME="$(basename $code_file | cut -d. -f1)"
                FILE_NAME="$FUNCTION_NAME.c"
                FILE_CONTENT=$(echo "$TEMPLATE"  | sed "s/{{function_name}}/$FUNCTION_NAME/g")
                FILE_CONTENT=$(echo "$FILE_CONTENT"  | sed "s/{{file_name}}/$FILE_NAME/g")
                FILE_CONTENT=$(echo "$FILE_CONTENT"  | sed "s/{{dir}}/$ex_dir/g")

                echo "$FILE_CONTENT" > "$ex_dir.c"
                gcc -Wall -Werror -Wextra "$ex_dir.c" -o "$ex_dir.out"
            fi
        done
    fi
done
