TEMPLATE='
#include <stdio.h>
#include "{{dir}}/{{file_name}}"

int	main()
{
	  {{function_name}}();

    return 0;
}
'

for ex_dir in ex*; do
    if [ -d "$ex_dir" ]; then
        for code_file in $ex_dir/*; do
            if [ -f "$code_file" ]; then
                FUNCTION_NAME="$(basename $code_file | cut -d. -f1)"
                FILE_NAME="$FUNCTION_NAME.c"
                FILE_CONTENT=$(echo $TEMPLATE | sed "s/{{function_name}}/$FUNCTION_NAME/g")
                FILE_CONTENT=$(echo $FILE_CONTENT | sed "s/{{file_name}}/$FILE_NAME/g")
                FILE_CONTENT=$(echo $FILE_CONTENT | sed "s/{{dir}}/$ex_dir/g")

                echo "$FILE_CONTENT" > $FILE_NAME
                gcc -Wall -Werror -Wextra $FILE_NAME -o "$FUNCTION_NAME.out"
            fi
        done
    fi
done
