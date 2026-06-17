#include "../include/shader.hpp"
#include <fstream>

shader::~shader() {
  if(program_){
    glDeleteProgram(program_);
  }

void shader::use() const {glUseProgram(program_);}

void shader::set(std::string_view name, int value){
  glUniform1i(glGetUniformLocation(name),value);
}

void shader::set(std::string_view name, float value){
  glUniform1i(glGetUniformLocation(name),value);
}

void shader::set(std::string_view name, float x, float y){
  glUniform1i(glGetUniformLocation(name),x,y);
}
