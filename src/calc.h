#ifndef CALC_H
#define CALC_H

#include <math.h>
#include <stdlib.h>

#include "parse.h"
#include "stack.h"

double calculate(char *postfix_exp, double x, int *flag);
int base_operations(const char *postfix_exp, double a, double b, double *res);
int func_operations(const char *postfix_exp, double a, double b, double *res, double *nums, int *top);

#endif