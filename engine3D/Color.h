#pragma once

typedef struct Color {
	double r, g, b, a;
	Color(double red, double green, double blue, double alpha = 1.0f) : r(red), g(green), b(blue), a(alpha) {}
	Color() : r(0), g(0), b(0), a(1) {}
}Color;

Color normalizeColors(Color read);