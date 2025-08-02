#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "calc.h"
#include "draw.h"
#include "parse.h"
#include "stack.h"

int main() {
    int flag = 1;
    char *functions = input_func(&flag);
    if (functions != NULL && flag) {
        if (!bracket_cnt(functions) || !unar_valid(functions)) {
            printf("n/a");
        } else {
            int len = strlen(functions);
            char *postfix_exp = converter(functions, len, &flag);
            if (postfix_exp != NULL && flag) {
                draw_graphic(postfix_exp, &flag);
                free(postfix_exp);
            } else if (postfix_exp != NULL && flag) {
                printf("n/a");
                free(postfix_exp);
            }
        }
    } else {
        printf("n/a");
    }
    if (functions != NULL) {
        free(functions);
    }
    return 0;
}