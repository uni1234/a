#ifndef PARALLEL_H
#define PARALLEL_H

#include "ray.h"
#include "vec3.h"

class Parallel {
 public:
  Vec3 A;
  Vec3 B;
  Vec3 C;
  Parallel(const Vec3& A, const Vec3& B, const Vec3& C) : A(A), B(B), C(C){};
  bool intersect(const Ray& ray) const {
    Vec3 a = A - B;
    Vec3 b = C - B;
    Vec3 d = -1 * ray.direction;
    Vec3 n = normalize(cross(a, b));
    Vec3 p = ray.origin - B;
    if (dot(ray.direction, n) == 0) {
      return false;
    }
    double k = det3(a, b, d);
    double s = det3(p, b, d) / k;
    double t = det3(a, p, d) / k;
    double l = det3(a, b, p) / k;
    if (s > 1 || s < 0) return false;
    if (t > 1 || t < 0) return false;

    return true;
    };
};
#endif