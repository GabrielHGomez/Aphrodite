#version 330
out vec4 FragColor;
in vec2 TexCoord;

uniform sampler2D image;

void main()
{
  vec4 c = texture(image, TexCoord);
  FragColor = vec4(1.0 - c.rgb, c.a);
}
