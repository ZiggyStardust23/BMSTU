#ifndef _DYNAMIC_SORT_H_
#define _DYNAMIC_SORT_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dynamic.h"

ARR_DLL void ARR_DECL swap(void *elem_1, void *elem_2, size_t size);
ARR_DLL int ARR_DECL comparator(const void *elem_1, const void *elem_2);
ARR_DLL void ARR_DECL mysort(void *const base, size_t num, size_t size, int (*comparator)(const void *, const void *));

#endif