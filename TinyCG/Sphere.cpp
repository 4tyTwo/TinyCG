#include "geometry.h"

Sphere::Sphere(const Vec3f& center, float radius) : center_(center), radius_(radius) {}

bool Sphere::rayIntersect(const Vec3f& origin, const Vec3f& direction, float& t0) const
{
	Vec3f L = center_ - origin;
	float tca = L * direction; // what tca means?
	float dsq = L * L - tca * tca;
	if (dsq > radius_ * radius_)
		return false;
	float thc = sqrtf(radius_ * radius_ - dsq);
	t0 = tca - thc;
	if (t0 < 0)
	{
		t0 = tca + thc;
		if (t0 < 0)
			return false;
	}
	return true;
	

	/*float dist = distanceToLine(origin, direction);
	if (dist > radius_)
		return false;
	return true;*/
}