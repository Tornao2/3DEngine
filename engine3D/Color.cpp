#include "Color.h"

Color normalizeColors(Color read) {
    if (read.r < 0)
        read.r = 0;
    else if (read.r > 255)
        read.r = 255;
    if (read.g < 0)
        read.g = 0;
    else if (read.g > 255)
        read.g = 255;
    if (read.b < 0)
        read.b = 0;
    else if (read.b > 255)
        read.b = 255;
    if (read.a < 0)
        read.a = 0;
    else if (read.a > 255)
        read.a = 255;
    read.r /= 255;
    read.g /= 255;
    read.b /= 255;
    read.a /= 255;
    return read;
}