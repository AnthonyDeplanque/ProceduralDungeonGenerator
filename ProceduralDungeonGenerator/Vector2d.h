#pragma once
class Vector2d
{
public:
	Vector2d() = default;
	Vector2d(int x, int y);

	inline void setX(int p_x) { x = p_x; };
	inline void setY(int p_y) { y = p_y; };
	inline int getX() { return x; };
	inline int getY() { return y; };

	void operator+=(Vector2d const other);

private:
	int x{0};
	int y{0};

};

