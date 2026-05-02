#include <SDL2/SDL.h>
#include <glad/glad.h>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include <iostream>

int SRC_WIDTH = 800;
int SRC_HEIGHT = 600;

void processInput(bool &shouldClose) {
  const Uint8 *keystate = SDL_GetKeyboardState(nullptr);
  if (keystate[SDL_SCANCODE_ESCAPE]) {
    shouldClose = true;
  }
}
int main(int argc, char *argv[]) {
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

  SDL_Window *window = SDL_CreateWindow(
      "LearnOpenGL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SRC_WIDTH,
      SRC_HEIGHT, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);

  SDL_GLContext ctx = SDL_GL_CreateContext(window);

  if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress)) {
    SDL_GL_DeleteContext(ctx);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return -1;
  }

  bool close = false;

  while (!close) {
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        close = true;
      } else if (event.type == SDL_WINDOWEVENT &&
                 event.window.event == SDL_WINDOWEVENT_SIZE_CHANGED) {
        glViewport(0, 0, event.window.data1, event.window.data2);
      }
    }
    processInput(close);

    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    SDL_GL_SwapWindow(window);
  }

  SDL_GL_DeleteContext(ctx);
  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
}
