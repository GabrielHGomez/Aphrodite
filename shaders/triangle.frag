#version 330 core
out vec4 FragColor;
in vec3 ourColor;

in vec2 TexCoord;

uniform sampler2D texture1;
uniform vec4 uniformColor;
uniform bool useUniform;

void main()
{
  vec4 texColor = texture(texture1, TexCoord);
  if(useUniform = 1){
  FragColor = texColor * uniformColor;
  }
  else{
    FragColor = texColor;
  }
}
