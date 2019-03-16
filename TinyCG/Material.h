#pragma once
#include "Vec3f.h"
#include "Vec2f.h"
class Material
{
public:
	Material() : diffusional_color(), albedo(1, 0), specular_exp() {}
	Material(const Vec3f& color, const Vec2f& albedo, float specular) : diffusional_color(color), albedo(albedo), specular_exp(specular) {}
	inline Vec3f diffusionalColor() const { return diffusional_color; }
private:
	Vec3f diffusional_color;
	Vec2f albedo;
	float specular_exp;
};