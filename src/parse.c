#include "parse.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack.h"

int is_operator(char symbol) {
    return symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/' || symbol == '^';
}

int is_digit(char symbol) { return symbol == 'x' || (symbol >= '0' && symbol <= '9'); }

int is_func(const char *function, int i, int len) {
    int res = 0;
    if (i + 2 < len && function[i] == 's' && function[i + 1] == 'i' && function[i + 2] == 'n') {
        res = fsin;
    } else if (i + 2 < len && function[i] == 'c' && function[i + 1] == 'o' && function[i + 2] == 's') {
        res = fcos;
    } else if (i + 2 < len && function[i] == 't' && function[i + 1] == 'a' && function[i + 2] == 'n') {
        res = ftan;
    } else if (i + 2 < len && function[i] == 'c' && function[i + 1] == 't' && function[i + 2] == 'g') {
        res = fctg;
    } else if (i + 3 < len && function[i] == 's' && function[i + 1] == 'q' && function[i + 2] == 'r' &&
               function[i + 3] == 't') {
        res = fsqrt;
    } else if (i + 1 < len && function[i] == 'l' && function[i + 1] == 'n') {
        res = fln;
    } else if (i < len && function[i] == '~') {
        res = fun_minus;
    }
    return res;
}

int get_priority(char operator) {
    int priority = -1;
    switch (operator) {
        case '+':
        case '-':
            priority = 1;
            break;
        case '/':
        case '*':
            priority = 2;
            break;
        case Fsin:
        case Fcos:
        case Ftan:
        case Fctg:
        case Fsqrt:
        case Fln:
        case Fun_minus:
            priority = 3;
            break;
    }
    return priority;
}

void validate(char *stack) {
    int flag_type = 1;
    for (int i = 0; stack[i] != '\0'; ++i) {
        if (is_operator(stack[i])) {
            if (flag_type && stack[i] == '-') {
                stack[i] = '~';
            }
            flag_type = 1;
        } else if (is_digit(stack[i])) {
            flag_type = 0;
        }
    }
}

int bracket_cnt(const char *line) {
    int flag_bracket = 1;
    int left_cnt = 0, right_cnt = 0;
    for (int i = 0; line[i] != '\0'; ++i) {
        if (line[i] == '(') {
            ++left_cnt;
        } else if (line[i] == ')') {
            ++right_cnt;
            if (line[i + 1] == '(') {
                flag_bracket = 0;
                break;
            }
        }
    }
    return (flag_bracket && left_cnt == right_cnt);
}

int unar_valid(const char *line) {
    int flag_unar = 1;
    for (int i = 0; line[i] != '\0'; ++i) {
        if ((is_operator(line[i]) == 1 || line[i] == '~') &&
            (is_operator(line[i + 1]) == 1 || line[i + 1] == '~')) {
            flag_unar = 0;
            break;
        }
    }
    return flag_unar;
}

char *input_func(int *flag) {
    char *function = malloc(60 * sizeof(char));
    char ch = '_';
    int cnt = 0;
    while (ch != '\n' && *flag) {
        if (cnt > 60) {
            *flag = 0;
        } else {
            ch = getc(stdin);
            if (ch != ' ' && ch != '\n') {
                function[cnt] = ch;
                ++cnt;
            }
        }
    }
    function[cnt] = '\0';
    validate(function);
    return function;
}

void pushing_operators(int func, char stack[60], int *top, const char *function, int *point) {
    switch (func) {
        case 0:
            push_oper(stack, top, function[*point]);
            break;
        case 1:
            push_oper(stack, top, Fsin);
            *point += 2;
            break;
        case 2:
            push_oper(stack, top, Fcos);
            *point += 2;
            break;
        case 3:
            push_oper(stack, top, Ftan);
            *point += 2;
            break;
        case 4:
            push_oper(stack, top, Fctg);
            *point += 2;
            break;
        case 5:
            push_oper(stack, top, Fsqrt);
            *point += 3;
            break;
        case 6:
            push_oper(stack, top, Fln);
            *point += 1;
            break;
        case 7:
            push_oper(stack, top, Fun_minus);
            break;
    }
}

char *converter(const char *function, int len, int *flag) {
    char *chars_stack = calloc((len * 2 + 1), sizeof(char)), stack[60] = {0};
    int top = -1, j = 0, i = 0, flag_conv = 0;
    for (; i < len && *flag && j < 2 * len; ++i) {
        if (is_digit(function[i])) {
            while (is_digit(function[i]) || function[i] == '.') {
                chars_stack[j++] = function[i];
                flag_conv = 1;
                ++i;
            }
            --i;
        } else if (function[i] == '(') {
            push_oper(stack, &top, function[i]);
        } else if (function[i] == ')') {
            while (top > -1 && stack[top] != '(') {
                chars_stack[j++] = pop_oper(stack, &top);
                chars_stack[j++] = ' ';
            }
            if (top > -1 && stack[top] != '(')
                *flag = 0;
            else
                --top;
        } else if (is_operator(function[i]) || is_func(function, i, len)) {
            int func = is_func(function, i, len);
            while (!func && top > -1 && get_priority(stack[top]) >= get_priority(function[i])) {
                chars_stack[j++] = pop_oper(stack, &top);
                chars_stack[j++] = ' ';
            }
            pushing_operators(func, stack, &top, function, &i);
        } else
            *flag = 0;
        if (flag_conv) {
            chars_stack[j++] = ' ';
            flag_conv = 0;
        }
    }
    while (top > -1) {
        chars_stack[j++] = pop_oper(stack, &top);
        chars_stack[j++] = ' ';
    }
    chars_stack[j] = '\0';
    return chars_stack;
}