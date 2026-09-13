#pragma once

#include <optional>
#include "texture.hpp"
#include "window.hpp"
#include "canvas.hpp"
#include "shader.hpp"
#include <string_view>

//i dont like how openGLctx looks TODO::Change this to something more meaningful
class GLctx{
public:
  GLctx(std::string_view title, int width, int height,std::string_view type);
  void loadImage(std::string_view path);
  void run();
  void render();
private:
  //all cap or not cap that is the question?
  Window window_;
  std::optional<texture> texture_;
  canvas canvas_;
  shader shader_;

  std::string_view title_ = "";
  int width = 0;
  int height = 0;
};
