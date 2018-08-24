#ifndef RAY_H
#define RAY_H
#include "vec3.h"

class Ray {
 public:
  Vec3 origin;
  Vec3 direction;
  Ray(const Vec3& origin, const Vec3& direction)
      : origin(origin), direction(direction){};
};
#endif
/*Vec3(double _x,double _y,double _z){
    x = _x;
    y = _y;
    z = _z;
}とやっていること同じ*/
