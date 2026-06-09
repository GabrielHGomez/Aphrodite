#include "window.hpp"
#include <stdexcept>

Window::Window(std::string_view title, int width, int height): title_(title), width_(width), height_(height) {
  SDL_Init(SDL_INIT_VIDEO);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

  window_ = SDL_CreateWindow(
    "LearnOpenGL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width_,
    height_, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);

  SDL_GLContext ctx = SDL_GL_CreateContext(window_); 
  if(!window_){
    throw std::runtime_error("Window Creation failed");
  } 
  
  ctx_ = SDL_GL_CreateContext(window_);

  if(!ctx_){
    throw std::runtime_error("OpenGL Context failed to create");
  } 

  if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress)) {
    SDL_GL_DeleteContext(ctx);
    SDL_DestroyWindow(window_);
    SDL_Quit();
    throw std::runtime_error("Failed to load glad");
    }  
 }

Window::~Window(){
  std::cout << "Window Deconstructor called" << std::endl;
  SDL_DestroyWindow(window_);
}
