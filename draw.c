#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

//Insert your line algorithm here
void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {
    int x = x0;
    int y = y0;
    int delta_y = y1 - y0; // A
    int delta_x = x1 - x0; // B
    float slope = 2 * delta_y / delta_x;

    if (slope > 0) {
        // Octant 2 & 6
        if (slope > 2) {

        }
        // Octant 1 & 5
        else {
            int d = 2 * (delta_y) + delta_x;

            while (x <= x1) {
                plot(s, c, x, y);
                if (d > 0) {
                    y++;
                    d += 2 * (delta_x);
                }
                x++;
                d += 2 * (delta_y);
            }
        }
    }
    // Octant 8 & 4
    else if (slope > -2) {

    }
    // Octant 7 & 3
    else {

    }

}
