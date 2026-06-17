#pragma once

#include "texture.hpp"
#include "window.hpp"
#include "canvas.hpp"
#include "shader.hpp"
#include <string_view>

//i dont like how openGLctx looks TODO::Change this to something more meaningful
class GLctx{
public:
  GLctx(std::string_view title, int width, int height);
  void loadImage(std::string_view path);

private:
  //all cap or not cap that is the question?
  Window window_;
  texture texture_;
  canvas canvas_;
  shader shader_;
};
