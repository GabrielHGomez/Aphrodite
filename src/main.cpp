#include <SDL2/SDL.h>
#include <glad/glad.h>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include "window.hpp"

int SRC_WIDTH = 800;
int SRC_HEIGHT = 600;

unsigned int indices[]= {
  0, 1, 3,
  1, 2, 3
};
void processInput(bool &shouldClose) {
  const Uint8 *keystate = SDL_GetKeyboardState(nullptr);
  if (keystate[SDL_SCANCODE_ESCAPE]) {
    shouldClose = true;
  }
}

std::string loadShaderSrc(std::string path){
  std::ifstream file(path);

  std::stringstream buffer;
  buffer << file.rdbuf();
  return buffer.str();
}

unsigned int compileShader(GLenum type, std::string source, std::string name){
  unsigned int shader = glCreateShader(type);
  const char* src = source.c_str();
  glShaderSource(shader, 1, &src, NULL);
  glCompileShader(shader);

  int success;
  char infoLog[512];
  glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

  return shader;
}

unsigned int createShaderProgram(std::string vertexPath, std::string fragmentPath)
{
    std::string vertexSource = loadShaderSrc(vertexPath);
    std::string fragmentSource = loadShaderSrc(fragmentPath);

    unsigned int vertexShader = compileShader(GL_VERTEX_SHADER, vertexSource, "VERTEX");
    unsigned int fragmentShader = compileShader(GL_FRAGMENT_SHADER, fragmentSource, "FRAGMENT");

    unsigned int program = glCreateProgram();
    glAttachShader(program, vertexShader);
    glAttachShader(program, fragmentShader);
    glLinkProgram(program);

    int success;
    char infoLog[512];
    glGetProgramiv(program, GL_LINK_STATUS, &success);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    return program;
}

unsigned int loadTexture(const char* path, GLenum format){
  unsigned int texture;
  glGenTextures(1,&texture);
  glBindTexture(GL_TEXTURE_2D, texture);

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

  int width;
  int height;
  int nrChannels;

  unsigned char *data = stbi_load(path, &width, &height, &nrChannels, 0);
  if(data){
    glTexImage2D(GL_TEXTURE_2D,0, GL_RGB, width, height, 0 ,format, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
  }
  else{
    std::cout << "Failed to load texture: " << path << std::endl;
  }
  stbi_image_free(data);
  return texture;
}

void usage(){
  std::cout << "Usage: /gl_image_viewer /path/to/image/" << std::endl;
}
int main(int argc, char *argv[]) {
  if(argc < 2){
    usage();
    return 0;
  }
//  stbi_set_flip_vertically_on_load(true);
//  unsigned int shaderProgram = createShaderProgram("shaders/triangle.vert","shaders/triangle.frag");
//
//
//  glUseProgram(shaderProgram);
//  glUniform1i(glGetUniformLocation(shaderProgram, "tex1"), 0);
//  glUniform1i(glGetUniformLocation(shaderProgram, "tex2"), 1);
//
//
//
//    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//    glClear(GL_COLOR_BUFFER_BIT);
//
//    glUseProgram(shaderProgram);
//
//    float timeValue = SDL_GetTicks() / 1000.0f;
//    float greenValue = std::sin(timeValue) / 2.0f + 0.5f;
//    float offset = std::sin(timeValue) * 0.5f;
//
//    int colorLoc = glGetUniformLocation(shaderProgram, "uniformColor");
//    int offsetLoc = glGetUniformLocation(shaderProgram, "hOffset");
//    int useLoc = glGetUniformLocation(shaderProgram, "useUniform");
//
//    glUniform4f(colorLoc, 0.0f, greenValue, 0.0f, 1.0f);
//    glUniform1f(offsetLoc, offset);
//    glUniform1i(useLoc, 0);   
//
//    glActiveTexture(GL_TEXTURE0);
//    glBindTexture(GL_TEXTURE_2D, tex1);
//
//    glBindVertexArray(VAO);
//    glDrawArrays(GL_TRIANGLES, 0, 3); 
//
//    //SDL_GL_SwapWindow(window);
//  }
//
//  //SDL_GL_DeleteContext(ctx);
//  //SDL_DestroyWindow(window);
//  SDL_Quit();
  Window window("User_Window",SRC_WIDTH,SRC_HEIGHT);

  while(!window.close()){
    window.pollEvents();
  }
  return 0;

}
