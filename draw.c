#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {
    int x = x0;
    int y = y0;
    // Make sure we go from left to right
    if (x0 > x1 && x0 != 0) {
        x = x1;
        x1 = x0;
        y = y1;
        y1 = y0;
    }
    int delta_y = y1 - y;
    int delta_x = x1 - x;
    int A = delta_y;
    int B = -1 * delta_x;
    int d;
    printf("delta_y: %d, delta_x: %d\n", delta_y, delta_x);

    if (delta_y * delta_x >= 0) {
        // Octant 1 & 5
        if (delta_y <= delta_x) {
            printf("OCTANT 1\n");
            d = 2 * A + B;

            while (x <= x1) {
                plot(s, c, x, y);
                if (d > 0) {
                    y++;
                    d += 2 * B;
                }
                x++;
                d += 2 * A;
            }
        }
        // Octant 2 & 6
        else {
            printf("OCTANT 2\n");
            d = A + 2 * B;
        
            while (y <= y1) {
                plot(s, c, x, y);
                if (d < 0) {
                    x++;
                    d += 2 * A;
                }
                y++;
                d += 2 * B;
            }
        }
    }
    // Octant 8 & 4
    else if (abs(delta_y) <= abs(delta_x)) {
        printf("OCTANT 8\n");
        d = A - 2 * B;
        
        while (x <= x1) {
            plot(s, c, x, y);
            if (d < 0) {
                y--;
                d -= 2 * B;
            }
            x++;
            d += 2 * A;
        } 
    }
    // Octant 7 & 3
    else {
        printf("OCTANT 7\n");
        d = 2 * A - B;

        while (y >= y1) {
            plot(s, c, x, y);
            if (d > 0) {
                x++;
                d += 2 * A;
            }
            y--;
            d -= 2 * B;
        }
    }
}
