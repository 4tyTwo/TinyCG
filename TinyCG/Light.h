#pragma once
#include "Vec3f.h"
class Light
{
public:
	Light(const Vec3f& position, float intensity) : position_(position), intensity_(intensity) {}
	inline Vec3f position() const { return position_; }
	inline float intensity() const { return intensity_; }
private:
	Vec3f position_;
	float intensity_;
};