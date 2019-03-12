#pragma once
#include <cmath>
#include <cfloat>

class Vec3f
{
public:
    Vec3f();
    Vec3f(float r, float g, float b);
    Vec3f(const Vec3f& other);
	float length() const;
	size_t size() const;
	void normalize();
    float operator[](int i) const;
	Vec3f operator+(const Vec3f& other) const;
	Vec3f operator-(const Vec3f& other) const;
	float operator*(const Vec3f& other) const;
	Vec3f operator/(const Vec3f& other) const;
	Vec3f operator*(const float multiplicator) const;
	Vec3f operator/(const float multiplicator) const;
private:
    float rgb[3];
};

class Sphere
{
public:
	Sphere(const Vec3f& center, float radius);
	bool rayIntersect(const Vec3f& origin, const Vec3f& direction, float& t0) const;
private:
	Vec3f center_;
	float radius_;
};