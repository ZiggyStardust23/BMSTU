#ifndef _CHECK_MAIN_H_
#define _CHECK_MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <check.h>

#include "mysort.h"
#include "key.h"
#include "funcs.h"

Suite *comparator_suite(void);
Suite *key_suite(void);
Suite *mysort_suite(void);

#endif