#ifndef _MY_SORT_H_
#define _MT_SORT_H_

#include <stddef.h>

void mysort(void *const base, size_t num, size_t size, int (*comparator)(const void *, const void *));

void swap(void *elem_1, void *elem_2, size_t size);

int comparator(const void *elem_1, const void *elem_2);

#endif