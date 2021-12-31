#ifndef _SORT_H_
#define _SORT_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(void *elem_1, void *elem_2, size_t size);
int comparator(const void *elem_1, const void *elem_2);
void mysort(void *const base, size_t num, size_t size, int (*comparator)(const void *, const void *));

#endif