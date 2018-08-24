#ifndef SPHERE_H
#define SPHERE_H

//互いに定義しアウト循環する
#include "ray.h"
#include "vec3.h"

class Sphere {
 public:
  Vec3 center;
  double radius;

  Sphere(const Vec3& center, double radius) : center(center), radius(radius){};

  bool intersect(const Ray& ray) const {
    double a = ray.direction.length2();
    double b = 2 * dot(ray.direction, ray.origin - center);
    double c = (ray.origin - center).length2() - radius * radius;
    double D = b * b - 4 * a * c;
    if (D < 0) return false;

    double t1 = (-b - std::sqrt(D)) / (2 * a);
    double t2 = (-b + std::sqrt(D)) / (2 * a);

    double t = t1;
    if (t < 0) {
      t = t2;
      if (t < 0) return false;
    }

    return true;
  };
};
#endif