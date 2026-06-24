#include "../include/shader.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

shader::shader(std::string_view vertSrc, std::string_view fragSrc){
  std::string vertexCode;
  std::string fragCode;
  std::ifstream shaderFiles;
  std::ifstream fragFiles;

  try{
    shaderFiles.open(static_cast<std::string>(vertSrc));
    fragFiles.open(static_cast<std::string>(fragSrc));

    std::stringstream shaderStream;
    std::stringstream fragStream;

    shaderStream << shaderFiles.rdbuf();
    fragStream << fragFiles.rdbuf();

    shaderFiles.close();
    fragFiles.close();

    vertexCode = shaderStream.str();
    fragCode = fragStream.str();

    std::cout << "vert source length: " << vertexCode.size()
    << "  frag source length: " << fragCode.size() << std::endl;
  }
  catch(std::ifstream::failure e){
    std::cout << "ERROR::loading shader files" << std::endl;
  }

  const char* shaderCode = vertexCode.c_str();
  const char* fragshaderCode = fragCode.c_str();

  unsigned int vertex;
  unsigned int fragment;

  int ok = 0;
  char log[512];

  vertex = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertex, 1, &shaderCode, NULL);
  glCompileShader(vertex);
  glGetShaderiv(vertex, GL_COMPILE_STATUS, &ok);
  if(!ok){ 
    glGetShaderInfoLog(vertex, 512, nullptr, log);
    std::cout << "VERTEX compile failed:\n" << log << std::endl; 
  }

  fragment = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragment, 1, &fragshaderCode, NULL);
  glCompileShader(fragment);
  glGetShaderiv(fragment, GL_COMPILE_STATUS, &ok);
  if(!ok){ 
    glGetShaderInfoLog(fragment, 512, nullptr, log);
    std::cout << "FRAG compile failed:\n" << log << std::endl; 
  }

  program_ = glCreateProgram();
  glAttachShader(program_, vertex);
  glAttachShader(program_, fragment);
  glLinkProgram(program_);
  
  glGetProgramiv(program_, GL_LINK_STATUS, &ok);
  if(!ok){ 
    glGetProgramInfoLog(program_, 512, nullptr, log);
    std::cout << "LINK compile failed:\n" << log << std::endl; 
  }

  glDeleteShader(vertex);
  glDeleteShader(fragment);

}
shader::~shader() {
  if(program_){
    glDeleteProgram(program_);
  }
}
void shader::use()const {glUseProgram(program_);}

void shader::set(std::string_view name, int value){
  glUniform1i(glGetUniformLocation(program_,(static_cast<std::string>(name)).c_str()),value);
}

void shader::set(std::string_view name, float value){
  glUniform1f(glGetUniformLocation(program_,static_cast<std::string>(name).c_str()),value);
}

void shader::set(std::string_view name, float x, float y){

  glUniform2f(glGetUniformLocation(program_,static_cast<std::string>(name).c_str()),x,y);
}
