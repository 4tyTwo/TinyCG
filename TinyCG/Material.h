#pragma once
#include "geometry.h"
class Material
{
public:
	Material() : diffusional_color() {}
	Material(const Vec3f& color) : diffusional_color(color) {}
	inline Vec3f diffusionalColor() const { return diffusional_color; }
private:
	Vec3f diffusional_color;
};