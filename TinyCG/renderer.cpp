#define _USE_MATH_DEFINES
#include <cmath>
#include <limits>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include "geometry.h"
#include "test_runner.h"

using namespace std;

Vec3f castRay(const Vec3f &orig, const Vec3f &dir, const Sphere &sphere)
{
	float sphere_distance = numeric_limits<float>::max();
	if (!sphere.rayIntersect(orig, dir, sphere_distance))
		return Vec3f(0.2f, 0.7f, 0.8f);
	return Vec3f(0.4f, 0.4f, 0.3f);
}

void render(const Sphere& sphere)
{
	const Vec3f camera_position(0, 0, 0);
	const float fov = M_PI/2;
    const int width = 1024;
    const int height = 768;
    vector<Vec3f> framebuffer(height * width);
    for (int i = 0; i < height; ++i)
		for (int j = 0; j < width; ++j)
		{
			float x =  (2 * (j + 0.5f) / static_cast<float>(width)  - 1) * tan(fov / 2.f) * width / static_cast<float>(height);
			float y = -(2 * (i + 0.5f) / static_cast<float>(height) - 1) * tan(fov / 2.f);
			Vec3f dir = Vec3f(x, y, -1);
			dir.normalize();
			framebuffer[j + i * width] = castRay(camera_position, dir, sphere);
		}
            
    ofstream ofs;
    ofs.open("res\\out.ppm", ios::binary);
    ofs << "P6" << endl << width << " " << height << endl << 255 << endl;
    for (size_t i = 0; i < height * width; ++i)
        for (size_t j = 0; j < 3; ++j)
            ofs << (char)(255 * max(0.f, min(1.f, framebuffer[i][j])));
    ofs.close();
}


int main()
{
	Sphere sphere(Vec3f(-3, 0, -16), 2);
	render(sphere);
	system("PAUSE");
    return 0;
}
