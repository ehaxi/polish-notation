#include "draw.h"

#include <math.h>
#include <stdio.h>

#include "calc.h"

#define WIDTH 80
#define HEIGHT 25
#define PI 3.141592654

void draw_graphic(char *postfix_exp, int *flag) {
    double func[WIDTH] = {0};
    if (*flag) {
        int cnt = 0;
        for (double x = 0.; x < 4. * PI; x += 4. * PI / WIDTH) {
            func[cnt] = calculate(postfix_exp, x, flag);
            ++cnt;
        }
    }
    if (*flag) {
        for (int row = 0; row <= HEIGHT; ++row) {
            double y = -1. + row * 2. / HEIGHT;
            for (int coord_x = 0; coord_x < WIDTH; ++coord_x) {
                if (fabs(func[coord_x] - y) <= 2. / HEIGHT / 2.) {
                    putchar('*');
                } else {
                    putchar('.');
                }
            }
            putchar('\n');
        }
    }
    if (!(*flag)) {
        printf("n/a");
    }
}