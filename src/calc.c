#include "calc.h"

#include <math.h>

#include "parse.h"
#include "stack.h"

double calculate(char *postfix_exp, double x, int *flag) {
    double nums[60] = {0}, res = 0;
    int top = -1, is_double = 0;
    while (*postfix_exp != '\0' && *flag) {
        if (*postfix_exp == 'x') {
            push_num(nums, &top, x);
        } else if (*postfix_exp >= '0' && *postfix_exp <= '9') {
            double curr = 0.;
            while (*postfix_exp != 'x' && *postfix_exp != ' ') {
                if (*postfix_exp != '.' && !is_double) {
                    curr = curr * 10 + (double)(*postfix_exp - 48);  // 48 потому что ascii 0 = 48
                    ++postfix_exp;
                } else if (*postfix_exp == '.' && !is_double) {
                    ++postfix_exp;
                    is_double = 1;
                } else {
                    curr = curr + (double)(*postfix_exp - 48) / pow(10, is_double);
                    ++postfix_exp;
                    ++is_double;
                }
            }
            --postfix_exp;
            is_double = 0;
            push_num(nums, &top, curr);
        } else if (*postfix_exp != ' ') {
            if (top < 0) {
                *flag = 0;
                break;
            }
            double a = pop_num(nums, &top);
            double b = pop_num(nums, &top);
            if (isnan(a) == 0) {
                *flag = base_operations(postfix_exp, a, b, &res);
                if (!(*flag)) *flag = func_operations(postfix_exp, a, b, &res, nums, &top);
                if (*flag == 1) push_num(nums, &top, res);
            }
        }
        ++postfix_exp;
    }
    return pop_num(nums, &top);
}

int base_operations(const char *postfix_exp, double a, double b, double *res) {
    int flag_res = 1;
    switch (*postfix_exp) {
        case '+':
            *res = b + a;
            break;
        case '-':
            *res = b - a;
            break;
        case '*':
            *res = b * a;
            break;
        case '/':
            if (a == 0) {
                flag_res = 0;
            } else {
                *res = b / a;
            }
            break;
        default:
            flag_res = 0;
    }
    return flag_res;
}

int func_operations(const char *postfix_exp, double a, double b, double *res, double *nums, int *top) {
    int flag_res = 1;
    switch (*postfix_exp) {
        case Fsin:
            *res = sin(a);
            break;
        case Fcos:
            *res = cos(a);
            break;
        case Ftan:
            *res = tan(a);
            break;
        case Fctg:
            if (tan(a) == 0) {
                flag_res = 0;
            } else {
                *res = 1 / tan(a);
            }
            break;
        case Fsqrt:
            if (a < 0) {
                flag_res = 0;
            } else {
                *res = sqrt(a);
            }
            break;
        case Fln:
            if (a <= 0) {
                flag_res = 0;
            } else {
                *res = log(a);
            }
            break;
        case Fun_minus:
            *res = -a;
            break;
        default:
            flag_res = 0;
    }
    if (flag_res == 1) push_num(nums, top, b);
    return flag_res;
}