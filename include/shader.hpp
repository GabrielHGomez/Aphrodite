#pragma once
#include <string_view>

class shader{
public:
  shader(std::string_view vertSrc, std::string_view fragSrc);
  ~shader();
  unsigned int program(){return program_;}
  void use() const;
  void set(std::string_view name, int value);
  void set(std::string_view name, float value);
  void set(std::string_view name, float x, float y);

private:
  unsigned int program_ = 0;
};
