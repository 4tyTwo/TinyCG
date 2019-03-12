#pragma once
#include "Vec3f.h"
#include "Material.h"
class Sphere
{
public:
	Sphere(const Vec3f& center, float radius, const Material& material);
	bool rayIntersect(const Vec3f& origin, const Vec3f& direction, float& t0) const;
	inline Vec3f center() const { return center_; }
	inline float radius() const { return radius_; }
	inline Material material() const { return material_; }
private:
	Material material_;
	Vec3f center_;
	float radius_;
};

