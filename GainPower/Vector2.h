#pragma once

#include <cmath>
class Vector2
{
public:
	Vector2(float x, float y) {
		this->x = x;
		this->y = y;
	}

	Vector2() = default;

	Vector2 operator+(const Vector2& other) const {
		return Vector2(x + other.x, y + other.y);
	}

	Vector2 operator-(const Vector2& other) const {
		return Vector2(x - other.x, y - other.y);
	}

	Vector2 operator*(float scalar) const {
		return Vector2(x * scalar, y * scalar);
	}

	void operator+=(const Vector2& other) {
		x += other.x;
		y += other.y;
	}

	void operator-=(const Vector2& other) {
		x -= other.x;
		y -= other.y;
	}

	void operator*=(float scalar) {
		x *= scalar;
		y *= scalar;
	}

	float operator*(const Vector2& other) const {
		return x * other.x + y * other.y;
	}

	float getX() const {
		return x;
	}

	float getY() const {
		return y;
	}

	float length() const {
		return sqrt(x * x + y * y);
	}

	Vector2 normalize() const {
		float len = length();
		return Vector2(x / len, y / len);
	}

public:

	float x;
	float y;

};

