#include "../include/texture.hpp"
#include <stdexcept>
#include <string>
#define STB_IMAGE_IMPLEMENTATION
#include "../external/stb_image.h"

texture::texture(std::string_view path){
  glGenTextures(1,&texture_);
  glBindTexture(GL_TEXTURE_2D, texture_);

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

  stbi_set_flip_vertically_on_load(true);

  int w = 0;
  int h = 0;
  int c = 0;

  unsigned char* pixels = stbi_load(std::string(path).c_str(), &w, &h, &c, 0); //wow that syntax should I even use string view at this point
  if(!pixels){
    throw std::runtime_error("Texture: failed to load an image: " + std::string(path));
  }

  width_ = w;
  height_ = h;
  channels_ = c;
  //have to chack format since this should work for different cases
  GLenum format = GL_RGB;
  if(c = 1 && c == 2){
    format = GL_RED;
  }
  else if(c == 3){
    format = GL_RGB;
  }
  else if(c == 4){
    format = GL_RGBA;
  }
  glTexImage2D(GL_TEXTURE_2D, 0, static_cast<GLint>(format), w, h, 0,format, 
		  GL_UNSIGNED_BYTE, pixels);
  glGenerateMipmap(GL_TEXTURE_2D);

  stbi_image_free(pixels);

}

texture::~texture(){
  glDeleteTextures(1,&texture_);
}

void texture::bind(){
  glActiveTexture(GL_TEXTURE0);
  glBindTexture(GL_TEXTURE_2D, texture_);
}
