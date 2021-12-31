#ifndef _CHECK_SORT_H_
#define _CHECK_SORT_H_

#include <stdio.h>
#include <stdlib.h>

#include <check.h>

#ifdef DYNAMIC_UNIT
#include "dynamic_sort.h"
#else
#include "mysort.h"
#endif

Suite *sort_suite(void);
Suite *comparator_suite(void);

#endif