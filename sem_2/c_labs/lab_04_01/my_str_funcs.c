#include "my_str_funcs.h"
#include <stddef.h>

char *my_strchr(const char *str, int sym) 
{
    int i = 0;
    
    while (str[i] && str[i] != sym) 
        ++i;
    
    if (sym == str[i])
        return (char*)str + i;
    else
        return NULL;
}
