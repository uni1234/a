#ifndef TRIANGLE_H
#define TRIANGLE_H

class Triangle {
 public:
  Vec3 A;
  Vec3 B;
  Vec3 C;
  bool intersect(const Ray& ray) {}
}