#include "Vec3f.h"

Vec3f::Vec3f() {}

Vec3f::Vec3f(float r, float g, float b)
{
	rgb[0] = r;
	rgb[1] = g;
	rgb[2] = b;
}

Vec3f::Vec3f(const Vec3f& other)
{

	for (int i = 0; i < 3; ++i)
		rgb[i] = other[i];
}

size_t Vec3f::size() const
{
	return sizeof(rgb) / sizeof(rgb[0]); // or just return 3
}

float Vec3f::length() const
{
	// TODO: overflow checks
	float sum = 0;
	for (int i = 0; i < size(); ++i)
		sum += pow(rgb[i], 2);
	return sqrt(sum);
}

Vec3f Vec3f::normalize() const
{
	float len = length();
	float rgb_new[3];
	for (int i = 0; i < size(); ++i)
		rgb_new[i] = rgb[i] / len;
	return Vec3f(rgb_new[0], rgb_new[1], rgb_new[2]);
}

float Vec3f::operator[] (const int i) const
{
	return rgb[i];
}

Vec3f Vec3f::operator+(const Vec3f& other) const
{
	float rgb_new[3];
	for (int i = 0; i < 3; ++i)
		rgb_new[i] = rgb[i] + other.rgb[i];
	return Vec3f(rgb_new[0], rgb_new[1], rgb_new[2]);
}

Vec3f Vec3f::operator-(const Vec3f& other) const
{
	float rgb_new[3];
	for (int i = 0; i < 3; ++i)
		rgb_new[i] = rgb[i] - other.rgb[i];
	return Vec3f(rgb_new[0], rgb_new[1], rgb_new[2]);
}

float Vec3f::operator*(const Vec3f& other) const
{
	float sum = 0;
	for (int i = 0; i < 3; ++i)
		sum += rgb[i] * other.rgb[i];
	return sum;
}

Vec3f Vec3f::operator/(const Vec3f& other) const
{
	float rgb_new[3];
	for (int i = 0; i < 3; ++i)
		rgb_new[i] = rgb[i] / other.rgb[i];
	return Vec3f(rgb_new[0], rgb_new[1], rgb_new[2]);
}


Vec3f Vec3f::operator*(const float multiplicator) const
{
	float rgb_new[3];
	for (int i = 0; i < 3; ++i)
		rgb_new[i] = rgb[i] * multiplicator;
	return Vec3f(rgb_new[0], rgb_new[1], rgb_new[2]);
}

Vec3f Vec3f::operator/(const float divisor) const
{
	float rgb_new[3];
	for (int i = 0; i < 3; ++i)
		rgb_new[i] = rgb[i] / divisor;
	return Vec3f(rgb_new[0], rgb_new[1], rgb_new[2]);
}