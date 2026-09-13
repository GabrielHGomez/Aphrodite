#include "../include/GLContext.hpp"

GLctx::GLctx(std::string_view title, int width, int height, std::string_view type):window_(title,width,height),shader_("./shaders/triangle.vert",type){

  glClearColor(0.1f,0.0f, 0.2f, 1.0f);
}
void GLctx::loadImage(std::string_view path){
  texture_.emplace(path);
}

void GLctx::render(){
  glClear(GL_COLOR_BUFFER_BIT);
  shader_.use();
  if(texture_){
    float winAspect = static_cast<float>(window_.width()) / static_cast<float>(window_.height());
    float imgAspect = static_cast<float>(texture_->width()) / static_cast<float>(texture_->height());

    float x = 1.0f;
    float y = 1.0f;

    if(imgAspect > winAspect){
      y = winAspect / imgAspect;
    }
    else{

      x = imgAspect / winAspect;
    }
    shader_.set("uScale",x,y); 
    texture_->bind(0);
  }
  glDisable(GL_CULL_FACE);
  glDisable(GL_DEPTH_TEST);

  canvas_.draw();
}

void GLctx::run(){
  while(!window_.close()){
    window_.pollEvents();
    render();
    
    window_.swapBuffer();
  }
}
