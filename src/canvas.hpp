#pragma once
#include <glad/glad.h>

class canvas{
public:
  canvas();
  ~canvas();
  void draw() const;
  

private:
  unsigned int vao_ = 0;
  unsigned int vbo_ = 0;
  int vertextCount_ = 0;
};
