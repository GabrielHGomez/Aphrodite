#version 330 core
out vec4 FragColor;
in vec2 TexCoord;

uniform sampler2D image;

void main()
{
//  vec4 texColor = vec4(1.0,0.0,0.0,1.0);
  FragColor = texture(image,TexCoord);
}
