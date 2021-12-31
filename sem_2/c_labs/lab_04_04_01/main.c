#include <stdio.h>
#include <string.h>

#include "check_if_correct.h"

int main()
{
    char str[MAX_STR_LEN + 1];
    int str_len;

    str_len = read_str(str);
    
    int result = check_if_correct(str, str_len);
    
    if (result < 0)
        return result;
    else if (result == 1)
        printf("YES");
    else if (result == 0)
        printf("NO");

    return 0;
}
