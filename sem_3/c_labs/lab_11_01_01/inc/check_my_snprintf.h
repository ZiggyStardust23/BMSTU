#ifndef _CHECH_MY_SNPRINTF_H_
#define _CHECK_MY_SNPRINTF_H_

#include "my_snprintf.h"

int test_snprintf_c();
int test_snprintf_s();
int test_snprintf_d();
int test_snprintf_o();

int cmp_two_str(const char *a, const char *b);
int my_strlen(const char *str);


#endif