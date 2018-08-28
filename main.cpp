#include "camera.h"
#include "image.h"
#include "triangle.h"
#include "vec3.h"

int main() {
  Image img(512, 512);
  Camera cam(Vec3(0, 0, -3), Vec3(0, 0, 1));

  Triangle triangle(Vec3(0, 0, 0), Vec3(1, 0, 0), Vec3(0, 1, 0));

  for (int i = 0; i < img.width; i++) {
    for (int j = 0; j < img.height; j++) {
      double u = (2.0 * i - img.width) / img.width;
      double v = (2.0 * j - img.height) / img.height;
      Ray ray = cam.getRay(u, v);

      if (triangle.intersect(ray)) {
        img.setPixel(i, j, Vec3(1, 1, 1));
      } else {
        img.setPixel(i, j, Vec3(0, 0, 0));
      }
    }
  }

  img.ppm_output();
}