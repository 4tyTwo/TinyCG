#pragma once
#include <cmath>
#include <cfloat>
#include <stdexcept>

class Vec2f
{
public:
	Vec2f();
	Vec2f(float x, float y);
	Vec2f(const float vec[]);
	Vec2f(const Vec2f& other);
	float length() const;
	size_t size() const;
	Vec2f normalize() const;
	float operator[](int i) const;
	Vec2f operator+(const Vec2f& other) const;
	Vec2f operator-(const Vec2f& other) const;
	float operator*(const Vec2f& other) const;
	Vec2f operator*(const float multiplicator) const;
private:
	static const size_t size_ = 2;
	float data[size_];
};