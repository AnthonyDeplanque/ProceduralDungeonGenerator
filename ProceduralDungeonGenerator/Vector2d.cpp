#include "Vector2d.h"

Vector2d::Vector2d(int p_x, int p_y) {
	x = p_x;
	y = p_y;
}

void Vector2d::operator+=(Vector2d other) {
	x += other.getX();
	y += other.getY();
}