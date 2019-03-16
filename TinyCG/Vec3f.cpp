#include "Vec3f.h"

Vec3f::Vec3f() {}

Vec3f::Vec3f(float x, float y, float z)
{
	data[0] = x;
	data[1] = y;
	data[2] = z;
}

Vec3f::Vec3f(const float vec[])
{
	for (size_t i = 0; i < size_; ++i)
		data[i] = vec[i];
}

Vec3f::Vec3f(const Vec3f& other)
{
	for (size_t i = 0; i < size(); ++i)
		data[i] = other[i];
}

size_t Vec3f::size() const
{
	return size_;
}

float Vec3f::length() const
{
	// TODO: overflow checks
	float sum = 0;
	for (size_t i = 0; i < size_; ++i)
		sum += pow(data[i], 2);
	return sqrt(sum);
}

Vec3f Vec3f::normalize() const
{
	float len = length();
	float data_new[size_];
	for (int i = 0; i < size_; ++i)
		data_new[i] = data[i] / len;
	return Vec3f(data_new);
}

float Vec3f::operator[] (const int i) const
{
	return data[i];
}

Vec3f Vec3f::operator+(const Vec3f& other) const
{
	float data_new[size_];
	for (size_t i = 0; i < size_; ++i)
		data_new[i] = data[i] + other.data[i];
	return Vec3f(data_new);
}

Vec3f Vec3f::operator-(const Vec3f& other) const
{
	float data_new[size_];
	for (size_t i = 0; i < size_; ++i)
		data_new[i] = data[i] - other.data[i];
	return Vec3f(data_new);
}

float Vec3f::operator*(const Vec3f& other) const
{
	float sum = 0;
	for (size_t i = 0; i < size_; ++i)
		sum += data[i] * other.data[i];
	return sum;
}

Vec3f Vec3f::operator*(const float multiplicator) const
{
	float data_new[size_];
	for (size_t i = 0; i < size_; ++i)
		data_new[i] = data[i] * multiplicator;
	return Vec3f(data_new);
}

Vec3f Vec3f::operator-() const
{
	return (*this * -1);
}