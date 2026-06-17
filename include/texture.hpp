#pragma once
#include <glad/glad.h>
#include <string_view>

class texture{
public:
  texture(std::string_view);
  ~texture();
  void bind(unsigned int id);
  int width() const {return width_;}
  int height() const {return height_;}
  int channels() const {return channels_;}
  unsigned int texture_id() const {return texture_;}

private:
  int width_ = 0;
  int height_ = 0;
  int channels_ = 0;
  unsigned int texture_ = 0;

};
