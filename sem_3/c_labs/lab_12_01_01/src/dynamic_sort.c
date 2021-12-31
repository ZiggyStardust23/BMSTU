#include "../inc/dynamic_sort.h"

ARR_DLL void ARR_DECL swap(void *elem_1, void *elem_2, size_t size)
{
    char *first = (char*)elem_1;
    char *second = (char*)elem_2;

    for (int i = 0; i < size; i++)
    {
        char temp = *first;
        *first++ = *second;
        *second++ = temp;
    }
}

ARR_DLL int ARR_DECL comparator(const void *elem_1, const void *elem_2)
{
    int code = 0;
    const int *elem_1_to_char = elem_1;
    const int *elem_2_to_char = elem_2;
    if (*elem_1_to_char > *elem_2_to_char)
        code = 1;
    else 
        code = -1;

    return code;
}


ARR_DLL void ARR_DECL mysort(void *const base, size_t num, size_t size, int (*comparator)(const void *, const void *))
{
    char *pb = base;
    char *pe = (char *)base + size * (num - 1);
    int flag = 1;

    while (flag != -1 && (pb < pe))
    {
        flag = 1;
        for (char *i = pb; i != pe; i += size)
            if (comparator(i, i + size) > 0)
            {
                flag = 0;
                swap(i, i + size, size);
            }
        pe -= size;

        for (char *i = pe; i != pb; i -= size)
        {
            if (comparator(i - size, i) > 0)
            {
                flag = 0;
                swap(i - size, i, size);
            }
        }
        pb += size;

        if (flag == 1)
            flag = -1;
    }
}


