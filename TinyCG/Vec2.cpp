#include "Vec2f.h"

Vec2f::Vec2f() {}

Vec2f::Vec2f(float x, float y)
{
	data[0] = x;
	data[1] = y;
}

Vec2f::Vec2f(const float vec[])
{
	if (sizeof(vec) != sizeof(data))
		throw std::invalid_argument("Invalid array size");
	for (size_t i = 0; i < size_; ++i)
		data[i] = vec[i];
}

Vec2f::Vec2f(const Vec2f& other)
{
	for (size_t i = 0; i < size(); ++i)
		data[i] = other[i];
}

size_t Vec2f::size() const
{
	return size_;
}

float Vec2f::length() const
{
	// TODO: overflow checks
	float sum = 0;
	for (size_t i = 0; i < size_; ++i)
		sum += pow(data[i], 2);
	return sqrt(sum);
}

Vec2f Vec2f::normalize() const
{
	float len = length();
	float data_new[size_];
	for (int i = 0; i < size_; ++i)
		data_new[i] = data[i] / len;
	return Vec2f(data_new);
}

float Vec2f::operator[] (const int i) const
{
	return data[i];
}

Vec2f Vec2f::operator+(const Vec2f& other) const
{
	float data_new[size_];
	for (size_t i = 0; i < size_; ++i)
		data_new[i] = data[i] + other.data[i];
	return Vec2f(data_new);
}

Vec2f Vec2f::operator-(const Vec2f& other) const
{
	float data_new[size_];
	for (size_t i = 0; i < size_; ++i)
		data_new[i] = data[i] - other.data[i];
	return Vec2f(data_new);
}

float Vec2f::operator*(const Vec2f& other) const
{
	float sum = 0;
	for (size_t i = 0; i < size_; ++i)
		sum += data[i] * other.data[i];
	return sum;
}

Vec2f Vec2f::operator*(const float multiplicator) const
{
	float data_new[size_];
	for (size_t i = 0; i < size_; ++i)
		data_new[i] = data[i] * multiplicator;
	return Vec2f(data_new);
}