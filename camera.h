#ifndef CAMERA_H
#define CAMERA_H

#include "ray.h"
#include "vec3.h"
class Camera {
 public:
  Vec3 camPos;
  Vec3 camForward;
  Vec3 camRight;  // Camera のとこで参照渡ししないのにここに書くのは、 Camera
                  // のインストラクタ?でも使うため(他の関数で使う)
  Vec3 camUp;

  Camera(const Vec3& camPos, const Vec3& camForward)
      : camPos(camPos), camForward(camForward) {
    camRight =
        -1 * normalize(cross(camForward, Vec3(0, 1, 0)));  //横 上下　奥行き
    camUp = normalize(
        cross(camForward, camRight));  //左手　フレミング　1 => 親指, 2 =>
                                       //人差し指,外積の向き -> 中指
  };
  Ray getRay(double u, double v) const {
    Vec3 pinhole = camPos + camForward;
    Vec3 sensorPos = camPos + u * camRight + v * camUp;
    return Ray(sensorPos, normalize(pinhole - sensorPos));
  };
};
#endif