#define _USE_MATH_DEFINES
#include <cmath>
#include <limits>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include "geometry.h"
#include "Vec3f.h"
using namespace std;


bool sceneIntersect(const Vec3f& orig, const Vec3f& dir, const vector<Sphere>& spheres, Vec3f& hit, Vec3f& N, Material& material)
{
	float sphere_distance = numeric_limits<float>::max();
	for (size_t i = 0; i < spheres.size(); ++i)
	{
		float dist_i;
		if (spheres[i].rayIntersect(orig, dir, dist_i) && dist_i < sphere_distance)
		{
			sphere_distance = dist_i;
			hit = orig + dir * dist_i;
			N = (hit - spheres[i].center()).normalize();
			material = spheres[i].material();
		}
	}
	return sphere_distance < 1000;
}

Vec3f castRay(const Vec3f &orig, const Vec3f &dir, const vector<Sphere>& spheres)
{
	Vec3f point, N;
	Material material;
	if (!sceneIntersect(orig, dir, spheres, point, N, material))
		return Vec3f(0.2f, 0.7f, 0.8f);
	return material.diffusionalColor();
}

void saveToFile(string filename, int w, int h, const vector<Vec3f>& buffer)
{
	ofstream ofs;
	ofs.open(filename, ios::binary);
	ofs << "P6" << endl << w << " " << h << endl << 255 << endl;
	for (size_t i = 0; i < h * w; ++i)
		for (size_t j = 0; j < buffer[0].size(); ++j)
			ofs << (char)(255 * max(0.f, min(1.f, buffer[i][j])));
	ofs.close();
}

void render(const vector<Sphere>& spheres)
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
			Vec3f dir = Vec3f(x, y, -1).normalize();
			framebuffer[j + i * width] = castRay(camera_position, dir, spheres);
		}
	saveToFile("res\\out.ppm", width, height, framebuffer);	
}

int main()
{
	vector<Sphere> spheres;
	Material bronze(Vec3f(205, 127, 50).normalize());
	Material dark_wood(Vec3f(133, 94, 66).normalize());
	spheres.push_back(Sphere(Vec3f(-1, -1.5, -12), 2, dark_wood));
	spheres.push_back(Sphere(Vec3f(-3, 0, -16), 2, bronze));
	render(spheres);
	system("PAUSE");
    return 0;
}
