#include "stack.h"

void push_oper(char *stack, int *top, char op) {
    ++(*top);
    stack[*top] = op;
}

char pop_oper(const char *stack, int *top) {
    char op = stack[*top];
    --(*top);
    return op;
}

void push_num(double *stack, int *top, double num) {
    ++(*top);
    stack[*top] = num;
}

double pop_num(const double *stack, int *top) {
    double num = stack[*top];
    --(*top);
    return num;
}