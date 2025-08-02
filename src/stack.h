#ifndef STACK_H
#define STACK_H

void push_oper(char *stack, int *top, char op);
char pop_oper(const char *stack, int *top);

void push_num(double *stack, int *top, double num);
double pop_num(const double *stack, int *top);

#endif