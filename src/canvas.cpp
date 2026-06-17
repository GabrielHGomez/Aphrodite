#include "../include/canvas.hpp"

float vertices[] = 
{
    -1.0f,  1.0f,   0.0f, 1.0f,   // top-left
    -1.0f, -1.0f,   0.0f, 0.0f,   // bottom-left
     1.0f, -1.0f,   1.0f, 0.0f,   // bottom-right
 
    -1.0f,  1.0f,   0.0f, 1.0f,   // top-left
     1.0f, -1.0f,   1.0f, 0.0f,   // bottom-right
     1.0f,  1.0f,   1.0f, 1.0f,   // top-right
};

canvas::canvas(){
  glGenVertexArrays(1, &vao_);
  glGenBuffers(1, &vbo_);
 
  glBindVertexArray(vao_);
  glBindBuffer(GL_ARRAY_BUFFER, vbo_);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
 
  const GLsizei stride = 4 * sizeof(float);
  glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, stride, (void*)0);
  glEnableVertexAttribArray(0);
  glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, stride, (void*)(2 * sizeof(float)));
  glEnableVertexAttribArray(1);
 
  glBindVertexArray(0);
  glBindBuffer(GL_ARRAY_BUFFER, 0);
 
  vertextCount_ = 6; 
}
canvas::~canvas(){
  std::cout << "deleted canvas" << std::endl;
}

void canvas::draw() const {
  glBindVertexArray(vao_);
  glDrawArrays(GL_TRIANGLES, 0 , vertextCount_);
  glBindVertexArray(0);
}
