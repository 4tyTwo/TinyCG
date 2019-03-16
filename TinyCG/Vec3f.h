#pragma once
#include <cmath>
#include <cfloat>
#include <stdexcept>

class Vec3f
{
public:
	Vec3f();
	Vec3f(float x, float y, float z);
	Vec3f(const float vec[]);
	Vec3f(const Vec3f& other);
	float length() const;
	size_t size() const;
	Vec3f normalize() const;
	float operator[](int i) const;
	Vec3f operator+(const Vec3f& other) const;
	Vec3f operator-(const Vec3f& other) const;
	float operator*(const Vec3f& other) const;
	Vec3f operator*(const float multiplicator) const;
	Vec3f operator-() const;
private:
	static const size_t size_ = 3;
	float data[size_];
};
