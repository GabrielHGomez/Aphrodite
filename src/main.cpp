#include <SDL2/SDL.h>
#include <glad/glad.h>
//#define STB_IMAGE_IMPLEMENTATION
//#include "stb_image.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include "../include/window.hpp"
#include "../include/texture.hpp"
#include "../include/canvas.hpp"
#include "../include/shader.hpp"
#include "../include/GLContext.hpp"

int SRC_WIDTH = 800;
int SRC_HEIGHT = 600;

void usage(){
  std::cout << "Usage: /gl_image_viewer /path/to/image/" << std::endl;
}
int main(int argc, char *argv[]) {
  if(argc < 2){
    usage();
    return 0;
  }
  auto type = argv[2];
  GLctx application("Test", SRC_WIDTH, SRC_HEIGHT,type);
  application.loadImage(argv[1]);
  
  application.run();
  return 0;

}
