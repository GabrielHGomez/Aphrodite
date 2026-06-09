#pragma once
#include <iostream>
#include <string_view>
#include <string>
#include <SDL2/SDL.h>
#include <glad/glad.h>

//should I make this user inputted? I dont know
//int SRC_WIDTH = 800;
//int SRC_HEIGHT = 600;

class Window{
public:
  Window(std::string_view title, int width, int height);

  ~Window();

  int width() const {return width_;}
  int height() const {return height_;}


private:
  SDL_Window* window_ = nullptr;
  SDL_GLContext ctx_ = nullptr;
  int width_ = 0;
  int height_ = 0;
  std::string_view title_ = "";
};
