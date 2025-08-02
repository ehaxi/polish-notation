#ifndef PARSE_H
#define PARSE_H

#define fsin 1
#define fcos 2
#define ftan 3
#define fctg 4
#define fsqrt 5
#define fln 6
#define fun_minus 7

#define Fsin 's'
#define Fcos 'c'
#define Ftan 't'
#define Fctg 'g'
#define Fsqrt 'q'
#define Fln 'l'
#define Fun_minus '~'

int is_operator(char symbol);
int is_digit(char symbol);
int is_func(const char *function, int i, int len);
int get_priority(char operator);
void validate(char *stack);
int bracket_cnt(const char *line);
int unar_valid(const char *line);
char *input_func(int *flag);
void pushing_operators(int func, char stack[60], int *top, const char *function, int *point);
char *converter(const char *function, int len, int *flag);

#endif
