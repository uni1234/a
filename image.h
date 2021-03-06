#ifndef IMAGE_H
#define IMAGE_H

#include <fstream>
#include <iostream>
#include "vec3.h"

class Image {
 public:
  int width;
  int height;
  Vec3* data;

  Image(int width, int height) : width(width), height(height) {
    data = new Vec3[width * height];
  };

  ~Image() { delete[] data; };
  Vec3 getPixel(int i, int j) const {
    return data[width * i + j];
  };  // classのメンバ変数にすでに設定されているので、引数に含む必要なし
  Vec3 setPixel(int i, int j, const Vec3& color) {
    return data[width * i + j] = color;
  };

  void ppm_output() const {
    std::ofstream file("output.ppm");
    file << "P3" << std::endl;
    file << width << " " << height << std::endl;
    file << "255" << std::endl;
    for (int i = 0; i < width; i++) {
      for (int j = 0; j < height; j++) {
        Vec3 color = 255 * this->getPixel(i, j);
        if (color.x < 0) color.x = -color.x;  //書き方めんどい？かえたい
        if (color.y < 0) color.y = -color.y;
        if (color.z < 0) color.z = -color.z;
        int r = std::min((int)color.x, 255);
        int g = std::min((int)color.y, 255);
        int b = std::min((int)color.z, 255);
        file << r << " " << g << " " << b << std::endl;
      }
    }
    file.close();
  };
};
#endif